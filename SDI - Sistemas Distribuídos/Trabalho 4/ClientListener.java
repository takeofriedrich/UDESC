import com.rabbitmq.client.*;

import java.io.IOException;
import java.util.concurrent.TimeoutException;

public class ClientListener extends Thread {

    private String nome;
    private Arquivos arquivos = new Arquivos();
    private int cliente;

    public ClientListener(String nome, int cliente) {
        this.nome = nome;
        this.cliente = cliente;
    }

    @Override
    public void run() {
        super.run();
        try {
            ConnectionFactory factory = new ConnectionFactory();
            factory.setHost("localhost");
            Connection connection = factory.newConnection();
            Channel channel = connection.createChannel();

            channel.queueDeclare(nome + "-c", false, false, false, null);

            Consumer consumer = new DefaultConsumer(channel) {
                @Override
                public void handleDelivery(String consumerTag, Envelope envelope, AMQP.BasicProperties properties,
                        byte[] body) throws IOException {
                    String corpo = new String(body, "UTF-8");
                    String[] res = corpo.split("#####");
                    int valor = arquivos.incrementaContador(res[0], cliente);
                    arquivos.writeBytesInFile(res[0] + valor + ".client" + cliente, res[1].getBytes(), false);
                    System.out.println("Mensagem retransmitida de " + res[0] + ": " + res[1].substring(0, 10) + "...");
                }
            };
            channel.basicConsume(nome + "-c", true, consumer);
        } catch (IOException e) {
            e.printStackTrace();
        } catch (TimeoutException e) {
            e.printStackTrace();
        }
    }

}
