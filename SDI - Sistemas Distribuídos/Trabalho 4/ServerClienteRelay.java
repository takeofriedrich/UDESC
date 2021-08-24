import java.io.IOException;
import java.util.concurrent.TimeoutException;

import com.rabbitmq.client.Channel;
import com.rabbitmq.client.Connection;
import com.rabbitmq.client.ConnectionFactory;

public class ServerClienteRelay {

    private String nome;

    public ServerClienteRelay(String nome) {
        this.nome = nome;
    }

    public void run(String message) {

        ConnectionFactory factory = new ConnectionFactory();
        factory.setHost("localhost");
        Connection connection;
        try {
            connection = factory.newConnection();
            Channel channel = connection.createChannel();

            channel.queueDeclare(nome + "-c", false, false, false, null);

            channel.basicPublish("", nome + "-c", null, message.getBytes("UTF-8"));

            channel.close();
            connection.close();
        } catch (IOException | TimeoutException e) {
            e.printStackTrace();
        }

    }
}
