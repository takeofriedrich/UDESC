package modelo;
import java.util.ArrayList;

import br.sc.udesc.cct.dcc.tads.poo.tabuleiro.Casa;
import br.sc.udesc.cct.dcc.tads.poo.tabuleiro.Peca;
import br.sc.udesc.cct.dcc.tads.poo.tabuleiro.Tabuleiro;

public class Torre extends Peca{

	public Torre(int cor){
		super(cor);
	}

	@Override
	public ArrayList<Casa> movimentosPossiveis(Tabuleiro tabuleiro){

		ArrayList<Casa> casas = new ArrayList<Casa>();

		int largura = this.getLargura();
		int altura = this.getAltura();
		
		
		// WHILE QUE PERCORRE EM Y PARA CIMA
		int cima = altura - 1;
		while(cima > -1){
			Casa c = tabuleiro.getCasaNaPosicao(cima,largura);
			if(c.temPeca()) {
				if(c.getPeca().temMesmaCor(this)) {
					break;
				}else {
					casas.add(c);
					break;
				}
			}
			casas.add(c);
			cima--;
		}
		
		casas.add(this.casa);
		
		// WHILE QUE PERCORRE EM Y PARA BAIXO
		int baixo = altura + 1;
		while(baixo < tabuleiro.getAltura()) {
			Casa c = tabuleiro.getCasaNaPosicao(baixo,largura);
			if(c.temPeca()) {
				if(c.getPeca().temMesmaCor(this)) {
					break;
				}else {
					casas.add(c);
					break;
				}
			}
			casas.add(c);
			baixo++;
		}
		
		// WHILE QUE PERCORRE EM X PARA DIREITA
		int direita = largura + 1;
		while(direita < tabuleiro.getLargura()) {
			Casa c = tabuleiro.getCasaNaPosicao(altura,direita);
			if(c.temPeca()) {
				if(c.getPeca().temMesmaCor(this)) {
					break;
				}else {
					casas.add(c);
					break;
				}
			}
			casas.add(c);
			direita++;
		}
		
		// WHILE QUE PERCORRE EM X PARA ESQUERDA
		int esquerda = largura - 1;
		while(esquerda > -1) {
			Casa c = tabuleiro.getCasaNaPosicao(altura,esquerda);
			if(c.temPeca()) {
				if(c.getPeca().temMesmaCor(this)) {
					break;
				}else {
					casas.add(c);
					break;
				}
			}
			casas.add(c);
			esquerda--;
		}
		
		return casas;
		
	}

	@Override
	public String getPecaIcone(){
		if(this.cor == Peca.BRANCA){
			return "t";
		}else{
			return "T";
		}
	}
}