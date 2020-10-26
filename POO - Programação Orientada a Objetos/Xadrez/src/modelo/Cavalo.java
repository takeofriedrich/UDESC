package modelo;

import java.util.ArrayList;

import br.sc.udesc.cct.dcc.tads.poo.tabuleiro.Casa;
import br.sc.udesc.cct.dcc.tads.poo.tabuleiro.Peca;
import br.sc.udesc.cct.dcc.tads.poo.tabuleiro.Tabuleiro;

public class Cavalo extends Peca{
	
	public Cavalo(int cor) {
		super(cor);
	}
	
	public String getPecaIcone(){
		if(this.cor == Peca.BRANCA){
			return "c";
		}else{
			return "C";
		}
	}
	
	@Override
	public ArrayList<Casa> movimentosPossiveis(Tabuleiro tabuleiro){
		
		ArrayList<Casa> casas = new ArrayList<Casa>();

		Casa aux = new Casa(0,0); // APENAS INICIALIZANDO UMA VARIAVEL AUXILIAR CASA
		
		for(int i=0;i<8;i++) {
			switch(i) {
			case 0:
				if( this.getAltura() == tabuleiro.getAltura() ||  this.getLargura() == tabuleiro.getLargura()) i++;
				aux = tabuleiro.getCasaNaPosicao(this.getAltura()+2,this.getLargura()+1);
				break;
			case 1:
				if( this.getAltura() == tabuleiro.getAltura() ||  this.getLargura() == 0) i++;
				aux = tabuleiro.getCasaNaPosicao(this.getAltura()+2,this.getLargura()-1);
				break;
			case 2:
				if( this.getAltura() == 0 ||  this.getLargura() == tabuleiro.getLargura()) i++;
				aux = tabuleiro.getCasaNaPosicao(this.getAltura()-2,this.getLargura()+1);
				break;
			case 3:
				if( this.getAltura() == 0||  this.getLargura() == 0) i++;
				aux = tabuleiro.getCasaNaPosicao(this.getAltura()-2,this.getLargura()-1);
				break;
			case 4:
				if( this.getAltura() == tabuleiro.getAltura() ||  this.getLargura() == tabuleiro.getLargura()) i++;
				aux = tabuleiro.getCasaNaPosicao(this.getAltura()+1,this.getLargura()+2);
				break;
			case 5:
				if( this.getAltura() == tabuleiro.getAltura() ||  this.getLargura() == 0) i++;
				aux = tabuleiro.getCasaNaPosicao(this.getAltura()+1,this.getLargura()-2);
				break;
			case 6:
				if( this.getAltura() == 0 ||  this.getLargura() == tabuleiro.getLargura()) i++;
				aux = tabuleiro.getCasaNaPosicao(this.getAltura()-1,this.getLargura()+2);
				break;
			case 7:
				if( this.getAltura() == 0 ||  this.getLargura() == 0) i++;
				aux = tabuleiro.getCasaNaPosicao(this.getAltura()-1,this.getLargura()-2);
				break;
			}
		
			
		}
		
		return casas;
	}
	
}