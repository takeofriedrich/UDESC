package modelo;

import br.sc.udesc.cct.dcc.tads.poo.tabuleiro.Peca;

public class Rei extends Peca{
	
	public Rei(int cor) {
		super(cor);
	}
	
	public String getPecaIcone(){
		if(this.cor == Peca.BRANCA){
			return "r";
		}else{
			return "R";
		}
	}
	
}