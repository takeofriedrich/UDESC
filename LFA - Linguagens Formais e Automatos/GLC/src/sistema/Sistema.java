package sistema;

import algoritmos.Early;
import algoritmos.EliminacaoProducoesAB;
import algoritmos.EliminacaoSimbolosInuteis;
import algoritmos.FormaNormalChomsky;
import algoritmos.ProducoesVazias;
import arquivosExternos.Entrada;
import classes.Gramatica;
import classes.Producao;

import java.util.LinkedList;
import java.util.HashMap;

public class Sistema {
	
	static String aux = "";
	
	public Gramatica gramatica;
	
	private Entrada entrada;
	
	private HashMap<Integer,LinkedList<Producao>> producoesEarly = new HashMap<Integer,LinkedList<Producao>>();
	
	private HashMap<String,LinkedList<String>> fechos = new HashMap<String,LinkedList<String>>();
	
	private EliminacaoProducoesAB eliminacaoProducoesAB = new EliminacaoProducoesAB();
	private ProducoesVazias producoesVazias = new ProducoesVazias();
	private EliminacaoSimbolosInuteis eliminacaoSimbolosInuteis = new EliminacaoSimbolosInuteis();
	private FormaNormalChomsky fnc = new FormaNormalChomsky();
	private Early early = new Early();
	
	public Sistema() {
		
		entrada = new Entrada();
		
		iniciaGramaticaLateX();
		
	}
	
	public void leGramaticaArquivo(String caminho) throws Exception {
		entrada.leGramaticaT(caminho);
		gramatica = entrada.getGramatica();
	}
	
	public void salvaGramaticaArquivo(String caminho) throws Exception {
		entrada.setGramatica(gramatica);
		entrada.gravaGramaticaT(caminho);
	}
	
	public String converteVariaveisString() {
		String variaveis = "";
		for(int i=0;i<gramatica.getNaoTerminais().size() -1 ;i++) {
			variaveis += gramatica.getNaoTerminais().get(i) + " ";
		}
		variaveis += gramatica.getNaoTerminais().get(gramatica.getNaoTerminais().size()-1);
		return variaveis;
	}
	
	public String converteTerminaisString() {
		String terminais = "";
		for(int i=0;i<gramatica.getTerminais().size()-1;i++) {
			terminais += gramatica.getTerminais().get(i) + " ";
		}
		terminais += gramatica.getTerminais().get(gramatica.getTerminais().size()-1);
		return terminais;
	}
	
	public String converteProducoesString() {
		String producoes = "";
		for(int i=0;i<gramatica.getProducoes().size()-1;i++) {
			producoes += gramatica.getProducoes().get(i).toString();
		}
		producoes += gramatica.getProducoes().get(gramatica.getProducoes().size()-1).toString2();
		return producoes;
	}
	
	public void converteStringVariaveis(String variaveis) {
		LinkedList<String> naoTerminais = new LinkedList<String>();
		String[] aux = variaveis.split(" ");
		for(int i=0;i<aux.length;i++) {
			naoTerminais.add(aux[i]);
		}
		gramatica.setNaoTerminais(naoTerminais);
	}
	
	public void converteStringTerminais(String terminais) {
		LinkedList<String> ter = new LinkedList<String>(); 
		String[] aux = terminais.split(" ");
		for(int i=0;i<aux.length;i++) {
			ter.add(aux[i]);
		}
		gramatica.setTerminais(ter);
	}
	
	public void converteStringProducoes(String producoes) {
		LinkedList<Producao> p = new LinkedList<Producao>(); 
		String[] aux = producoes.split("\n");
		for(int i=0;i<aux.length;i++) {
			String[] aux2 = aux[i].split("->");
			Producao nova = new Producao();
			nova.setDe(aux2[0]);
			nova.setPara(aux2[1]);
			p.add(nova);
		}
		gramatica.setProducoes(p);
	}
	
	public String getFechos() {
		
		aux = "";
		
		this.eliminacaoProducoesAB.setGramatica(gramatica);
		this.eliminacaoProducoesAB.constroiFechos();
		this.eliminacaoProducoesAB.getFechos().forEach((k,v)->{
			
			if(v.size()>0) {
				aux += "Fecho(" + k +"): {";
				for(int i=0;i<v.size()-1;i++) {
					aux += v.get(i) + " , ";
				}
				aux += v.get(v.size()-1);
				aux += "}\n";
			}else {
				aux += "Fecho(" + k +"): Ø\n";
			}
			
			
		});
		
		return aux;
	}
	
