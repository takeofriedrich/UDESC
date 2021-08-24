import pika
import sys
import os


def writeCSV(csv: dict, cliente=1):
    file = ''
    for key in csv.keys():
        file += '{},{}\n'.format(key, csv[key])
    open('contador{}.csv'.format(cliente), 'w').write(file)


def parseCSV(cliente=1):
    csv = {}
    for linha in open('contador{}.csv'.format(cliente), 'r').readlines():
        infos = linha.replace('\n', '').split(',')
        csv[infos[0]] = int(infos[1])
    return csv


def incrementaContador(nome, cliente=1):
    mapa = parseCSV(cliente)
    if nome in mapa:
        mapa[nome] = mapa[nome]+1
    else:
        mapa[nome] = 0
    writeCSV(mapa, cliente)
    return mapa[nome]


def ler():
    f = open('teste.txt', 'r')
    s = ''
    for linha in f.readlines():
        s += linha
    return s


def callback(ch, method, properties, body):
    msg = str(body, encoding='UTF-8').split('#####')
    nome = msg[0]
    corpo = msg[1]
    f = open('{}{}.client{}'.format(nome, incrementaContador(nome), 1), 'w')
    print('Mensagem de {}: {}...'.format(nome, corpo[0:10]))
    f.write(corpo)


def main():
    nome = sys.argv[1]

    connection = pika.BlockingConnection(
        pika.ConnectionParameters('localhost'))

    # Notificar o servidor de que precisa escutar esse novo cliente
    start = connection.channel()

    start.queue_declare(queue='SERV')

    start.basic_publish(exchange='',
                        routing_key='SERV',
                        body=nome)

    # Mandando o arquivo para nome-s
    sender = connection.channel()

    sender.queue_declare(queue='{}-s'.format(nome))

    sender.basic_publish(exchange='',
                         routing_key='{}-s'.format(nome),
                         body=ler())

    # Receber as mensagens e salvar no arquivo

    receiver = connection.channel()
    receiver.queue_declare(queue='{}-c'.format(nome))

    receiver.basic_consume(queue='{}-c'.format(nome),
                           auto_ack=True,
                           on_message_callback=callback)

    receiver.start_consuming()

    connection.close()


if __name__ == '__main__':
    try:
        main()
    except KeyboardInterrupt:
        print('Interrupted')
        try:
            sys.exit(0)
        except SystemExit:
            os._exit(0)
