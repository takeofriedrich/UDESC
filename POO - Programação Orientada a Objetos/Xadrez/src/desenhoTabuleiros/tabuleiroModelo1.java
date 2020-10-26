package desenhoTabuleiros;

import br.sc.udesc.cct.dcc.tads.poo.tabuleiro.Tabuleiro;
import br.sc.udesc.cct.dcc.tads.poo.tabuleiro.EstiloTabuleiro;
import br.sc.udesc.cct.dcc.tads.poo.tabuleiro.Peca;

public class tabuleiroModelo1 extends EstiloTabuleiro{
	
	private Tabuleiro tabuleiro;
	
	public tabuleiroModelo1() {
		super();
	}
	
	protected void criarColuna(){
		this.coluna = "|";
	}
	
	protected void criarJuncao(){
		this.juncao = "";
	}
	
	protected void criarAntesCasaVazia(){
		this.antesCasaVazia = " ";
	}
	
	protected void criarDepoisCasaVazia(){
		this.depoisCasaVazia = " ";
	}

	protected void criarAntesCasaSelecionada(){
		this.antesCasaSelecionada = "-";
	}

	protected void criarDepoisCasaSelecionada(){
		this.depoisCasaSelecionada = "-";
	}

	protected void criarEntrelinha(){
		this.entrelinha = "";
		for(int i =0;i<this.tabuleiro.getLargura();i++){
			this.entrelinha+= this.juncao+"";
		}
		this.entrelinha += this.juncao+"\n";
	}
	
	public String desenhar(){
		String tab = "";

		tab += this.entrelinha;

		for(int j =0;j<this.tabuleiro.getAltura();j++){
			String linha = "";

			for(int i =0;i<this.tabuleiro.getLargura();i++){

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

			tab += linha+this.coluna+"";
			tab += this.entrelinha;
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

		this.criarEntrelinha();
	}
	
	
}

