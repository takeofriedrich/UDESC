package arquivosExternos;

import java.io.BufferedReader;
import java.io.DataOutputStream;
import java.io.EOFException;
import java.io.FileOutputStream;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.LinkedList;
import java.util.List;

public class EditorTexto {
	
	public void gravaTexto(String caminho, List<String> dados) throws Exception {
		
		FileWriter arq;
		try {
			arq = new FileWriter(caminho);
		} catch (IOException e) {
			throw new Exception("Falha ao acessar o arquivo especificado");
		}
		
		try {
			
			limpa(caminho);
			
			for(int i=0;i<dados.size();i++) {
		    	arq.write(dados.get(i));
		    }
		}catch(IOException e) {
			arq.close();
			throw new Exception("Falha ao gravar no arquivo");
		}
	    

	    arq.close();
	    
	}
	
	public List<String> leTexto(String caminho) throws Exception{
		List<String> dados = new LinkedList<String>();
		
		FileReader arq = new FileReader(caminho);
        BufferedReader lerArq = new BufferedReader(arq);
        String s = lerArq.readLine();
	    
	    while(s != null) {
	    	dados.add(s);
	    	try {
	    		s = lerArq.readLine();
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
		
		FileWriter arq = new FileWriter(caminho);

	    arq.write(linha);

	    arq.close();

	}

}

