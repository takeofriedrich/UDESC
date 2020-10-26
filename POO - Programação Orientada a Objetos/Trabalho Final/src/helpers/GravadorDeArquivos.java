package helpers;

import java.util.ArrayList;
import java.io.FileWriter;
import java.io.IOException;

public class GravadorDeArquivos {

	private String caminho;

    public GravadorDeArquivos(String caminho){
        this.caminho = caminho;
    }
    
    public void gravar(ArrayList<String> linhas) {
    	
    	try {
    		
    		FileWriter arq = new FileWriter(this.caminho);
    		
    		for(int i=0;i<linhas.size();i++) {
    			arq.write(linhas.get(i));
    		}
    		arq.close();
    		
    	} catch (IOException e) {
            System.err.printf("Erro na abertura do arquivo: %s.\n",e.getMessage());
            System.exit(0);
        }

    }
	
}
