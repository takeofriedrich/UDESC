package algoritmos;

import java.util.LinkedList;

import classes.Gramatica;
import classes.Producao;

public class EliminacaoSimbolosInuteis extends Algoritmo{
	
	public EliminacaoSimbolosInuteis() {
	}
 
	
	public void etapa1() throws Exception {
		
		Gramatica g1 = this.gramatica;
		
		boolean possuiSEsquerda = false;
		
		for(int i=0;i<g1.getProducoes().size();i++) {
			if(g1.getProducoes().get(i).getDe().equals(g1.getInicial())) {
				possuiSEsquerda = true;
				break;
			}
		}
		
		if(!possuiSEsquerda) {
			throw new Exception("Não há regra de produção que parte de S");
		}
		
		LinkedList<String> v1 = new LinkedList<String>(); // v1 = vazio;
		
		boolean quebraLoop = false;
		
		do {
			
			int tamanhoAntesDoLoop = v1.size();
			
			for(int i=0;i<g1.getProducoes().size();i++) {
				for(int j=0;j<g1.getTerminais().size();j++) { // Lado esquerdo união ( T u V1 )
					if(g1.getProducoes().get(i).getPara().contains(g1.getTerminais().get(j))) {
						if(!v1.contains(g1.getProducoes().get(i).getDe())) {
							v1.add(g1.getProducoes().get(i).getDe());
						}
					}
				}
				for(int j=0;j<v1.size();j++) { // Lado direito união ( T u V1 )
					if(g1.getProducoes().get(i).getPara().contains(v1.get(j))) {
						if(!v1.contains(g1.getProducoes().get(i).getDe())) {
							v1.add(g1.getProducoes().get(i).getDe());
						}
					}
				}
			}
			
			if(v1.size() - tamanhoAntesDoLoop == 0) {
				quebraLoop = true;
			}
			
		}while(!quebraLoop);
		
		LinkedList<Producao> p1 = new LinkedList<Producao>();
		LinkedList<String> subtracao = (LinkedList<String>) g1.getNaoTerminais().clone();
		subtracao.removeAll(v1);
		//subtracao.remove(g1.getInicial());
		
		if(subtracao.size()!=0) {
			for(int i=0;i<g1.getProducoes().size();i++) {
				for(int j=0;j<subtracao.size();j++) {
					if(g1.getProducoes().get(i).getPara().contains(subtracao.get(j))) {
						continue;
					}else {
						if(!p1.contains(g1.getProducoes().get(i))) {
							p1.add(g1.getProducoes().get(i));
						}
					}
				}
			}
		}else {
			p1 = this.gramatica.getProducoes();
		}
			
		Gramatica nova = new Gramatica();
		
		nova.setNaoTerminais(v1);
		nova.setProducoes(p1);
		nova.setTerminais(g1.getTerminais());
		nova.setInicial(g1.getInicial());
		
		this.gramatica = nova;
		
	}
	
	public void etapa2() {
		
		Gramatica g2 = this.gramatica;
		
		boolean quebraLoop = false;
		
		LinkedList<String> t2 = new LinkedList<String>();
		LinkedList<String> v2 = new LinkedList<String>();
		v2.add(g2.getInicial());
		
		do {
			
			int tamanhoT2AntesDoLoop = t2.size();
			int tamanhoV2AntesDoLoop = v2.size();
			
			for(int i=0;i<g2.getProducoes().size();i++) {
				
				for(int j=0; j<g2.getNaoTerminais().size();j++) {
					
					for(int k=0; k<v2.size();k++) {
						
						if(g2.getProducoes().get(i).getPara().contains(g2.getNaoTerminais().get(j)) && g2.getProducoes().get(i).getDe().equals(v2.get(k))) {
							
							if(!v2.contains(g2.getNaoTerminais().get(j))) {
								v2.add(g2.getNaoTerminais().get(j));
							}
							
						}
						
					}
					
				}
				
				for(int j=0; j<g2.getTerminais().size();j++) {
					
					for(int k=0; k<v2.size();k++) {
						
						if(g2.getProducoes().get(i).getPara().contains(g2.getTerminais().get(j)) && g2.getProducoes().get(i).getDe().equals(v2.get(k))) {
							
							if(!t2.contains(g2.getTerminais().get(j))) {
								t2.add(g2.getTerminais().get(j));
							}
							
						}
						
					}
					
				}
				
				
			}
			
			
			if(t2.size() - tamanhoT2AntesDoLoop == 0 && v2.size() - tamanhoV2AntesDoLoop == 0 ) {
				quebraLoop = true;
			}
			
		}while(!quebraLoop);
		
		Gramatica nova = new Gramatica();
		
		LinkedList<Producao> p2 = new LinkedList<Producao>();
		
		LinkedList<String> simbolos = new LinkedList<String>();
		
		simbolos.addAll(v2);
		simbolos.addAll(t2);
		
		for (int i = 0; i < g2.getProducoes().size(); i++) {
			
			for(int j=0 ; j<simbolos.size(); j++) {
				
				if(g2.getProducoes().get(i).getDe().contains(simbolos.get(j)) || g2.getProducoes().get(i).getPara().contains(simbolos.get(j))) {
					
					if(!p2.contains(g2.getProducoes().get(i))) {
						
						p2.add(g2.getProducoes().get(i));
						
					}
					
				}
				
			}
			
		}
		
		
		
		nova.setNaoTerminais(v2);
		
		nova.setProducoes(p2);
		
		nova.setTerminais(t2);
		
		nova.setInicial(g2.getInicial());
		
		this.gramatica = nova;
		
	}


	public void executa() throws Exception {
		
		this.etapa1();
		this.etapa2();
		
	}

}
