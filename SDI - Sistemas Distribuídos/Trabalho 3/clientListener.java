import java.io.IOException;
import java.net.DatagramPacket;
import java.net.InetAddress;
import java.net.MulticastSocket;

public class clientListener extends Thread {

    private int cliente;
    private String username;
    private Arquivos arquivos = new Arquivos();

    public clientListener(int cliente, String username) {
        this.cliente = cliente;
        this.username = username;
    }

    @Override
    public void run() {
        super.run();
        System.out.println("Pressione ENTER para começar o envio de arquivos");
        DatagramPacket inPacket;

        byte[] inBuf = new byte[256];
        try {
            MulticastSocket socket = new MulticastSocket(8888);
            InetAddress address = InetAddress.getByName("224.0.0.2");
            socket.joinGroup(address);
            while (true) {
                inPacket = new DatagramPacket(inBuf, inBuf.length);
                socket.receive(inPacket);
                String msg = new String(inBuf, 0, inPacket.getLength());
                System.out.println("From " + inPacket.getAddress() + " Msg : " + msg);
                // salvar o arquivo na maquina com formato
                // 'nomeCliente'-01.client'numeroDeUsuário'
                arquivos.writeBytesInFile(
                        username + "-" + arquivos.incrementaContador(username, cliente) + ".client" + cliente,
                        msg.getBytes(), false);

            }
            // System.out.println("Parei de escutar");
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

}
