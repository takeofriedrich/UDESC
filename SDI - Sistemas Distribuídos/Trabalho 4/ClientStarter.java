import java.io.IOException;
import java.util.concurrent.TimeoutException;

import com.rabbitmq.client.Channel;
import com.rabbitmq.client.Connection;
import com.rabbitmq.client.ConnectionFactory;

public class ClientStarter {

    private String nome;
    private Arquivos arquivos = new Arquivos();

    public ClientStarter(String nome) {
        this.nome = nome;
    }

    private final String QUEUE_STARTER = "SERV";
    private final String QUEUE_ENDER = "SERV_CLOSE";

    public void start() throws IOException, TimeoutException {
        ConnectionFactory factory = new ConnectionFactory();
        factory.setHost("localhost");
        Connection connection = factory.newConnection();
        Channel channel = connection.createChannel();

        channel.queueDeclare(QUEUE_STARTER, false, false, false, null);

        channel.basicPublish("", QUEUE_STARTER, null, nome.getBytes("UTF-8"));

        channel.close();
        connection.close();
    }

    public void end() throws IOException, TimeoutException {
        ConnectionFactory factory = new ConnectionFactory();
        factory.setHost("localhost");
        Connection connection = factory.newConnection();
        Channel channel = connection.createChannel();

        channel.queueDeclare(QUEUE_ENDER, false, false, false, null);
        channel.basicPublish("", QUEUE_ENDER, null, nome.getBytes("UTF-8"));

        channel.close();
        connection.close();
    }

    public void send() throws IOException, TimeoutException {
        ConnectionFactory factory = new ConnectionFactory();
        factory.setHost("localhost");
        Connection connection = factory.newConnection();
        Channel channel = connection.createChannel();

        byte[] file = arquivos.readBytesFromFile("teste.txt");

        channel.queueDeclare(nome + "-s", false, false, false, null);
        channel.basicPublish("", nome + "-s", null, file);

        channel.close();
        connection.close();
    }

}
