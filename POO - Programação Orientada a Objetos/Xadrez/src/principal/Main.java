package principal;

//imports para as classes do jar "poo_tabuleiro"
import br.sc.udesc.cct.dcc.tads.poo.tabuleiro.DesenharTabuleiro;
import br.sc.udesc.cct.dcc.tads.poo.tabuleiro.EstiloTabuleiro;
import br.sc.udesc.cct.dcc.tads.poo.tabuleiro.Peca;
import br.sc.udesc.cct.dcc.tads.poo.tabuleiro.Tabuleiro;

import java.util.ArrayList;

import br.sc.udesc.cct.dcc.tads.poo.tabuleiro.Casa;
import desenhoTabuleiros.tabuleiroModelo1;
import desenhoTabuleiros.tabuleiroModelo2;
import desenhoTabuleiros.tabuleiroModelo3;
import desenhoTabuleiros.tabuleiroModelo4;
//import desenhoTabuleiros.tabuleiroModelo5;
import modelo.Peao;
import modelo.Torre;
import modelo.Cavalo;

public class Main{
	
	public static void main(String[] args){
		
		Tabuleiro tabuleiro = new Tabuleiro(8,8);
		EstiloTabuleiro estilo = new EstiloTabuleiro();
		//EstiloTabuleiro estilo = new tabuleiroModelo3();

		Peca t1 = new Torre(Peca.BRANCA);
		Peca t2 = new Torre(Peca.PRETA);
		
		Peca c1 = new Cavalo(Peca.BRANCA);

		tabuleiro.addPeca(t1, 4, 4);
		tabuleiro.addPeca(t2, 0, 3);
		tabuleiro.addPeca(c1, 3, 6);

		c1.selecionar();
		
		tabuleiro.atualizar();
		
		//para este exercício, estas duas linhas não devem ser mexidas.
		DesenharTabuleiro saida = new DesenharTabuleiro();
		saida.desenhar(tabuleiro, estilo);
		
	}
}