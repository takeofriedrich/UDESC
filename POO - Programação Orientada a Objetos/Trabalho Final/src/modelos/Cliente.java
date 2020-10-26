package modelos;

public class Cliente extends Pessoa {
	
	int codigo;
	
	public Cliente(	
			int codigo,
			String nome,
			int cpf,
			int rg,
			int idade,
			String cargo,
			int telefone){
		super();
		this.setCodigo(codigo);
		this.setNome(nome);	
		this.setCpf(cpf);
		this.setRg(rg);
		this.setIdade(idade);
		this.setCargo(cargo);
		this.setTelefone(telefone);
	}
	
	public void setCodigo(int codigo) {
		this.codigo = codigo;
	}
	
	public int getCodigo() {
		return this.codigo;
	}
	
	public void printCliente() {
		System.out.println("Codigo: "+this.getCodigo());
		System.out.println("Nome: "+this.getNome());
		System.out.println("CPF: "+this.getCpf());
		System.out.println("RG: "+this.getRg());
		System.out.println("Idade: "+this.getIdade());
		System.out.println("Cargo: "+this.getCargo());
		System.out.println("Telefone: "+this.getTelefone());
		System.out.println();
		
	}
	
	public String getClienteCSV() {
		String cliente = "";
		String csvDivisor = ",";
		
		cliente += getCodigo() + csvDivisor;
		cliente += getNome() + csvDivisor;
		cliente += Integer.toString(getCpf()) + csvDivisor ; 
		cliente += Integer.toString(getRg()) + csvDivisor ;
		cliente += Integer.toString(getIdade()) + csvDivisor ;
		cliente += getCargo() + csvDivisor ;
		cliente += Integer.toString(getTelefone()) + '\n';
		
		return cliente;
	}
}
