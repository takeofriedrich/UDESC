import java.io.IOException;
import java.util.concurrent.TimeoutException;

public class Cliente {

    private String nome;
    private int cliente;
    private Thread clientListener;

    public Cliente(String nome, int cliente) {
        this.nome = nome;
        this.cliente = cliente;
        run();
    }

    public void run() {
        ClientStarter starter = new ClientStarter(nome);
        try {
            starter.start();
            clientListener = new Thread(new ClientListener(nome, cliente));
            clientListener.start();
            starter.send();
            clientListener.interrupt();
            // starter.end();

        } catch (IOException | TimeoutException e) {
            e.printStackTrace();
        }
    }

}
