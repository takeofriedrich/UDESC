package modelo;
import br.sc.udesc.cct.dcc.tads.poo.tabuleiro.Peca;

public class Dama extends Peca{
	
	public Dama(int cor) {
		super(cor);
	}
	
	public String getPecaIcone(){
		if(this.cor == Peca.BRANCA){
			return "d";
		}else{
			return "D";
		}
	}
	
}