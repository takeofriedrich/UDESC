package arquivosExternos;

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;

import classes.Gramatica;

public class Entrada {
	
	private EditorTexto t = new EditorTexto();
	private Gramatica g;
	
	private final String minusculas = "abcdefghijklmnopqrstuvwxyz";
	private final String mauisculas = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	private final int[] numeros = {1,2,3,4,5,6,7,8,9,0};
	
	public Entrada() {
		
	}
	
	public Gramatica getGramatica() {
		return this.g;
	}
	
	public void setGramatica(Gramatica g) {
		this.g = g;
	}
	
	private void transformaGramatica(List<String> linhas) {
		Gramatica g = new Gramatica();
		
		String[] naoTerminais = linhas.get(0).split(" ");
		for(int i=0;i<naoTerminais.length;i++) {
			g.adicionaNaoTerminal(naoTerminais[i]);
		}
		
		String[] terminais = linhas.get(1).split(" ");
		for(int i=0;i<terminais.length;i++) {
			g.adicionaTerminal(terminais[i]);
		}
		
		g.setInicial(linhas.get(2));
		
		for(int i=3;i<linhas.size();i++) {
			String[] linha = linhas.get(i).split("->");
			g.adicionaProducao(linha[0], linha[1]);
		}
		
		this.g = g;
	}

	
	public void leGramaticaT(String caminho) throws Exception {
		
		transformaGramatica(t.leTexto(caminho));
		
	}
	
	public void gravaGramaticaT(String caminho) throws Exception{
				
		this.t.gravaTexto(caminho, transformaTexto());
		
	}
	
	private ArrayList<String> transformaTexto(){
		ArrayList<String> linhas = new ArrayList<String>();
		
		String naoTerminais = "";
		for(int i=0;i<g.getNaoTerminais().size() - 1;i++) {
			naoTerminais += g.getNaoTerminais().get(i) + " ";
		}
		naoTerminais += g.getNaoTerminais().get(g.getNaoTerminais().size()-1) + "\n";
		linhas.add(naoTerminais);
		
		String terminais = "";
		for(int i=0;i<g.getTerminais().size() - 1;i++) {
			terminais += g.getTerminais().get(i) + " ";
		}
		
		terminais += g.getTerminais().get(g.getTerminais().size()-1) + "\n";
		linhas.add(terminais);
		
		linhas.add(g.getInicial()+"\n");
		
		for(int i=0;i<g.getProducoes().size()-1;i++) {
			String linha = "";
			linha += g.getProducoes().get(i).getDe();
			linha += "->";
			linha += g.getProducoes().get(i).getPara() + "\n";
			linhas.add(linha);
		}
		String linha = "";
		linha += g.getProducoes().get(g.getProducoes().size()-1).getDe();
		linha += "->";
		linha += g.getProducoes().get(g.getProducoes().size()-1).getPara() + "\n";
		linhas.add(linha);

		return linhas;
	}
	
	private List<String> converteStringToArray(String texto){
		List<String> retorno = new LinkedList<String>();
		String[] linhas = texto.split("\n");
		for(int i=0;i<linhas.length;i++) {
			retorno.add(linhas[i]);
		}
		return retorno;
	}
	
	private String converteArrayToString(List<String> texto) {
		String retorno = "";
		for(int i=0;i<texto.size();i++) {
			retorno += texto.get(i) + "\n";
		}
		return retorno;
	}


}
