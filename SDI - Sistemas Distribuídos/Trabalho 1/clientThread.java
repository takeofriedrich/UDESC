import java.io.DataInputStream;
import java.io.IOException;
import java.io.PrintStream;
import java.net.DatagramPacket;
import java.net.InetAddress;
import java.net.MulticastSocket;
import java.net.Socket;

class clientThread extends Thread {

    private DataInputStream is = null;
    private PrintStream os = null;
    private Socket clientSocket = null;
    private final clientThread[] threads;
    private int maxClientsCount;
    private boolean stop = false;
    private MulticastSocket socket = null;
    private Arquivos arquivos = new Arquivos();

    public clientThread(Socket clientSocket, clientThread[] threads) {
        this.clientSocket = clientSocket;
        this.threads = threads;
        maxClientsCount = threads.length;
    }

    public synchronized boolean isStop() {
        return this.stop;
    }

    public MulticastSocket getMulticastSocket() {
        return this.socket;
    }

    public void run() {
        int maxClientsCount = this.maxClientsCount;
        clientThread[] threads = this.threads;

        try {

            is = new DataInputStream(clientSocket.getInputStream());
            os = new PrintStream(clientSocket.getOutputStream());

            String name = is.readLine().trim();

            String[] correct = name.split("\f");

            name = correct.length > 0 ? correct[0] : "Anônimo";

            os.println(name + " seja bem-vindo.\nPara sair digite CTRL+C");

            // Entra no multicast

            try {

                socket = new MulticastSocket(8888);
                InetAddress address = InetAddress.getByName("224.0.0.2");
                socket.joinGroup(address);

                System.out.println("Entrou no multicast!");

            } catch (IOException ioe) {
                System.out.println(ioe);
            }

            while (true) {

                String line = is.readLine();

                if (line.startsWith("/quit")) {
                    this.stop = true;
                    os.println("Parei de ler");
                    break;
                }

                os.println(line);

                String arquivo = "";
                int data = is.read();

                while (true) {
                    arquivo += (char) data;
                    data = is.read();
                    if ((char) data == '\f') {
                        break;
                    }
                }

                InetAddress address = InetAddress.getByName("224.0.0.2");
                DatagramPacket outPacket = new DatagramPacket(arquivo.getBytes(), arquivo.length(), address, 8888);
                socket.send(outPacket);

                // Deixei o incrementaContador() devido a que é a função que faz sentido (ele tá
                // funcionando)

                String caminho = name + "-" + arquivos.incrementaContador(name, 0) + ".serv";

                System.out.println("Salvando no nome: " + caminho);

                arquivos.writeBytesInFile(caminho, arquivo.getBytes(), false);

            }
            for (int i = 0; i < maxClientsCount; i++) {
                if (threads[i] != null && threads[i] != this) {
                    threads[i].os.println("*** The user " + name + " is leaving the chat room !!! ***");
                }
            }
            os.println("*** Bye " + name + " ***");

            /*
             * Clean up. Set the current thread variable to null so that a new client could
             * be accepted by the server.
             */
            for (int i = 0; i < maxClientsCount; i++) {
                if (threads[i] == this) {
                    threads[i] = null;
                }
            }

            /*
             * Close the output stream, close the input stream, close the socket.
             */
            is.close();
            os.close();
            clientSocket.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}