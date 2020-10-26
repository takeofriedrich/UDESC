package algoritmos;

import classes.Gramatica;
import classes.Producao;

import java.util.HashMap;
import java.util.LinkedList;

public class EliminacaoProducoesAB extends Algoritmo{
	
	
	private HashMap<String,LinkedList<String>> fechos = new HashMap<String,LinkedList<String>>();
	
	public EliminacaoProducoesAB() {
		
	}
	
	public void constroiFechos() {

		HashMap<String,LinkedList<String>> listadeFechos = new HashMap<String, LinkedList<String>>();
		LinkedList<Producao> p = gramatica.getProducoes();
		LinkedList<String> V = gramatica.getNaoTerminais();
		
		for(int i=0;i<V.size();i++) {
			
			String X = V.get(i);
			LinkedList<String> fechoX = new LinkedList<String>();
			
			for(int j=0;j<p.size();j++) {
				
				if(!p.get(j).getDe().equals(V.get(i))) {
					
					continue;
					
				}else {
					
					
					if(!fechoX.contains(p.get(j).getPara()) && V.contains(p.get(j).getPara())) {
						fechoX.add(p.get(j).getPara());
					}
					
					for(int k=0;k<p.size();k++) {
						
						if(!p.get(k).getDe().equals(p.get(j).getPara())) {
							
							continue;
							
						}else {
							
							if(!V.contains(p.get(k).getDe())) {
								continue;
							}else {
								
								if(!fechoX.contains(p.get(k).getPara()) && V.contains(p.get(k).getPara())) {
									fechoX.add(p.get(k).getPara());
								}
								
							}
							
						}
						
						
					}
					
					
				}
				
			}
			
			fechoX.remove(X);
			
			listadeFechos.put(X, fechoX);
			
			
		}
		
		this.fechos = listadeFechos;
	}
	
	private LinkedList<Producao> construcaoP() {
		
		Gramatica g = this.gramatica;
		
		LinkedList<Producao> p1 = new LinkedList<Producao>();
		
		for(int i=0;i<g.getProducoes().size();i++) {
			
			if(!g.getNaoTerminais().contains(g.getProducoes().get(i).getPara())) {
				
				if(!p1.contains(g.getProducoes().get(i))) {
					p1.add(g.getProducoes().get(i));
				}

			}
			
		}
		
		return p1;
	}
	
	public void exclusaoAB() {
		
		Gramatica nova = new Gramatica();
		
		constroiFechos();
		
		LinkedList<Producao> p = this.gramatica.getProducoes();
		LinkedList<String> V = this.gramatica.getNaoTerminais();
		
		nova.setProducoes(this.construcaoP());
		
		for(int i=0;i<p.size();i++) {
			
			if(!V.contains(p.get(i).getDe())) {
				continue;
			}else {
				
				for(int j=0;j<p.size();j++) {
					
					if(!fechos.get(p.get(i).getDe()).contains(p.get(j).getDe())) {
						continue;
						
					}else {
						if(V.contains(p.get(j).getPara())) {
							continue;
						}else {
							
							if(!nova.contemProducao(p.get(i).getDe(), p.get(j).getPara())) {
								nova.adicionaProducao(p.get(i).getDe(), p.get(j).getPara());
							}
						}
					}
					
				}
				
			}
			
		}
		
		nova.setInicial(this.gramatica.getInicial());
		nova.setNaoTerminais(this.gramatica.getNaoTerminais());
		nova.setTerminais(this.gramatica.getTerminais());
		
		this.gramatica = nova;
		
		
	}

	public HashMap<String, LinkedList<String>> getFechos() {
		return fechos;
	}

	public void setFechos(HashMap<String, LinkedList<String>> fechos) {
		this.fechos = fechos;
	}

	
	public void executa() {
		
		exclusaoAB();
		
	}
	
	
	
	
}
