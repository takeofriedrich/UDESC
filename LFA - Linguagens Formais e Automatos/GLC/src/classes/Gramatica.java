package classes;

import java.util.LinkedList;
import java.util.Random;

public class Gramatica {
	private LinkedList<String> naoTerminais = new LinkedList<String>();
	private LinkedList<String> terminais = new LinkedList<String>();
	private LinkedList<Producao> producoes = new LinkedList<Producao>();
	private String inicial;
	
	public void adicionaNaoTerminal(String variavel) {
		this.naoTerminais.add(variavel);
	}
	
	public void adicionaTerminal(String variavel) {
		this.terminais.add(variavel);
	}
	
	public void adicionaProducao(String de, String para) {
		this.producoes.add(new Producao(de,para));
	}
	
	public LinkedList<String> getNaoTerminais() {
		return naoTerminais;
	}
	public void setNaoTerminais(LinkedList<String> naoTerminais) {
		this.naoTerminais = naoTerminais;
	}
	public LinkedList<String> getTerminais() {
		return terminais;
	}
	public void setTerminais(LinkedList<String> terminais) {
		this.terminais = terminais;
	}
	public LinkedList<Producao> getProducoes() {
		return producoes;
	}
	public void setProducoes(LinkedList<Producao> producoes) {
		this.producoes = producoes;
	}
	public String getInicial() {
		return inicial;
	}
	public void setInicial(String inicial) {
		this.inicial = inicial;
		if(!naoTerminais.contains(inicial)) {
			naoTerminais.add(inicial);
		}
	}
	
	public String toString() {
		String gramatica = "Gramatica:\n\n";
		gramatica += "Variaveis nao terminais: ";
		
		for(int i=0;i<this.naoTerminais.size();i++) {
			gramatica += naoTerminais.get(i) + " ";
		}
		
		gramatica += "\n";
		
		gramatica += "Variaveis terminais: ";
		for(int i=0;i<this.terminais.size();i++) {
			gramatica += terminais.get(i) + " ";
		}
		
		gramatica += "\nVariavel inicial: " + inicial +"\n";
		gramatica += "\nProduções: \n";
		
		for(int i=0;i<this.producoes.size();i++) {
			gramatica += producoes.get(i).toString();
		}
		
		return gramatica;
		
	}
	
	
	public boolean contemPalavraVazia() {
		for(int i=0;i<this.producoes.size();i++) {
			if (this.producoes.get(i).getPara().equals("ε")) {
				return true;
			}
		}
		
		return false;
	}
	
	public boolean contemProducao(String de, String para) {
		for(int i=0;i<this.producoes.size();i++) {
			if(this.producoes.get(i).getDe().equals(de) && this.producoes.get(i).getPara().equals(para)) {
				return true;
			}
		}
		return false;
	}
	
	public boolean contemProducao(Producao p) {
		return contemProducao(p.getDe(),p.getPara());
	}
	
	private char geraLetraMaiusculaASCII() {
		
		Random r = new Random();
		return (char)(r.nextInt((90-65)+1)+65);
		
	}
	
	public String geraNaoTerminal(LinkedList<String> naoTerminais) {
		
		while(true) {
			
			String nT = "" + geraLetraMaiusculaASCII();
			
			if(!naoTerminais.contains(nT)) {
				return nT;
			}
			
		}
		
	}
	
	public String geraNaoTerminal() {
		
		while(true) {
			
			String nT = "" + geraLetraMaiusculaASCII();
			
			if(!naoTerminais.contains(nT)) {
				return nT;
			}
			
		}
		
	}
	
}
