import java.util.HashMap;
import java.util.Map;

public class Servidor {

    private Map<String, Object[]> clientes = new HashMap<String, Object[]>();

    public static void main(String[] args) {
        Servidor servidor = new Servidor();
        servidor.run();
    }

    public void run() {
        new Thread(new ServidorReceiver(this)).start();
        // new Thread(new ServidorReceiverEnder(this)).start();
    }

    public void adicionarCliente(String nome) {
        Thread tLis = new Thread(new ServerClientListener(nome, this));
        ServerClienteRelay tRel = new ServerClienteRelay(nome);

        tLis.start();

        Object[] par = { tLis, tRel };

        clientes.put(nome, par);
        // System.out.println("------ADD_CLIENTE---------");
        // clientes.forEach((k, v) -> {
        // System.out.println(k);
        // });
        // System.out.println("--------------------------");
    }

    public void removerCliente(String nome) {
        Object[] par = this.clientes.remove(nome);

        Thread tLis = (Thread) par[0];

        tLis.interrupt();

        // System.out.println("-----REMOVE_CLIENTE-------");
        // clientes.forEach((k, v) -> {
        // System.out.println(k);
        // });
        // System.out.println("--------------------------");
    }

    public void retransmitir(String mensagem) {
        clientes.forEach((k, v) -> {
            ((ServerClienteRelay) (v[1])).run(mensagem);
        });
    }
}
