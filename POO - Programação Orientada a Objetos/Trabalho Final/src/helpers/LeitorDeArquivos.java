package helpers;

import java.util.ArrayList;
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;

public class LeitorDeArquivos{
    private String caminho;

    public LeitorDeArquivos(String caminho){
        this.caminho = caminho;
    }
    public ArrayList<String> ler(){

        ArrayList<String> linhas = new ArrayList<String>();

        try {
          FileReader arq = new FileReader(this.caminho);
          BufferedReader lerArq = new BufferedReader(arq);
          String linha = lerArq.readLine();
          while (linha != null) {
              linhas.add(linha);
              linha = lerArq.readLine();
          }
          arq.close();
        } catch (IOException e) {
            System.err.printf("Erro na abertura do arquivo: %s.\n",e.getMessage());
            System.exit(0);
        }

        return linhas;
    }
    
}