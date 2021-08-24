import java.io.DataInputStream;
import java.io.PrintStream;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.net.Socket;
import java.net.UnknownHostException;
import java.rmi.*;
import java.rmi.server.*;
import java.rmi.registry.*;

public class MultiThreadChatClient implements Runnable {

    // The client socket
    private static Socket clientSocket = null;
    // The output stream
    private static PrintStream os = null;
    // The input stream
    private static DataInputStream is = null;

    private static BufferedReader inputLine = null;
    private static boolean closed = false;

    private static int cliente;

    private static String username;

    public static void main(String[] args) {

        int portNumber = 2222;

        String host = "10.20.221.230";

        cliente = Integer.parseInt(args[0]);

        try {
            clientSocket = new Socket(host, portNumber);
            inputLine = new BufferedReader(new InputStreamReader(System.in));
            os = new PrintStream(clientSocket.getOutputStream());
            is = new DataInputStream(clientSocket.getInputStream());
            username = args[1];
        } catch (UnknownHostException e) {
            System.err.println("Don't know about host " + host);
        } catch (IOException e) {
            System.err.println("Couldn't get I/O for the connection to the host " + host);
        }

        /*
         * If everything has been initialized then we want to write some data to the
         * socket we have opened a connection to on the port portNumber.
         */
        if (clientSocket != null && os != null && is != null) {
            try {

                new Thread(new MultiThreadChatClient()).start();
                while (!closed) {
                    os.println(inputLine.readLine().trim());
                }

                os.close();
                is.close();
                clientSocket.close();
            } catch (IOException e) {
                System.err.println("IOException:  " + e);
            }
        }
    }

    /*
     * Create a thread to read from the server. (non-Javadoc)
     * 
     * @see java.lang.Runnable#run()
     */
    public void run() {

        String responseLine;
        Arquivos arquivos = new Arquivos();

        try {

            new Thread(new clientListener(cliente, username)).start();

            RemoteClient client = new RemoteClient(username);
            Remotos stub = (Remotos) UnicastRemoteObject.exportObject(client, 0);
            // Registra a stub no RMI Registry para que ela seja obtida pelo servidor
            Registry registry = LocateRegistry.createRegistry(6600);
            registry.bind("Eai", stub);

            // while ((responseLine = is.readLine()) != null) {

            // System.out.println("Digite o caminho do arquivo a ser enviado:\n-Extensao
            // .txt apenas\n");
            // System.out.println(responseLine);
            // if (responseLine.indexOf("*** Bye") != -1) {
            // break;
            // }
            // if (!responseLine.endsWith("Para sair digite CTRL+C") &&
            // responseLine.contains(".txt")) {
            // arquivos.writeBytesInFile(responseLine, new String("\f").getBytes(), true);
            // byte[] bytes = arquivos.readBytesFromFile(responseLine);
            // // System.out.println("Vou enviar:");
            // // System.out.println(new String(bytes) + "\n");
            // os.write(bytes);
            // }
            // }
            closed = true;
        } catch (IOException e) {
            System.err.println("IOException:  " + e);
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

}