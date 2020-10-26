package classes;

public class Producao {
	
	private String de;
	private String para;
	
	public Producao(String de, String para) {
		this.de = de;
		this.para = para;
	}
	
	public Producao() {
		// TODO Auto-generated constructor stub
	}

	public String getDe() {
		return de;
	}
	public void setDe(String de) {
		this.de = de;
	}
	public String getPara() {
		return para;
	}
	public void setPara(String para) {
		this.para = para;
	}
	
	public String toString() {
		return this.de + "->" + this.para +"\n";
	}
	
	public String toString2() {
		return this.de + "->" + this.para;
	}
	
	public Producao clone() {
		Producao p2 = new Producao(this.getDe(),this.getPara());
		return p2;
	}

}
