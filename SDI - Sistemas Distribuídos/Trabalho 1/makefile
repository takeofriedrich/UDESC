# GNU Makefile

JC = /usr/local/jdk1.8.0_131/bin/javac
JFLAGS = #-Xlint
TARGET = MultiThreadChatServer.class MultiThreadChatClient.class clientThread.class clientListener.class Arquivos.class

all: $(TARGET)

clientThread.class: clientThread.java
	$(JC) $(JFLAGS) clientThread.java 

clientListener.class: clientListener.java
	$(JC) $(JFLAGS) clientListener.java 

MultiThreadChatServer.class: MultiThreadChatServer.java
	$(JC) $(JFLAGS) MultiThreadChatServer.java 

MultiThreadChatClient.class: MultiThreadChatClient.java
	$(JC) $(JFLAGS) MultiThreadChatClient.java 

Arquivos.class: Arquivos.java
	$(JC) $(JFLAGS) Arquivos.java 

runC1:
	java MultiThreadChatClient 1 paul

runC2:
	java MultiThreadChatClient 2 john

runC3:
	java MultiThreadChatClient 3 Mary

runS:
	java MultiThreadChatServer

clean:
	rm -f *~ $(TARGET)