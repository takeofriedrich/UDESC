# Trabalho 4 - Chat Multicast com RabbitMQ

Trabalho implementado com Matias Giuliano.

A implementação consiste de um servidor executando em Java, com dois clientes (Paul e John) em Java e um cliente em Python (Mary). Todos são executados na mesma máquina e compartilham dos mesmos contadores (arquivo contador1.csv), enquanto que o contador0.csv é exclusivo ao Servidor.

Para executar o chat, é necessário ter instalado o pika no Python:

    python -m pip install pika --upgrade

O trabalho é composto de 4 aplicações distribuidas:

- Servidor (em Java)
- Cliente 1 (em Java)
- Cliente 2 (em Java)
- Cliente 3 (em Python)

Para executar o trabalho, basta executar os scripts:

## Compilação

    ./compilar.sh

## Execução do Servidor em Java

    ./run_server.sh

## Execução do Cliente 1 em Java

    ./run_client1.sh

## Execução do Cliente 2 em Java

    ./run_client2.sh

## Execução do Cliente 3 em Python

    ./run_client3.sh

## Excluir compilados

    ./clean.sh



