# DNS: Domain Name System

De acordo com Tanenbauh, a essência do DNS é a criação de um esquema hierárquico de atribuição de nomes baseados no domínio e de um sistema de banco de dados distribuídos para implementar esse esquema de nomenclatura. Normalmente ele é utilizado para mapear nomes e destinos de mensagens de correio eletrônico em endereço IP, mas também pode ser utilizado para outros objetivos.

Em resumo o objetivo do DNS é mapear um nome para um endereço de IP. As aplicações então utiliza uma biblioteca chamada resolvedor, essa é responsável pela "tradução" do nome em endereço de IP. A aplicação pode então estabeler uma conexão TCP com o destino ou enviar pacotes UDP.

## Espaço de nomes do DNS

A internet é dividida em mais de 200 domínios de nível superior, que se dividem em mais domínios, e que podem se dividir em mais domínios e assim por diante. Todos eles podem ser represetandos por uma árvore, onde as folhas contém um único host, ou podem representar uma empresa.

### Tipos de domínios de nível superior

Se dividem em dois: genéricos e de países.

#### Genéricos

- com
- edu
- gov
- int
- mil
- net
- org

#### De países

Cada país possui sua própria entrada.

### Tipos de nomes de domínios

Podem ser absolutos ou relativos. Em ambos os casos o nome de um domínio se refere a um nó específico da árvore e a todos os nós abaixo dele.

#### Absolutos

Terminam com um ponto. Por exemplo: eng.sun.com

#### Relativos

Diferentemente dos absolutos, não terminam com ponto. Logo, devem ser interpretados em algum contexto para determinar seu verdadeiro significado. 

### Características dos nomes de domínios

- Não fazem distinção entre maiúsculas e minúsculas.
- Nomes de componentes podem ter até 63 caracteres.
- Caminhos completos não podem exceder 255.


## Registro de recursos

É uma tupla de cinco campos. Na maioria das exposições são mostrados como texto ASCII, embora sejam codificados em binário.

**Nome_do_Dominio Tempo_para_viver Classe Tipo Valor**

### Nome do domínio

Informa o domínio ao qual o registro se aplica. Como existem muitos registros para cada domínio, normalmente esse é o campo é a chave de busca primária.

### Tempo para viver

Fornece uma indicação da estabilidade do registro. As mais estáveis são indicadas com um valor alto, por exemplo 86400 (número de segundo que um dia possui). As mais voltáreis recebem valores baixos, como 60.

### Classe

O mais comum para esse campo é o Internet, logo utiliza-se o IN.

### Tipo

Informa qual o tipo de registro. Os mais importantes estão listados abaixo: (IPV4)

- SOA: Inicio de autoridade
- A: Endereço de IP de um host
- MX: Troca de mensagens de correio
- NS: Serviço de nomes
- CNAME: Nome canônico
- PTR: Ponteiro
- HINFO: Descrição de HOST
- TXT: Texto

### Valor

Esse campo contém um número ou nome de dominio ou uma string ASCII, onde sua semântica vai depender do tipo de registro.

## Servidores de nomes

444