package modelos;

public class Quarto {
	
	protected int codigoQuarto; 
	
	protected int numeroCamaCasal;
	protected int numeroCamaSolteiro;
	
	protected boolean arCondicionado;
	protected boolean frigobar;
	protected boolean tv;
	protected boolean cofre;
	
	protected boolean banheira;
	
	public Quarto(
			int codigoQuarto, 
			int numeroCamaCasal,
			int numeroCamaSolteiro,
			boolean arCondicionado,
			boolean frigobar,
			boolean tv,
			boolean cofre,
			boolean banheira) {
		this.setCodigoQuarto(codigoQuarto);
		this.setNumeroCamaCasal(numeroCamaCasal);
		this.setNumeroCamaSolteiro(numeroCamaSolteiro);
		this.setArCondicionado(arCondicionado);
		this.setFrigobar(frigobar);
		this.setTv(tv);
		this.setCofre(cofre);
		this.setBanheira(banheira);
	}
	
	public void setCodigoQuarto(int codigoQuarto) {
		this.codigoQuarto = codigoQuarto;
	}
	
	public void setNumeroCamaCasal(int numeroCamaCasal) {
		this.numeroCamaCasal = numeroCamaCasal;
	}
	
	public void setNumeroCamaSolteiro(int numeroCamaSolteiro) {
		this.numeroCamaSolteiro = numeroCamaSolteiro;
	}
	
	public void setArCondicionado(boolean condicao) {
		this.arCondicionado = condicao;
	}
	
	public void setFrigobar(boolean condicao) {
		this.frigobar = condicao;
	}
	
	public void setTv(boolean condicao) {
		this.tv = condicao;
	}
	
	public void setCofre(boolean condicao) {
		this.cofre = condicao;
	}
	
	public void setBanheira(boolean condicao) {
		this.cofre = banheira;
	}
	
	public int getCodigoQuarto() {
		return this.codigoQuarto;
	}
	
	public int getNumeroCamaCasal() {
		return this.numeroCamaCasal;
	}
	
	public int getNumeroCamaSolteiro() {
		return this.numeroCamaSolteiro;
	}
	
	public boolean getArCondicionado() {
		return this.arCondicionado;
	}
	
	public boolean getFrigobar() {
		return this.frigobar;
	}
	
	public boolean getTv() {
		return this.tv;
	}
	
	public boolean getCofre() {
		return this.cofre;
	}
	
	public boolean getBanheira() {
		return this.banheira;
	}
	
	public void printQuarto() {
		System.out.println("Codigo do quarto: "+this.getCodigoQuarto());
		System.out.println("Numero de camas de casal: "+this.getNumeroCamaCasal());
		System.out.println("Numero de camas de solteiro: "+this.getNumeroCamaSolteiro());
		if(this.getArCondicionado()) System.out.println("Ar condicionado");
		if(this.getFrigobar()) System.out.println("Frigobar");
		if(this.getTv()) System.out.println("Tv");
		if(this.getCofre()) System.out.println("Cofre");
		if(this.getBanheira()) System.out.println("Banheira");
		System.out.println();
		
	}
	
	public String getQuartoCSV() {
		String quarto = "";
		String csvDivisor = ",";
		
		quarto += this.getCodigoQuarto() + csvDivisor;
		quarto += this.getNumeroCamaCasal() + csvDivisor;
		quarto += this.getNumeroCamaSolteiro() + csvDivisor;
		quarto += this.getArCondicionado() + csvDivisor;
		quarto += this.getFrigobar() + csvDivisor;
		quarto += this.getTv() + csvDivisor;
		quarto += this.getCofre() + csvDivisor;
		quarto += this.getBanheira() + "\n";
		
		return quarto;
		
	}
	
	
}
