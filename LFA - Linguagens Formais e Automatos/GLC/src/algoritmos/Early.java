package algoritmos;

import java.util.HashMap;
import java.util.LinkedList;

import classes.Gramatica;
import classes.Producao;

public class Early extends Algoritmo{

	private String palavra;
	
	private final char[] simbolosRestritos = {'+','*','-'};
	
	private HashMap<Integer,LinkedList<Producao>> early = new HashMap<Integer,LinkedList<Producao>>();
	
	public boolean isSimboloRestrito(char a) {
		for(int i=0;i<simbolosRestritos.length;i++) {
			if(a==simbolosRestritos[i]) {
				return true;
			}
		}
		return false;
	}
	
	public void executa() throws Exception {
		etapa1();
		etapa2();
	}

	public String getPalavra() {
		return palavra;
	}

	public void setPalavra(String palavra) {
		this.palavra = palavra;
	}
	
	private void construcaoNivel0() {
		
		String simboloInicial = gramatica.getInicial();
		
		LinkedList<Producao> p = gramatica.getProducoes();
		
		LinkedList<Producao> partemS = new LinkedList<Producao>();
		
		for(int i=0;i<p.size();i++) {
			
			if(!p.get(i).getDe().equals(simboloInicial)) {
				continue;
			}else {
				Producao pMarcado = new Producao();
				pMarcado.setDe(simboloInicial);
				
				String para = "." + p.get(i).getPara() + "/0";
				
				pMarcado.setPara(para);
				partemS.add(pMarcado);
			}
			
		}
		
		early.put(0, partemS);
		
	}
	
	public void etapa1() {
		
		construcaoNivel0();
		
		boolean para = false;
		
		LinkedList<Producao> level0 = early.get(0);
		LinkedList<Producao> p = gramatica.getProducoes();
		LinkedList<String> variaveis = gramatica.getNaoTerminais();
		
		while(!para) {
			
			int tamanho = level0.size();
			
			for(int i=0;i<level0.size();i++) {
				
				if(variaveis.contains(String.valueOf(level0.get(i).getPara().charAt(1)))) {
					
					for(int j=0;j<p.size();j++) {
						
						if(!p.get(j).getDe().equals(String.valueOf(level0.get(i).getPara().charAt(1)))){
							continue;
						}else {
							
							Producao novaP = new Producao();
							
							novaP.setDe(p.get(j).getDe());
							
							String para2 = "." + p.get(j).getPara() + "/0";
							
							novaP.setPara(para2);
							
							if(!contemProducao(novaP, level0)) {
								level0.add(novaP);
							}
							
						}
						
					}
					
				}
				
			}
			
			
			if(level0.size() - tamanho == 0) {
				para = true;
			}
			
		}
		
	}
	
