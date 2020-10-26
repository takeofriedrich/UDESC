# Aula 7: Comunicação interprocessos: conceitos de concorrência, soluções com espera ocupada

## Problema da Concorrência

Quando duas ou mais tarefas acessam simultâneamente um recurso compartilhado, causando inconcistência nos dados.

    void depositar(long *saldo, long valor){
        (*saldo) += valor;
    }

- São erros dinâmicos, isto é, não aparecem no fonte, apenas na execução.
- Ocorrem apenas as vezes, quando acontecem entrelaçamentos.
- Difícil depuração, pois os dados precisam ser acessados simultâmenamente.

## Condição de Bernstein

Dadas duas tarefas <img src="https://render.githubusercontent.com/render/math?math=t_{1}"> e <img src="https://render.githubusercontent.com/render/math?math=t_{2}">, sendo <img src="https://render.githubusercontent.com/render/math?math=R(t_{1})"> o conjunto das variáveis lidas por <img src="https://render.githubusercontent.com/render/math?math=R(t_{1})"> e <img src="https://render.githubusercontent.com/render/math?math=W(t_{1})"> o conjunto de variáveis escritas, as condições de Bernstein são tais que:

<img src="https://render.githubusercontent.com/render/math?math=t_{1}%20||%20t_{2}%20=%20\left\{\begin{matrix}%20R(t_{1})%20\cap%20W(t_{1})%20=%20\phi%20\\%20R(t_{2})%20\cap%20W(t_{1})%20=%20\phi%20\\%20W(t_{1})%20\cap%20W(t_{2})%20=%20\phi%20\end{matrix}\right.">

As tarefas podem ser executadas em paralelo <img src="https://render.githubusercontent.com/render/math?math=t_{1}%20||%20t_{2}"> se e somente se as condições forem atendidas.

## Seções Críticas

São trechos de código que acessam dados compartilhados em cada tarefa.

No caso do exemplo descrito anteriormente:

    (*saldo) += valor;

Para assegurar a correção de uma implementação, deve-se impedir o entrelaçamento de seções críticas.

Dado um conjunto de regiões críticas relacionadas, apenas uma tarefa pode estar em sua região crítica a cada instânte, excluíndo o acesso das demais às suas respectivas regiões críticas.

## Exclusão Mútua

Objetivo é impedir o entrelaçamento de seções críticas. O programador deve definir os limites (inicio e fim) de cada seção critica.

    void depositar(long conta, long *saldo, long valor){

        enter(conta);
        (*saldo) += valor;
        leave(conta);

    }

No código acima, *enter(conta)* representa uma ação a ser realizada quando a tarefa vai entrar na seção critica, enquanto que a *leave(conta)* representa a ação ao sair. Essas funções podem ser chamadas de guardas.

As soluções que serão propostas devem atender os critérios:

- Exclusão mútua: somente uma tarefa pode estar dentro da seção crítica em cada instânte;
- Espera limitada: a tarefa que aguarda acesso a região crítica, deve possui acesso por um periodo de tempo finito, e também não pode ficar aguardando eternamente;
- Independência de outras tarefas: As tarefas que não tem interesse em entrar na região crítica, não podem tomar decisões o uso da região crítica;
- Independência de fatores físicos: os fatores físicos, tais com velocidade de execução, número de processadores e outros, não deve influênciar na solução. Ela deve ser puramente lógica.

## Inibição de iterrupções

Possui o objetivo de impedir trocas de contexto dentro da seção crítica. Quando uma tarefa entra na seção crítica ela desativa as interrupções que possam provocar uma troca [de contexto] e as reativa ao sair. Como se a tarefa se "fechasse" dentro da região crítica. Essa solução é raramente utilizada, devido aos problemas listados no livro:

- Caso a tarefa entre em loop infinito dentro dela, pode prejudicar o sistema inteiro, pois ninguém mais conseguirá acessá-la. Uma tarefa mal intencionada pode causar isso.
- Enquanto as interrupções estão ativadas o núcleo deixa de atender outras atividades. No livro o autor cita uma placa de rede que pode perder novos pacotes de os seus buffers estiverem cheios e não forem tratados a tempo pelo núcleo.
- Quando a tarefa está na sessão crítica, ela não pode realizar operações de entrada e saída.
- A solução só funciona em sistemas com um núcleo de processador.

Devido a isso, essa solução nunca é utilizada por aplicações comuns, apenas por seções críticas existentes dentro do núcleo do sistema operacional.

