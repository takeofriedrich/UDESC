# JAVAC=/usr/lib/jvm/java-11-openjdk-amd64/bin/javac
JAVAC=/usr/local/jdk1.8.0_131/bin/javac
JAR=amqp-client-4.0.2.jar:slf4j-api-1.7.21.jar:slf4j-simple-1.7.22.jar
CLIENT="Arquivos.java ClientStarter.java Cliente.java ClienteRunner.java ClientListener.java"
SERVER="ServerClienteRelay.java ServerClientListener.java Servidor.java ServidorReceiver.java ServidorReceiverEnder.java"

$JAVAC -cp .:$JAR $CLIENT $SERVER