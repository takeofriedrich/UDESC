package arquivosExternos;

import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.EOFException;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.util.LinkedList;
import java.util.List;

public class EditorBinario {
	
	public void GravaBinario(String caminho, List<String> dados) throws Exception {
		
		FileOutputStream arq = new FileOutputStream(caminho);
	    DataOutputStream gravarArq = new DataOutputStream(arq);
	    
	    for(int i=0;i<dados.size();i++) {
	    	gravarArq.writeUTF(dados.get(i));
	    }

	    arq.close();
	    
	}
	
	public List<String> leBinario(String caminho) throws Exception{
		List<String> dados = new LinkedList<String>();
		
		FileInputStream arq = new FileInputStream(caminho);
	    DataInputStream lerArq = new DataInputStream(arq);
	    
	  
	    String s = lerArq.readUTF();
	    
	    while(s != "/0") {
	    	dados.add(s);
	    	try {
	    		s = lerArq.readUTF();
	    	}catch(EOFException e) {
	    		break;
	    	}
	    }
	    
	    arq.close();
	    return dados;
		
	}
	
	public void limpa(String caminho) throws Exception {
		
		FileOutputStream arq = new FileOutputStream(caminho);
	    DataOutputStream gravarArq = new DataOutputStream(arq);
	    
	    gravarArq.writeUTF("");

	    arq.close();
	    
	}
	
	private void iniciaArquivo(String caminho, String linha) throws Exception {
		
		FileOutputStream arq = new FileOutputStream(caminho);
	    DataOutputStream gravarArq = new DataOutputStream(arq);
	    
	    gravarArq.writeUTF(linha);

	    arq.close();

	}

}
