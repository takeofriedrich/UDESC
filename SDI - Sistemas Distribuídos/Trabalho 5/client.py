
'''
 TRABALHO 5 - CHAT P2P
 - Matias Giuliano Gutierrez Benitez
 - Vinicius Takeo Friedrich Kuwaki
'''
import sys
import socket
import threading

# TODO:end connection with 'exit'
username = ""
index_msg = ""
port = 2222
msg_final = ""
ports = {
    1: 2223,
    2: 2224,
    3: 2225
}
atualizaIndex = 0
atualizaIndexMsg = ""


def catching_msg(num):  # Pega a msg do .txt e a retorna
    global username
    caminho = username + ".txt"
    file = open(caminho, 'r')
    c_msg = ""
    for line in file.readlines():
        linha = line.split('\f')
        print(linha)
        if linha[0] == num:
            c_msg = linha[1]
            break
    return c_msg


def escrever_msg(indexMsg, nome, msg):  # Escreve msg no .txt
    caminho = nome + ".txt"
    file = open(caminho, 'a')
    file.write(indexMsg + "\f" + msg + "\n")
    file.close()


def connect_server(s, nome):  # Thread que escuta mensagens do Servidor

    global index_msg, msg_final
    while True:
        r_msg = s[0].recv(1024)
        if not r_msg:
            break
        if r_msg == '':
            pass
        elif msg_final != "":
            index_msg = r_msg.decode()
            if "#req" in msg_final:
                aux = msg_final.split(' ')
                print("Abrindo nova conexão com cliente {} pedindo mensagem {}".format(
                    index_msg, aux[1]))
                connect_to_peer(index_msg, aux[1])
            else:
                escrever_msg(index_msg, nome, msg_final)
                msg_final = ""


def send_msg_to_serv(s, id):  # Thread que manda mensagens ao servidor
    global msg_final, atualizaIndex, atualizaIndexMsg
    while True:
        msg = input(
            "\nPara requisitar uma mensagem digite: #req [num da mensagem]\n")
        s_msg = str(id) + "\f" + msg
        s_msg = s_msg.encode('utf-8')
        if atualizaIndex == 1:
            atualizaIndexMsg = str(id) + "\f" + atualizaIndexMsg
            atualizaIndexMsg = atualizaIndexMsg.encode('utf-8')
            s[0].sendall(atualizaIndexMsg)
            atualizaIndexMsg = ""
            atualizaIndex = 0
        if s_msg == '':
            pass
        if msg == 'exit':
            print("exit")
            break
        else:
            msg_final = msg
            if msg.startswith("#req"):
                s_msg = str(id) + "\f" + msg
                s_msg = s_msg.encode('utf-8')
            s[0].sendall(s_msg)


def listen_client(conn):  # Escutando até que o cliente mande a mensagem
    while True:
        r_msg = conn.recv(1024)
        if not r_msg:
            break
        if r_msg == '':
            pass
        else:
            print("Novo Cliente pedindo a mensagem número: " + r_msg.decode())
            client_msg = catching_msg(r_msg.decode())
            send_to_client(conn, client_msg)


def send_to_client(conn, c_msg):  # Funcão que envia a devida msg ao client
    c_msg = c_msg.encode('utf-8')
    print("Mandando a msg:  {}".format(c_msg.decode()))
    if c_msg.decode() == "":
        pass
    else:
        conn.sendall(c_msg)


def start_peer(id):
    # Inicializa uma nova conexão como se fosse um servidor caso algum cliente acesse sua porta
    global ports
    s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    s.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
    s.bind(('', ports[int(id)]))
    s.listen(5)
    while True:
        # Fica escutando até que um cliente novo seja conectado
        (conn, addr) = s.accept()
        print('Novo cliente conectado: ' + addr[0] + ':' + str(addr[1]))
        # Caso ele ache um novo cliente ele cria uma thread para escutar esse cliente
        thread = threading.Thread(target=listen_client, args=([conn]))
        thread.start()


def connect_to_peer(index, numberOfDocument):  # Conecta um cliente com outro
    global ports, atualizaIndex, atualizaIndexMsg
    s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    s.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
    s.connect(("127.0.0.1", ports[int(index)]))
    numberOfDocument = numberOfDocument.encode('utf-8')
    s.sendall(numberOfDocument)
    # Esperando que o cliente mande a mensagem
    while True:
        r_msg = s.recv(1024)
        print(r_msg)
        if not r_msg:
            break
        if r_msg == '':
            pass
        else:
            # salvo no meu arquivo
            escrever_msg(numberOfDocument.decode(), username, r_msg.decode())
            break
    atualizaIndexMsg = r_msg.decode()
    atualizaIndex = 1


if __name__ == '__main__':
    if len(sys.argv) != 3:
        print("usage: %s [id][username] " % sys.argv[0])
        sys.exit(0)

    # Abrindo a conexão com o servidor
    id = sys.argv[1]
    username = sys.argv[2]
    s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    s.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
    s.connect(("127.0.0.1", port))

    # Inicializando as threads que escutam e escrevem nos servidor
    thread1 = threading.Thread(target=connect_server, args=([s], username))
    thread2 = threading.Thread(target=send_msg_to_serv, args=([s], id))
    thread1.start()
    thread2.start()

    # Inicializando a funcão que escuta novos peers
    start_peer(id)
    thread1.join()
    thread2.join()
