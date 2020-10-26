package desenhoTabuleiros;

import br.sc.udesc.cct.dcc.tads.poo.tabuleiro.Tabuleiro;
import br.sc.udesc.cct.dcc.tads.poo.tabuleiro.EstiloTabuleiro;
import br.sc.udesc.cct.dcc.tads.poo.tabuleiro.Peca;

public class tabuleiroModelo3 extends EstiloTabuleiro{
	
	private Tabuleiro tabuleiro;
	
	protected void criarColuna(){
		this.coluna = "#";
	}
	
	protected void criarAntesCasaSelecionada(){
		this.antesCasaSelecionada = "(";
	}

	protected void criarDepoisCasaSelecionada(){
		this.depoisCasaSelecionada = ")";
	}
	
	private String entreColunas() {
		return "#";
	}
	
	private String espaco() {
		return " ";
	}
	
	private String inicializa() {
		return "";
	}
	
	private String linhaX() {
		String linhaX = this.inicializa();
		
		for (int i=0;i<this.tabuleiro.getLargura();i++) {
			for (int j=0;j<4;j++) {
				linhaX += this.entreColunas();
			}
		}
		
		linhaX += this.entreColunas();
		
		return linhaX;
	}
	
	
	private String linhaIntermediaria() {
		String linhaIntermediaria = this.inicializa();
		
		for (int i=0;i<this.tabuleiro.getLargura();i++) {
			linhaIntermediaria += this.entreColunas();
			
			for (int j=0;j<3;j++) {
				linhaIntermediaria += this.espaco();
			}
			
		}
		
		linhaIntermediaria += this.entreColunas();
		
		return linhaIntermediaria;
	}
	
	private String pulaLinha() {
		return "\n";
	}
	
	public String desenhar() {
		
		String tab = this.inicializa();
		
		tab += this.linhaX();
		tab += this.pulaLinha();
		
		for(int j =0;j<this.tabuleiro.getAltura();j++) { // LINHAS
			
			tab += linhaIntermediaria();
			tab += this.pulaLinha();
			String linha = "";
			
			for(int i =0;i<this.tabuleiro.getLargura();i++) { // COLUNAS
				
				String antes = this.antesCasaVazia;
				String depois = this.depoisCasaVazia;

				if(this.tabuleiro.getCasaNaPosicao(j,i).selecionada()){
					antes = this.antesCasaSelecionada;
					depois = this.depoisCasaSelecionada;
				}

				if(this.tabuleiro.getCasaNaPosicao(j,i).temPeca()){
					Peca p = this.tabuleiro.getCasaNaPosicao(j,i).getPeca();
					String icone = p.getPecaIcone();
					linha+= this.coluna+antes+icone+depois;
				}else{
					linha+= this.coluna+antes+" "+depois;
				}
				
			}
			
			tab += linha+this.coluna;
			tab += this.pulaLinha();
			tab += linhaIntermediaria();
			tab += this.pulaLinha();
			tab += this.linhaX();
			tab += this.pulaLinha();
			
		}
		
		return tab;
		
	}
	
	public void setTabuleiro(Tabuleiro tab){
		this.tabuleiro = tab;
	}

	public void processar() {
		this.criarAntesCasaVazia();
		this.criarDepoisCasaVazia();
		this.criarAntesCasaSelecionada();
		this.criarDepoisCasaSelecionada();
		this.criarColuna();
		this.criarJuncao();

		this.linhaX();
	}
	
}
