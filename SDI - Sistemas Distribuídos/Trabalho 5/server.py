'''
 TRABALHO 5 - CHAT P2P
 - Matias Giuliano Gutierrez Benitez
 - Vinicius Takeo Friedrich Kuwaki
'''
from io import DEFAULT_BUFFER_SIZE
import sys
import socket
import threading

# TODO: exit program when client ends the connection
indexMsg = ""


def remove_repetidos(lista):  # Remove repetidos de uma lista
    l = []
    for i in lista:
        if i not in l:
            l.append(i)
    return l


# Retorna a lista de clientes que possuem uma msg X
def list_of_clients(msgRequisitada):
    file = open("index.txt", 'r')
    lista = []
    for line in file.readlines():
        linha = line.split(',')
        if linha[0] == msgRequisitada:
            lista.append(linha[1])
    lista = remove_repetidos(lista)
    return lista


def escrever_index(id):  # Atualiza o arquivo index.txt com as informações que chegam
    global indexMsg
    file = open("index.txt", 'r')
    conteudo = file.readlines()
    if conteudo.__len__ == 1:
        novo = "\n1" + "," + str(id)
        index = 1
    else:
        linha = conteudo[-1].split(",")
        novo = "\n" + str(int(linha[0])+1) + ","+str(id)
        index = str(int(linha[0])+1)
    conteudo.append(novo)
    file = open("index.txt", 'w')
    file.writelines(conteudo)
    file.close()
    indexMsg = index


def receive(conn):  # Receve informações do cliente
    global indexMsg
    while True:
        received = conn.recv(1024)
        if "#req" in received.decode():
            separamos = received.decode().split(" ")
            listaDeClientes = list_of_clients(separamos[1])
            indexMsg = ' '.join(element for element in listaDeClientes)
        elif "\f" in received.decode():
            index = received.decode().split("\f")
            idd = index[0]
            escrever_index(idd)
        if received == '':
            pass
        else:
            print(received.decode())


def send_msg(conn):  # Manda informação para o cliente
    global indexMsg
    while True:
        send_msg = indexMsg.encode()
        if send_msg.decode() == "":
            pass
        else:
            conn.sendall(send_msg)
            indexMsg = ""


def client_thread(conn):  # Função que inicializa as threads para o cliente
    thread1 = threading.Thread(target=receive, args=([conn]))
    thread2 = threading.Thread(target=send_msg, args=([conn]))
    thread1.start()
    thread2.start()
    thread1.join()
    thread2.join()


def clients():
    # Estabelece uma conexão na porta 2222 e cria duas novas thread que escutam e escrevem por cada novo cliente
    s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    s.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
    s.bind(('', 2222))
    s.listen(5)
    while True:
        (conn, addr) = s.accept()
        print('Conectado a: ' + addr[0] + ':' + str(addr[1]))
        thread = threading.Thread(target=client_thread, args=([conn]))
        thread.start()


if __name__ == '__main__':
    clients()
