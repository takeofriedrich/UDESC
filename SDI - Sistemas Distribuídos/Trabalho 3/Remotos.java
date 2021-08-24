import java.rmi.*;

public interface Remotos extends Remote {

    public String[] sendFile() throws RemoteException;

}
