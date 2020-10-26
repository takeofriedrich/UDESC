package modelo;

import java.util.ArrayList;

import br.sc.udesc.cct.dcc.tads.poo.tabuleiro.*;

public class Bispo extends Peca{
	
	public Bispo(int cor) {
		super(cor);
	}
	
	public String getPecaIcone(){
		if(this.cor == Peca.BRANCA){
			return "b";
		}else{
			return "B";
		}
	}
	
	
}