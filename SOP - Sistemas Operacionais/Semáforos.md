# Mecanismos de Coordenação

O capitulo anterior havia apresentado algumas soluções para a condição de disputa, mas a falta de justiça inviabiliza as suas utilizações em aplicações ao usuário. As soluções apresentadas a seguir procuram resolver esse problema e são amplamente utilizadas em aplicações concorrentes.

## Semáforos

Introduzem uma váriavel s que representa uma seção crítica, onde seu conteúdo interno não é acessível ao programador. O semáforo é composto de:

- s.counter: Contador;
- s.queue: Uma fila de tarefas, inicialmente vazia;

Operações atômicas que a tarefas podem invocar sobre o semáforo:

- down(s): solicita o acesso a seção crítica. Caso ela esteja livre, a chamada retorna imediatamente e a tarefa continua sua execução. Caso não a tarefa é suspensa e adicionada a fila. O computador é decrementado.
- up(s): libera a seção crítica de s. O contador é incrementado. Caso a fila não esteja vazia, a primeira tarefa é acordada e retorna sua execução.

```
down(t,s){
    s.counter--
    if(s.counter<0){
        s.queue.add(t)
        suspend(t)
    }
}
```
```
up(t,s){
    s.counter++
    if(s.counter<=0){
        // retira a primeira tarefa da fila e a devolve a fila de tarefas prontas
        s.queue.first.awake()
    }
}
```
        
As operações descritas acimas são implementadas no núcleo do sistema operacional e devem ser **atômicas** para evitar condições de disputa.

Utilização do semáforo no exemplo da aula anterior:

```C
void depositar(Semaforo s, int *saldo, int valor){
    s.down()
    (*saldo) += valor;
    s.up()
}
```

Os semáforos resolvem os problemas que foram descritos na aula anterior:

-   **Eficiencia**: enquanto estão aguardado o semáforo elas são suspensas e não ficam consumindo processador. Quando o semáforo acorda uma é somente a primeira da fila e não todas, gerando maior ecônomia ainda.
-   **Justiça**: A fila de tarefa obedece a regra de uma FIFO, em que a primeira a entrar é a primeira a sair, respeitando a ordem das solicitações.
-   **Independência**: somente as tarefas que solicitarem a utilização (via operação down) são consideradas na decisão.

Semáforos estão disponíveis na maioria dos sistemas operacionais. O padrão POSIX dispõe várias chamadas para a sua criação e manipulação. Sendo as mais utilizadas:

- Inicia um semáforo apontado pela referência **semaforo** com um valor inicial **valor**

```C
#include <semaphore.h>

int init_sem(sem_t *semaforo, int pshared, unsigned int valor);
```

- Operações up() e down() em uma referência **semaforo**:

```C
#include <semaphore.h>

// up
int sem_post(sem_t *semaforo);

// down
int sem_wait(sem_t *semaforo);
```

- Operação try/down(s), ela retorna erro se o semáforo estiver ocupado

```C
#include <semaphore.h>

int sem_trywait(sem_t *semaforo);
```

O autor cita várias aplicações do semáforo, que vão até além do uso no controle de regiões críticas. O valor do contador do semáforo pode ser utilizado para contar a quantidade de recursos disponível. Por exemplo, uma aplicação para um estacionamento. O valor inicial representa o número de vagas totais. Quando um carro quiser entrar no semáforo ele solicita a sua entrada. Caso não hajam vagas o carro ficará aguardando o semáforo autorizar sua entrada (quando houver vagas disponíveis). Veja o exemplo abaixo:

```C
semaforo vagas = 10;

void obtem_vaga(){
    down(vagas);
}

void libera_vaga(){
    up(vagas);
}
```

## Mutexes

São semáforos que assumem apenas dois valores em seus contadores: *livre* ou *ocupado*.

Algumas funções disponíveis na biblioteca PThread:

- inicia uma variável do tipo mutex, usando uma struct de atributos:

```C
#include <pthread.h>

int pthread_mutex_init(pthread_mutex_t *restrict mutex, const pthread_mutexattr_t *restrict attr);
```

- destrói uma variável do tipo mutex:

```C
#include <pthread.h>

int pthread_mutex_destroy (pthread_mutex_t *mutex);
```

- solicita o acesso a seção crítica protegida pelo mutex, se ela estiver ocupada, bloqueia a tarefa:

```C
#include <pthread.h>

int pthread_mutex_lock (pthread_mutex_t *mutex);
```

- solicita o acesso a seção crítica protegida pelo mutex, se ela estiver ocupada, retorna com o status do erro:

```C
#include <pthread.h>

int pthread_mutex_trylock (pthread_mutex_t *mutex);
```

- libera o acesso a sessão crítica protegida pelo mutex:

```C
#include <pthread.h>

int pthread_mutex_unlock (pthread_mutex_t *mutex)
```

## Variáveis de condição