	public void etapa2() {
		
		for(int i=1;i<=palavra.length();i++) {
			
			LinkedList<Producao> drAnterior = early.get(i-1);
			LinkedList<Producao> dr = new LinkedList<Producao>();
			
			for(int j=0;j<drAnterior.size();j++) {
				
				if(!drAnterior.get(j).getPara().contains(String.valueOf(palavra.charAt(i-1)))){
					continue;
				}else {
					
					Producao p1 = new Producao();
					
					String de = drAnterior.get(j).getDe();
					String para = drAnterior.get(j).getPara();
					
					String paraAux = para;
					paraAux = paraAux.replace(".","");
					
					String[] aux;
					
					char ar = palavra.charAt(i-1);
					
					if(!isSimboloRestrito(ar)) {
						aux = paraAux.split(String.valueOf(ar));
					}else {
						aux = paraAux.split("\\"+ar);
					}
					
					paraAux = "";
					
					paraAux = aux[0] + palavra.charAt(i-1) + "." + aux[1];
					
					p1.setDe(de);
					p1.setPara(paraAux);
					
					if(!contemProducao(p1,dr)) {
						dr.add(p1);
					}
					
					boolean stop = false;
					
					int cont = 0;
					
					while(!stop) {
						
						int tamanho = dr.size();
						
						for(int k=0;k<dr.size();k++) {
							
							String direito = dr.get(k).getPara();
							
							String B = String.valueOf(direito.charAt(direito.indexOf('.')+1));
							
							if(!gramatica.getNaoTerminais().contains(B)) {
								continue;
							}
							
							for(int l=0;l<gramatica.getProducoes().size();l++) {
								
								if(!gramatica.getProducoes().get(l).getDe().equals(B)) {
									continue;
								}else {
									
									String direitoP = gramatica.getProducoes().get(l).getPara();
									
									Producao p2 = new Producao();
									
									p2.setDe(B);
									p2.setPara("."+direitoP+"/"+i);
									
									if(!contemProducao(p2,dr)) {
										dr.add(p2);										
									}
									
								}
								
							}
							
						}
						
						for(int k=0;k<dr.size();k++) {
							
							if(!dr.get(k).getPara().contains("./")) {
								
								continue;
								
							}else {
								
								String A = dr.get(k).getDe();
								
								String direitoA = dr.get(k).getPara();
								
								String[] aux1 = direitoA.split("/");
								
								int s = Integer.valueOf(aux1[1]);
								
								for(int l=0;l<early.get(s).size();l++) {
									
									if(!early.get(s).get(l).getPara().contains("."+A)) {
										
										continue;
										
									}else {
										
										String B = early.get(s).get(l).getDe();
										String direito = early.get(s).get(l).getPara();
										
										Producao p2 = new Producao();
										p2.setDe(B);
										
										direito = direito.replace(".", "");
										
										String[] splitA = direito.split(A); 
										
										if(splitA[0].length()==0) { // Não possui Beta
											
											if(splitA[1].charAt(0) == '/') { // Não possui phi
												
												p2.setPara(A+"."+splitA[1]);
												
											}else { // Possui phi
												
												String[] splitBarra = splitA[1].split("/");
												
												p2.setPara(A+"."+splitBarra[0]+"/"+splitBarra[1]);
												
											}
											
										}else { // Possui Beta
											
											if(splitA[1].charAt(0) == '/') { // Não possui phi
												
												p2.setPara(splitA[0]+A+"."+splitA[1]);
												
											}else { // Possui phi
												
												String[] splitBarra = splitA[1].split("/");
												
												p2.setPara(splitA[0]+A+"."+splitBarra[0]+"/"+splitBarra[1]);
												
											}
											
										}
										
										if(!contemProducao(p2,dr)) {
											dr.add(p2);											
										}
										
									}
									
								}
								
							}
							
						}
						
						if(tamanho - dr.size() == 0) {
							stop = true;
						}
						
						cont ++;
					}
					
					
				}
				
				
			}
			
			early.put(i, dr);
			
		}
		
	}
	
	public boolean isPalavraReconhecida() throws Exception {
		
		int tamanho = palavra.length();
		
		this.executa();
		
		for(int i=0;i<early.get(tamanho).size();i++) {
			if(!early.get(tamanho).get(i).getDe().equals(gramatica.getInicial())) {
				continue;
			}else {
				
				String para = early.get(tamanho).get(i).getPara();
				
				if(!para.contains("/0")) {
					continue;
				}else {
					
					int posicaoPonto = para.indexOf(".");
					
					if(posicaoPonto == para.length()-3) {
						return true;
					}
					
				}
				
			}
		}
		
		return false;
	}
	
	private boolean contemProducao(Producao p, LinkedList<Producao> lista) {
		
		for(int i=0;i<lista.size();i++) {
			if(lista.get(i).getDe().equals(p.getDe())) {
				if(lista.get(i).getPara().equals(p.getPara())) {
					return true;
				}
			}
		}
		return false;
		
	}

	public HashMap<Integer, LinkedList<Producao>> getEarly() {
		return early;
	}

	public void setEarly(HashMap<Integer, LinkedList<Producao>> early) {
		this.early = early;
	}

}
