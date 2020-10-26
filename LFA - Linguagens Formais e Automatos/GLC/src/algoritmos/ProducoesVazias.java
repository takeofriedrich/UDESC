package algoritmos;

import java.util.LinkedList;

import classes.Gramatica;
import classes.Producao;

public class ProducoesVazias extends Algoritmo{
	
	private LinkedList<String> vEpsilon = new LinkedList<String>();
	
	public void etapa1() throws Exception {
		
		if(!gramatica.contemPalavraVazia()) {
			throw new Exception("Gramatica não contem palavra vazia");
		}
		
		for(int i=0;i<gramatica.getProducoes().size();i++) {
			if(gramatica.getProducoes().get(i).getPara().equals("ε")) {
				if(!vEpsilon.contains(gramatica.getProducoes().get(i).getDe())) {
					vEpsilon.add(gramatica.getProducoes().get(i).getDe());
				}
			}
		}
		
		boolean quebraLoop = false;
		
		do {
			
			int tamanhoV3 = vEpsilon.size();
			
			for(int i=0;i<gramatica.getProducoes().size();i++) {
				for(int j=0;j<vEpsilon.size();j++) {
					if(!gramatica.getProducoes().get(i).getPara().equals("ε")) {
						if(gramatica.getProducoes().get(i).getPara().equals(vEpsilon.get(j))) {
							if(!vEpsilon.contains(gramatica.getProducoes().get(i).getDe())) {
								vEpsilon.add(gramatica.getProducoes().get(i).getDe());
							}
						}
					}
					
				}
			}
			
			
			if( tamanhoV3 - vEpsilon.size() == 0) {
				quebraLoop = true;
			}
			
		}while(!quebraLoop);
		
	}
	
	public void etapa2() {
		
		Gramatica nova = new Gramatica();
		
		LinkedList<Producao> p1 = new LinkedList<Producao>();
		
		// Inicialização de p1
		
		for(int i=0;i<gramatica.getProducoes().size();i++) {
			for(int j=0;j<vEpsilon.size();j++) {
				if(!gramatica.getProducoes().get(i).getPara().equals("ε") && !vEpsilon.contains(gramatica.getProducoes().get(i).getPara())) {
					if(!p1.contains(gramatica.getProducoes().get(i))) {
						p1.add(gramatica.getProducoes().get(i));
					}
				}
			}
		}
		
		boolean quebraLoop = false;
		
		LinkedList<Producao> gambiarra = new LinkedList<Producao>();
		
		do {
			
			int tamanhoP1 = p1.size();
			
			
			for(int i=0;i<gramatica.getProducoes().size();i++) {
				if(!gramatica.getProducoes().get(i).getPara().equals("ε")) {
					for(int j=0;j<vEpsilon.size();j++) {
						if(gramatica.getProducoes().get(i).getPara().contains(vEpsilon.get(j))) {
							
							if(gramatica.getProducoes().get(i).getPara().length()<1) {
								continue;
							}else {
								
								if(gramatica.getProducoes().get(i).getPara().length() <3) {
									
									String para = gramatica.getProducoes().get(i).getPara();
									para += para.replace(vEpsilon.get(j), "");
									
									Producao p = new Producao(gramatica.getProducoes().get(i).getDe(),para);
									
									if(!contemProducao(gambiarra, p)) {
										gambiarra.add(p);
									}
									
								}else {
								
									String[] aux = gramatica.getProducoes().get(i).getPara().split(vEpsilon.get(j));
									
									String para = aux[0] + aux[1];
						
									
									
									Producao p = new Producao(gramatica.getProducoes().get(i).getDe(),para);
									
									if(!contemProducao(gambiarra, p)) {
										gambiarra.add(p);
									}
									
								}
								
								
								
							}
							
						}
					}
				}
			}
			
			if(tamanhoP1 - p1.size() == 0) {
				quebraLoop = true;
			}
			
		}while(quebraLoop == false);
		
		nova.setProducoes(p1);
		
		for(int i=0;i<gambiarra.size();i++) {
			if(!nova.contemProducao(gambiarra.get(i).getDe(), gambiarra.get(i).getPara())) {
				nova.adicionaProducao(gambiarra.get(i).getDe(),gambiarra.get(i).getPara());
			}
		}
		
		nova.setInicial(gramatica.getInicial());
		nova.setNaoTerminais(gramatica.getNaoTerminais());
		nova.setTerminais(gramatica.getTerminais());
		
		// Fazendo a etapa 3:
		if(this.gramatica.contemPalavraVazia()) {
			nova.adicionaProducao("S", "ε");
		}
		
		
		this.gramatica = nova;
		
	}

	public LinkedList<String> getVEpsilon() {
		return this.vEpsilon;
	}

	public void setV1(LinkedList<String> vEpsilon) {
		this.vEpsilon = vEpsilon;
	}

	public void executa() throws Exception {
		this.etapa1();
		this.etapa2();
	}
	
	public boolean contemProducao(LinkedList<Producao> producoes, Producao p) {
		for(int i=0;i<producoes.size();i++) {
			if(producoes.get(i).getDe().equals(p.getDe()) && producoes.get(i).getPara().equals(p.getPara())) {
				return true;
			}
		}
		return false;
	}


}
