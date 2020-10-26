package algoritmos;

import classes.Gramatica;

public abstract class Algoritmo {
	
	protected Gramatica gramatica;

	public Gramatica getGramatica() {
		return gramatica;
	}

	public void setGramatica(Gramatica gramatica) {
		this.gramatica = gramatica;
	}
	
	public abstract void executa() throws Exception;

}
