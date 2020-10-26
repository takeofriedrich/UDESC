package algoritmos;

import java.util.LinkedList;

import classes.Gramatica;
import classes.Producao;

public class FormaNormalChomsky extends Algoritmo{
	
	public FormaNormalChomsky() {
		super();
	}
	
	public void etapa1() throws Exception {
		
		Algoritmo algoritmo = new ProducoesVazias();
		
		if(gramatica.contemPalavraVazia()) {
			
			algoritmo.setGramatica(gramatica);
			algoritmo.executa();
			this.setGramatica(algoritmo.getGramatica());
			
		}
			
		algoritmo = new EliminacaoProducoesAB();
		
		algoritmo.setGramatica(gramatica);
		algoritmo.executa();
		this.setGramatica(algoritmo.getGramatica());
		
		Gramatica nova = new Gramatica();
		nova.setTerminais(this.gramatica.getTerminais());
		nova.setInicial(this.gramatica.getInicial());
		
		LinkedList<Producao> p2 = this.gramatica.getProducoes();
		LinkedList<String> v2 = this.gramatica.getNaoTerminais();
		
		for(int i=0;i<p2.size();i++) {
			
			if(p2.get(i).getPara().length()>=2) {
				
				String ladoDireito = p2.get(i).getPara();
				
				
				for(int j=0;j<ladoDireito.length();j++) {
					
					String charEmj = ""+ladoDireito.charAt(j);
					
					if(!nova.getTerminais().contains(charEmj)) {
						continue;
						
					}else {
						
						String ladoEsquerdo = gramatica.geraNaoTerminal(v2);
						v2.add(ladoEsquerdo);
						Producao p = new Producao(ladoEsquerdo,""+ladoDireito.charAt(j));
						
						if(!p2.contains(p)) {
							p2.add(p);
						}
						
						p2.get(i).setPara(ladoDireito.replace(charEmj.charAt(0), ladoEsquerdo.charAt(0)));
						
						ladoDireito = ladoDireito.replace(charEmj.charAt(0), ladoEsquerdo.charAt(0));
						
					}
					
				}

				
			}
			
		}
		
		nova.setProducoes(p2);
		nova.setNaoTerminais(v2);
		
		this.gramatica = nova;

	}
	
	public void etapa2() {
		
		Gramatica nova = new Gramatica();
		nova.setTerminais(this.gramatica.getTerminais());
		nova.setInicial(this.gramatica.getInicial());
		
		LinkedList<Producao> p2 = this.gramatica.getProducoes();
		LinkedList<String> v2 = this.gramatica.getNaoTerminais();
		
		
		for(int i=0;i<p2.size();i++) {
			
			if(p2.get(i).getPara().length()>2) {
				
				String para = p2.get(i).getPara();
				
				String novaEsq = "";
				
				while(para.length()>2) {
					
					String doisUltimos = para.charAt(para.length()-2) + "" + para.charAt(para.length()-1);
					
					novaEsq = gramatica.geraNaoTerminal(v2);
					v2.add(novaEsq);
					
					Producao p = new Producao(novaEsq,doisUltimos);
					if(!p2.contains(p)) {
						p2.add(p);
					}
					
					para = para.replace(doisUltimos, novaEsq);
				}
				
				para = p2.get(i).getPara().charAt(0) + novaEsq;
				
				p2.get(i).setPara(para);
				
			}else {
				continue;
			}
			
			
			
		}
	
		nova.setProducoes(p2);
		nova.setNaoTerminais(v2);
		
		this.gramatica = nova;
		
	}
	
	
	public void executa() throws Exception {
		
		etapa2();
		
	}

}
