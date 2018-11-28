import java.rmi.Remote;
import java.rmi.RemoteException;

// Criando uma interface remtoa para nossa aplicação

public interface Hello extends Remote {
	void printMsg() throws RemoteException;
}

//Possivel uso no exercicio de enviar arquivo

public interface FileClientInt extends Remote {
	public boolean sendData(String nomeArquivo, byte[] data, int len) throws RemoteException;

	public String getName() throws RemoteException;
}