import java.io.IOException;
import java.rmi.*;
import java.rmi.server.*;
import java.rmi.registry.*;

public class RemoteClient implements Remotos {

    private String username;

    public RemoteClient(String username) {
        this.username = username;
    }

    public void run() {

    }

    public String[] sendFile() throws RemoteException {
        try {
            String[] retorno = new String[2];
            retorno[0] = this.username;
            Arquivos arquivos = new Arquivos();
            byte[] bytes = arquivos.readBytesFromFile("teste.txt");
            retorno[1] = new String(bytes);
            return retorno;
        } catch (IOException e) {
            e.printStackTrace();
            return null;
        }

    }
}