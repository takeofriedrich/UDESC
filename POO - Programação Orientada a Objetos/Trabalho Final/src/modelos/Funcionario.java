package modelos;

public class Funcionario extends Pessoa{
	
	protected Funcionario(String nome){
		super();
		this.setCargo("Funcionario");
		this.setNome(nome);
	}
}
