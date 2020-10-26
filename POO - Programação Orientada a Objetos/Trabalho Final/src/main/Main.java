package main;

import repositorios.RepositorioClientes;
import repositorios.RepositorioQuartos;

import modelos.Quarto;
import modelos.Cliente;

public class Main {

	public static void main(String[] args) {
		
		RepositorioQuartos c = new RepositorioQuartos();
		
		for(int i=0;i<c.quartos.size();i++) {
			c.quartos.get(i).printQuarto();
		}
		
	}

}
