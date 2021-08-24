import com.rabbitmq.client.*;

import java.io.IOException;
import java.util.concurrent.TimeoutException;

public class ServidorReceiverEnder extends Thread {

    private static final String QUEUE_NAME = "SERV_CLOSE";
    private Servidor servidor;

    public ServidorReceiverEnder(Servidor servidor) {
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

            channel.queueDeclare(QUEUE_NAME, false, false, false, null);

            Consumer consumer = new DefaultConsumer(channel) {
                @Override
                public void handleDelivery(String consumerTag, Envelope envelope, AMQP.BasicProperties properties,
                        byte[] body) throws IOException {
                    servidor.removerCliente(new String(body, "UTF-8"));
                }
            };
            channel.basicConsume(QUEUE_NAME, true, consumer);
        } catch (IOException e) {
            e.printStackTrace();
        } catch (TimeoutException e) {
            e.printStackTrace();
        }
    }

}
