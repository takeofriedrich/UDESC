package modelo;

import br.sc.udesc.cct.dcc.tads.poo.tabuleiro.Peca;

public class Peao extends Peca{

	public Peao(int cor){
		super(cor);
	}

	@Override
	public String getPecaIcone(){
		if(this.cor == Peca.BRANCA){
			return "p";
		}else{
			return "P";
		}
	}
}