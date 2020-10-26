package modelos;

public abstract class Pessoa {
	
	protected String nome;
	protected int cpf;
	protected int rg;
	protected int idade;
	protected String cargo;
	protected int telefone;
	
	protected void setNome(String nome) {
		this.nome = nome;
	}
	
	protected String getNome() {
		return this.nome;
	}
	
	protected void setCpf(int cpf) {
		this.cpf = cpf;
	}

	protected int getCpf() {
		return this.cpf;
	}
	
	protected void setRg(int rg) {
		this.rg = rg;
	}

	protected int getRg() {
		return this.rg;
	}
	
	protected void setIdade(int idade) {
		this.idade = idade;
	}

	protected int getIdade() {
		return this.idade;
	}
	
	protected void setCargo(String cargo) {
		this.cargo = cargo;
	}
	
	protected String getCargo() {
		return this.cargo;
	}
	
	protected void setTelefone(int telefone) {
		this.telefone = telefone;
	}

	protected int getTelefone() {
		return this.telefone;
	}
	
	
}
