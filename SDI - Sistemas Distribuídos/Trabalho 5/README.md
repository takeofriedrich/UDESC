# Trabalho 5 - Chat P2P

Trabalho implementado com Matias Giuliano.

A implementação consiste de um servidor executando em Python, com três clientes (Matias, Joao e Takeo) em python. Todos são executados na mesma máquina, o servidor funciona como um index ou seja os Clientes perguntam para o servidor em que máquina se encontra certa mensagem e ele envia as devidas posições para esse client. Os clientes se conectam por P2P para a transferência das informações.


O trabalho é composto de 4 aplicações distribuidas:

- Servidor 
- Cliente 1 
- Cliente 2 
- Cliente 3 

Para executar o trabalho, basta executar na mesma máquina::

## Execução do Servidor

    python server.py

## Execução do Cliente 1 em Java

    python3 client.py 1 matias

## Execução do Cliente 2 em Java

    python3 client.py 2 joao

## Execução do Cliente 3 em Python

    python3 client.py 3 takeo
    

## Durante a execução
    O usuário possui duas opções:
        - Digitar uma frase qualquer que será mandada para o servidor e salva em um arquivo com o nome de usuário do cliente.
        - Digitar "#req [número da mensagem]" para requisitar para o servidor a posição da mensagem numero [número da mensagem]





