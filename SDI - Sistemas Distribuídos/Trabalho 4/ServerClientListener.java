import com.rabbitmq.client.*;

import java.io.IOException;
import java.util.concurrent.TimeoutException;

public class ServerClientListener extends Thread {
    private String nome;
    private Servidor servidor;
    private Arquivos arquivos = new Arquivos();

    public ServerClientListener(String nome, Servidor servidor) {
        this.nome = nome;
        this.servidor = servidor;
    }

    @Override
    public void run() {
        super.run();
        try {
            ConnectionFactory factory = new ConnectionFactory();
            factory.setHost("localhost");
            Connection connection = factory.newConnection();
            Channel channel = connection.createChannel();

            channel.queueDeclare(nome + "-s", false, false, false, null);

            Consumer consumer = new DefaultConsumer(channel) {
                @Override
                public void handleDelivery(String consumerTag, Envelope envelope, AMQP.BasicProperties properties,
                        byte[] body) throws IOException {
                    // Retransmitir
                    System.out
                            .println("Mensagem de " + nome + ": " + new String(body, "UTF-8").substring(0, 10) + "...");
                    int cont = arquivos.incrementaContador(nome, 0);
                    arquivos.writeBytesInFile(nome + cont + ".serv", body, false);
                    servidor.retransmitir(nome + "#####" + new String(body, "UTF-8"));

                }
            };
            channel.basicConsume(nome + "-s", true, consumer);

        } catch (IOException e) {
            e.printStackTrace();
        } catch (TimeoutException e) {
            e.printStackTrace();
        }
    }

}
