import java.rmi.registry.Registry;
import java.rmi.registry.LocateRegistry;
import java.rmi.RemoteException;
import java.rmi.Server.UnicastRemoteObject;

public class Server extends ImplExample {
	public Server() {}
	public static void main(String args[]){

		try {
			// Instanciando a classe de implementação
			ImplExample obj = new ImplExample();

			// Exportando o objeto da classe de implementação
			// aqui são exportados os objetos remotos para o stub

			Hello stub = (Hello) UnicastRemoteObject.exportObject(obj, 0);

			// Ligando o objeto remoto (stub) no registro
			Registry registro = LocateRegistry.getRegistry();

			registry.bind("Hello", stub);

		} catch (Exception e) {

			System.out.println("Server exception: " + e.toString());
			e.printStackTrace();
		}
	}
}

// Possivel uso no exercicio de envio de arquivos
public class FileServer extends UnicastRemoteObject implements FileServerInt {
	private String file = "";

	protected FileServer() throws RemoteException {
		super(); 
		// Construtor automatizado
	}

	public void setfile(String f){
		file = f;
	}

	public boolean logic(FileClientInt c) throws RemoteException {
		//Enviando o arquivo
		try {
			File f1 = new File(file);
			FileInputStream in = new FileInputStream(f1);
			byte[] mydata = new byte[1024*1024];
			int mylen = in.read(mydata);
			while(mylen > 0){
				c.sendData(f1.getName(), mydata, mylen);
				mylen = in.read(mydata);
			}
		} catch (Exception e2) {
			e2.printStackTrace();
		}
		return true;
	}
}