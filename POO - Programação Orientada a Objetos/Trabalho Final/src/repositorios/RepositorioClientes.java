package repositorios;

import java.util.ArrayList;

import modelos.Cliente;
import helpers.LeitorDeArquivos;
import helpers.GravadorDeArquivos;

public class RepositorioClientes {
	
	public ArrayList<Cliente> clientes = new ArrayList<Cliente>();
	LeitorDeArquivos leitor = new LeitorDeArquivos("data/clientes.csv");
	GravadorDeArquivos gravador = new GravadorDeArquivos("data/clientes.csv");
	
	public RepositorioClientes(){
		this.carregaDados();
	}

	public void carregaDados() {
		
		ArrayList<String> linhas = new ArrayList<String>();
		linhas = leitor.ler();
		
		for(int i=0;i<linhas.size();i++) {
			
			String csvDivisor = ",";
			String[] clienteLinha = linhas.get(i).split(csvDivisor);
			int codigo = Integer.parseInt(clienteLinha[0]);
			String nome = clienteLinha[1];
	        int cpf = Integer.parseInt(clienteLinha[2]);
	        int rg = Integer.parseInt(clienteLinha[3]);
	        int idade = Integer.parseInt(clienteLinha[4]);
	        String cargo = clienteLinha[5];
	        int telefone = Integer.parseInt(clienteLinha[6]);
	        Cliente c = new Cliente(codigo,nome,cpf,rg,idade,cargo,telefone);
	        clientes.add(c);
	        
		}
		
	}
	
	public void gravaDados() {
		
		ArrayList<String> linhas = new ArrayList<String>();
		
		for(int i=0;i<this.clientes.size();i++) {
			linhas.add(clientes.get(i).getClienteCSV());
		}
		
		gravador.gravar(linhas);
		
	}

}