É associada a uma condição lógica. Para evitar a espera ocupada, uma tarefa é colocada para dormir até que outra tarefa a avise que a condição se tornou verdadeira. A condição desejada é associada a uma variável de condição *c*. Uma tarefa aguarda essa condição através do operador **wait(c)**, estando suspensa enquanto o aguarda. Ela só é acorda quando outra tarefa chamar o operador **signal(c)** ou **notify(c)**. Uma variável de condição também possui uma fila de tarefas **c.queue** que aguardam essa condição. Podem ser usadas também em conjunto com um mutex para garantir a exclusão mútua.

A seguir será a apresentado um "pseudocódigo" das operações mencionadas anteriormente. Assim como os operadores sobre semáforos, estas precisam ser executadas de forma atômica. 

* t representa a tarefa que invocou a operação;
* c é a variável de condição;
* m é o mutex associado à condição;

### Operação wait:

    wait(t,c,m):
        c.queue.add(t) // Adiciona a tarefa ao final da fila de c
        m.libera() // Libera o mutex
        t.suspende() // Suspende a tarefa
        m.lock() // Ao acordar, requer o mutex

### Operação signal:

    signal(c):
        u = c.queue.first() // u recebe a primeira tarefa da fila de c
        acorda(u) // essa tarefa é então acordada


### Operação broadcast:

    broadcast(c):
        while(c.queue.size() != 0): // acorda todas as tarefas da fila
            u = c.queue.first()
            acorda(u)

A variável de condição não contém a condição própriamente dita, ela apenas permite a sincronização em cima dessa condição. Por exemplo, se em um programa a condição a ser testada é um buffer estar vazio, a variável de condição apenas permite esperar que a condição se torne verdadeira e sinalizar quando isso acontecer. Para testar se o buffer está vazio ainda é necessário fazer via **if**.

As variáveis de condição estão disponíveis no POSIX, através de operadores:

- pthread_cond_wait;
- pthread_cond_signal;
- pthread_cond_broadcast;

Veja um exemplo apresentado no livro em que uma tarefa **produce_data** obtém dados de uma fonte qualquer (rede, disco, etc) e os deposita em um buffer compartilhado. Enquanto que a tarefa **consume_data** aguarda novos dados provindos desse buffer para consumi-los:

    condition c;
    mutex m;

    task produce_data(){
        while(1){

            // obtem os dados de uma fonte
            retrieve_data(data);

            // insere os dados no buffer
            lock(m); // acesso exclusivo ao buffer, fechando o acesso de outras tarefas

            put_data(buffer,data); // poe dados no buffer

            signal(c); // sinaliza que o buffer tem dados

            unlock(m); // libera o buffer

        }
    }

    task consume_data(){
        while(1){

            // agurda a presença de dados no buffer
            lock(m); // acesso exclusivo ao buffer
            while(buffer.size == 0){ // aguarda o buffer estar vazio
                wait(c,m); // espera a condição
            }

            // retira os dados do buffer o libera
            get_data(buffer,data); 
            unlock(m);

            // trata os dados recebidos
            process_data(data);

        }
    }

## Monitores

Um monitor é uma estrutura de sincronização que requisita e libera a seção crítica associada a um recurso de forma "automática", retirando esse trabalho do programador. Consiste nos seguintes elementos:

- um recurso compartilhado (conjunto de variáveis);
- um conjunto de procedimentos e funções que permitem o acesso a esses variáveis;
- um mutex ou semáforo para o controle da exclusão mútua. Cada procedimento de acesso ao recurso deve obter o mutex antes de iniciar e liberá-lo ao concluir;
- um invariante sobre o estado interno do recurso;

Veja o pseudocódigo de um monitor aplicado ao exemplo da conta bancária:

```C
monitor conta{
    
    string numero;
    float saldo = 0.0;
    float limite;

    void depositar(float valor){
        if(valor>=0){
            conta->saldo += valor;
        }else{
            error("Erro: valor negativo\n");
        }
    }

    void retirar(float saldo){
        if(valor>=0){
            conta->saldo -= valor;
        }else{
            error("Erro: valor negativo\n");
        }
    }
}
```

A definição formal de monitor prevê a existência de um invariante, isto é, uma condição sobre as variáveis internas do monitor que deve ser sempre verdadeira. No exemplo da conta bancária, o invariante poderia ser: "*O saldo atual deve ser a soma de todos depósitos efetuados menos todas as retiradas efetuadas*". Mas a maioria das implementações não suporta a definição de invariantes.

De certa forma, o monitor é um objeto que encapsula o recurso compartilhado, com procedimentos(métodos) para acessá-lo. No monitor a execução dos procedimentos é feita com exclusão mútua entre eles. As operações de obtenção e liberação do mutex são colocadas automaticamente pelo compilador da linguagem em questão. Várias linguagens implementam monitores: Ada, C#, Eiffel, Java, etc. Em Java, a cláusula *synchronized* faz com que um semáforo seja associado aos métodos de um objeto. Veja o exemplo da conta bancária em Java:

```Java
class Conta{
    private float saldo = 0;

    public synchronized void depositar(float valor){
        if(valor>=0){
            saldo += valor;
        }else{
            System.err.println("Valor negativo");
        }
    }

    public synchronized void retirar(float valor){
        if(valor>=0){
            saldo -= valor;
        }else{
            System.err.println("Valor negativo");
        }
    }
}
```
    



