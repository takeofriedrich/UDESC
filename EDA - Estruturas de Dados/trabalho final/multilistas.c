#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define SIM 1
#define NAO 0

#define SUCESSO 1
#define FRACASSO 0

#define MAX 20

struct Nodo{
    struct Nodo *proximo;
    char *palavra;
};

struct Linha{
      struct Nodo *primeiro;
      struct Nodo *ultimo;
      struct Linha *abaixo;
      int numeroPalavras;
};

typedef struct{
      struct Linha *primeira;
      struct Linha *ultima;
}MultiLista;

struct Linha *criaLinha(){
    struct Linha *nova = NULL;
    nova = (struct Linha*)malloc(sizeof(struct Linha));
    if(nova){
        nova ->primeiro = NULL;
        nova -> ultimo = NULL;
        nova -> abaixo = NULL;
        nova -> numeroPalavras = 0;
        return nova;
    }
}

MultiLista *criaMultilista(){
    MultiLista *nova = NULL;
    nova = (MultiLista*)malloc(sizeof(MultiLista));
    if(nova){
        nova ->primeira = NULL;
        nova ->ultima = NULL;
        return nova;
    }
}

char *alocaString(int numeroLetras){
      char *nova = (char*)malloc(numeroLetras*sizeof(char));
      if(nova) return nova;
}

int multiListaVazia(MultiLista *m){
      if(m->primeira == NULL && m->ultima == NULL) return SIM;
      else return NAO;
}

int linhaVazia(struct Linha *l){
      if( l->numeroPalavras == 0 ) return SIM;
      else return NAO;
}

FILE *abreArquivoLer(){
      FILE *arq;
      arq = fopen("input.txt","r");
      if(arq == NULL) printf("Erro");
         return arq;
}

void liberaArquivo(FILE *a){
      fclose(a);
}

struct Linha *alocaLinha(){
      struct Linha *nova = NULL;
      nova = (struct Linha*)malloc(sizeof(struct Linha));
      if(nova){
        nova->primeiro = NULL;
        nova->ultimo = NULL;
        nova->abaixo = NULL;
        nova->numeroPalavras = 0;
        return nova;
      }
}

int inserePalavraLinha(struct Linha *linha){

}

struct Nodo *alocaNodo(){
     struct Nodo *novo = NULL;
     novo = (struct Nodo*)malloc(sizeof(struct Nodo));
     if(novo){
        novo->proximo = NULL;
        novo->palavra = NULL;
        return novo;
     }
}

int numeroCaracteresString(char *palavra){
      int cont = 0;
      char aux;

      do{
        aux = palavra[cont];
        cont++;
      }while(aux != '\0');

      return cont-1;
    }

int numeroCaracteresTexto(FILE *a){
      char c;
      a = abreArquivoLer();
      int cont = 0;
      while(( c = getc(a) ) != EOF ){
        cont++;
      }
      liberaArquivo(a);
      return cont-1;
}

char *texto(FILE *a){
      char *texto, c;
      texto = (char*)malloc(sizeof(char)*numeroCaracteresTexto(a));
      a = abreArquivoLer();
      int cont = 0;

      while(( c = getc(a) ) != EOF ){
        texto[cont] = c;
        cont++;
      }

      liberaArquivo(a);
      return texto;
}

void imprimeTexto(FILE *a){

}

void imprimePalavra(char *palavra, FILE *a){
      for(int i=0;i<numeroCaracteresTexto(a);i++){
        printf("Palavra em %d: %c\n",i,palavra[i]);
      }
}

int numeroLinhas(char *palavra, FILE *a){
      int cont = 0;
      for(int i=0;i<numeroCaracteresTexto(a);i++){
        if(palavra[i] == '\n') cont++;
      }
      return cont+1;
}

MultiLista *iniciaMultiLista(FILE *a){

    MultiLista *ml = criaMultilista();
    
    char *textos = texto(a);
    char *aux, *aux2;
    aux = strtok(textos,"\n");
          while(aux != NULL){
      
        struct Linha *novaLinha = alocaLinha();
        struct Nodo *novoNodo = alocaNodo();
      
        if(novoNodo){
            novaLinha -> primeiro = novoNodo;
            novaLinha -> ultimo = novoNodo;
        }
        
        
        int numeroLetrasFrase = numeroCaracteresString(aux);
        
        for(int i=0;i<numeroLetrasFrase;i++){
                
            if(aux[i] == ' '){
            struct Nodo *nodoTemp = alocaNodo();
            novoNodo->proximo=nodoTemp;
            novaLinha->ultimo=nodoTemp;
            }else{
                str_append(novaLinha->ultimo->palavra,aux[i]);
            }
        }

        aux = strtok(NULL,"\n");
        
        if(multiListaVazia(ml)){
            ml -> primeira = novaLinha;
            ml -> ultima = novaLinha;
        }else{
            ml -> ultima -> abaixo = novaLinha;
            ml -> ultima = novaLinha;
        }
        }

    return ml;
}

int main(){

      FILE *a;
      //imprimePalavra(texto(a),a);
      iniciaMultiLista(a);

      return 0;

}