	public void simbolosInuteis() throws Exception {
		
		eliminacaoSimbolosInuteis.setGramatica(this.gramatica);
		eliminacaoSimbolosInuteis.executa();
		this.gramatica = eliminacaoSimbolosInuteis.getGramatica();
		
	}
	
	public void simbolosInuteis1() throws Exception {
		
		eliminacaoSimbolosInuteis.setGramatica(gramatica);
		eliminacaoSimbolosInuteis.etapa1();
		this.gramatica = eliminacaoSimbolosInuteis.getGramatica();
		
	}
	
	public void simbolosInuteis2() {
		
		eliminacaoSimbolosInuteis.setGramatica(gramatica);
		eliminacaoSimbolosInuteis.etapa2();
		this.gramatica = eliminacaoSimbolosInuteis.getGramatica();
		
	}
	
	public void producoesVazias() throws Exception {
		
		producoesVazias.setGramatica(gramatica);
		producoesVazias.executa();
		this.gramatica = producoesVazias.getGramatica();
		
	}
	
	public void producoesVazias1() throws Exception {
		
		producoesVazias.setGramatica(gramatica);
		producoesVazias.etapa1();
		this.gramatica = producoesVazias.getGramatica();
		
	}
	
	public String getVEpsilon() {
		String aux = "Vε = {";
		for(int i=0;i<producoesVazias.getVEpsilon().size()-1;i++) {
			aux += producoesVazias.getVEpsilon().get(i) + " , ";
		}
		aux += producoesVazias.getVEpsilon().get(producoesVazias.getVEpsilon().size()-1) + "}";
		return aux;
	}
	
	
	public void exclusaoAB() {
		
		eliminacaoProducoesAB.setGramatica(gramatica);
		eliminacaoProducoesAB.exclusaoAB();
		this.gramatica = eliminacaoProducoesAB.getGramatica();
		
	}
	
	public void exclusaoABFechos() {
		
		eliminacaoProducoesAB.setGramatica(gramatica);
		eliminacaoProducoesAB.constroiFechos();
		this.fechos = eliminacaoProducoesAB.getFechos();
		
	}
	
	public void fnc() throws Exception  {
		
		fnc.setGramatica(gramatica);
		fnc.executa();
		this.gramatica = fnc.getGramatica();
		
	}
	
	public void fnc1() throws Exception {
		fnc.setGramatica(gramatica);
		fnc.etapa1();
		this.gramatica = fnc.getGramatica();
	}
	
	public void fnc2() {
		fnc.setGramatica(gramatica);
		fnc.etapa2();
		this.gramatica = fnc.getGramatica();
	}
	
	public void early() throws Exception {
		
		early.setGramatica(gramatica);
		early.executa();
		this.producoesEarly = early.getEarly();
		
	}
	
	public void early1() {
		
		early.setGramatica(gramatica);
		early.etapa1();
		this.producoesEarly = early.getEarly();
		
	}
	
	public void early2() {
		
		early.setGramatica(gramatica);
		early.etapa2();
		this.producoesEarly = early.getEarly();
		
	}
	
	public boolean earlyReconheceu() throws Exception {
		
		early.setGramatica(gramatica);
		return early.isPalavraReconhecida();
		
	}
	
	public String getEarly(){
		aux = "";
		this.producoesEarly.forEach((k,v)->{
			aux += "Nivel "+ k+":\n";
			for(int i=0;i<v.size();i++) {
				aux += "\t"+v.get(i).toString();
			}
			aux+= "\n";
		});
		return aux;
	}
	
	public void setPalavra(String palavra) {
		early.setPalavra(palavra);
	}
	
	public void iniciaGramaticaLateX() {
		
		gramatica = new Gramatica();
		
		gramatica.adicionaNaoTerminal("A");
		gramatica.adicionaNaoTerminal("B");
		gramatica.adicionaNaoTerminal("C");
		gramatica.adicionaNaoTerminal("D");
		gramatica.adicionaNaoTerminal("E");
		
		gramatica.adicionaTerminal("a");
		gramatica.adicionaTerminal("b");
		gramatica.adicionaTerminal("c");
		gramatica.adicionaTerminal("d");
		
		gramatica.setInicial("S");
		
		gramatica.adicionaProducao("S", "A");
		gramatica.adicionaProducao("A", "B");
		gramatica.adicionaProducao("A", "a");
		gramatica.adicionaProducao("A", "ε");
		
	}
	
	public String geraNaoTerminal() {
		return this.gramatica.geraNaoTerminal(this.gramatica.getNaoTerminais());
	}
	

}
