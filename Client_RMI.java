import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;

//@author Vitor Sousa @vss2

/*
* Compilando o aplicativo
* 
* Compile a interface remota
* Compile a classe de implementação
* Compile o programa do servidor
* Compile o programa do cliente
*/



public class Client {
	private Cliente(){}
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		String entrada = in.nextLine();

		// Escrever o texto num arquivo

		Writer escritor = null;

		try {
			escritor = new BufferedWriter(new OutputStreamWriter (new FileOutputStream("Arquivo.txt"), "utf-8"));
			escritor.write(entrada);
		} catch (IOException IOEerro) {
			System.out.print("Erro: " + IOEerro.toString())
		} finally {
			try {
				escritor.close();
			}
		}

		try {
			// Pegando o registro
			Registry registro = LocateRegistry.getRegistry(null);

			// Procurando no registro em busca do objeto remoto
			Hello stub = (Hello) registry.lookup("Hello");

			// Chamando o método remoto usado o objeto obtido

			stub.printMsg();
		} catch (Exception e) {
			System.out.println("Client exception: " + e.toString());
			e.printStackTrace();
		}
	}
}