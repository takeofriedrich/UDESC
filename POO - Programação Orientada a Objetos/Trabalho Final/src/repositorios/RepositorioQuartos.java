package repositorios;

import java.util.ArrayList;

import helpers.LeitorDeArquivos;
import helpers.GravadorDeArquivos;
import modelos.Quarto;

public class RepositorioQuartos {
	
	public ArrayList<Quarto> quartos = new ArrayList<Quarto>();
	LeitorDeArquivos leitor = new LeitorDeArquivos("data/quartos.csv");
	GravadorDeArquivos gravador = new GravadorDeArquivos("data/quartos.csv");
	
	public RepositorioQuartos(){
		this.carregaDados();
	}

	public void carregaDados() {
		
		ArrayList<String> linhas = new ArrayList<String>();
		linhas = leitor.ler();
		
		for(int i=0;i<linhas.size();i++) {
			
			String csvDivisor = ",";
			String[] clienteLinha = linhas.get(i).split(csvDivisor);
			int codigo = Integer.parseInt(clienteLinha[0]);
	        int casal = Integer.parseInt(clienteLinha[1]);
	        int solteiro = Integer.parseInt(clienteLinha[2]);
	        
	        boolean possuiArCondicionado = Boolean.parseBoolean(clienteLinha[3]);
	        boolean possuiFrigobar = Boolean.parseBoolean(clienteLinha[4]);
	        boolean possuiTv = Boolean.parseBoolean(clienteLinha[5]);
	        boolean possuiCofre = Boolean.parseBoolean(clienteLinha[6]);
	        boolean possuiBanheira = Boolean.parseBoolean(clienteLinha[7]);

	        Quarto q = new Quarto(codigo,casal,solteiro,possuiArCondicionado,possuiFrigobar,possuiTv,possuiCofre,possuiBanheira);
	        quartos.add(q);
	        q.printQuarto();
	        
		}
		
	}
	
	public void gravaDados() {
		
		ArrayList<String> linhas = new ArrayList<String>();
		
		for(int i=0;i<this.quartos.size();i++) {
			linhas.add(quartos.get(i).getQuartoCSV());
		}
		
		gravador.gravar(linhas);
		
	}

}