## A solução trivial

A solução consiste em utilizar uma variável $busy$ para indicar se a seção crítica está ocupada ou não.

    int busy = 0; // seção está inicialmente livre

    void enter(){
        while (busy){}; // espera enquanto a seção estiver ocupada
        busy = 1; // marca a seção como ocupada
    }

    void leave(){
        busy = 0; // libera a seção, marcando-a como livre
    }

Essa solução não funciona, pois a verificação do while e atribuição ocorrem em momentos distintos, gerando outra seção crítica. O teste contínuo também demanda muito processamento computacional, se houverem muitas tarefas tentando entrar na seção, o processamento gasto será muito maior. Essa verificação é chamada de teste **contínuo** e deve ser evitada.

## Alternância de uso

Outra solução para a excusão mútua é a definição de uma variável *turno*. Ela deve ser ajustada sempre que uma tarefa sai da seção crítica.

    int num_tasks;
    int turn = 0;

    void enter(int task){
        while(turn != task) {};
    }

    void leave(int task){
        turn (turn + 1) % num_tasks;
    }

Essa solução permite um rodízio no uso da seção critica, em uma sequência circular:

t0 -> t1 -> ... -> tn -> t0.

Mas ela ainda não atende os demais critérios: caso uma tarefa ti não deseje usar a seção crítica, ela irá impedir as demais de usar, pois a variável turno nunca vai evoluir.

## Algoritmos de Peterson

Foi desenvolvido para garantir a exclusão mútua entre **duas tarefas**, garantindo também o critério da espera limitada:

    int turn = 0;
    int wants[2] = {0,0};

    void enter(int task){ // task pode valer 0 ou 1

        int other = 1 - task; // indica a outra tarefa
        wants[task] = 1; // task quer acessar a seção critica
        turn = task;
        while ((turn == task) && wants[other]) {} // espera ocupada

    }

    void leave(int task){
        wants[task] = 0; // task libera a seção critica
    }

## Operações atômicas

Para resolver o problema da troca de contexto, projetistas desenvolveram instruções de código de máquina que permitem testar e atribuir um valor a uma variável ao mesmo tempo (sem a troca de contexto pelo hardware). Tais instruções impedem a ocorrência de condições de disputa sobre a variável *busy*.

Um exemplo é a instrução TSL (Test-and-SetLock), descrita pelo pseudo-código abaixo:

<img src="https://render.githubusercontent.com/render/math?math=TSL(x) =%20\left\{\begin{matrix}x%20\rightarrow%20old\\1%20\rightarrow%20x\\return(old)\end{matrix}\right.">

A implementação de enter() e leave() assume a seguinte forma:

    int lock = 0; // variavel de trava

    void enter(int *lock){ // passa o endereço da trava

        while( TSL(*lock) ) {}; // espera ocupada sobre a trava

    }

    void leave(int *lock){

        (*lock) = 0; // libera a seção crítica

    }

Os mecanismos de exclusão mútua usando instruções atômicas são amplamente usados no interior do sistema operacional (chamados muitas vezes de *spinlocks*): acesso a sessões críticas dentro do núcleo, buffers de arquivos, etc. Mas são inadequados para a construção de aplicações de usuário.

## Problemas

O acesso de diversas tarefas aos mesmos recursos pode provocar problemas de cosistência, chamados de **condições de disputa**. Um forma de resolver isso é realizar uma tarefa por vez. Apesas dessas soluções garantirem a exclusão mútua (menos a solução trivial), seu uso em aplicações de usuário é reduzido devido a:

- **Ineficiência**: consumo alto de processamento ao ficar testando continuamente se a sessão crítica está livre. O correto seria suspender essas tarefas até que a sessão critica ficasse disponível.
- **Injustiça**: na maioria dos casos, excluindo a solução de alternância, não existem garantias na ordem em que as tarefas irão acessar a seção crítica. Uma tarefa pode entrar e sair várias vezes, antes de uma em específico conseguir.
- **Dependência**: na solução por alternância, algumas tarefas que desejam acessar a seção crítica podem acabar sendo impedidas por tarefas que não tem interesse em acessá-la.

Pelas razões apontadas acima, essas soluções são pouco usadas na construção de aplicações. Sua maior aplicação encontra-se na concorrência dentro do núcleo do sistema operacional e na construção de sistemas de computação dedicados, como controladores embarcados mais simples.




