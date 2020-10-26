#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define SIM 1
#define NAO 0

#define SUCESSO 1
#define FRACASSO 0

#define MAX 20

typedef struct{
    char *palavra;
}info;

struct Nodo{
    struct Nodo *proximo;
    info dado;
    int linha;
    int coluna;
};

struct Linha{
      struct Nodo *primeiro;
      struct Nodo *ultimo;
      struct Linha *acima;
      struct Linha *abaixo;
      int numeroPalavras;
};

typedef struct{
      struct Linha *primeira;
      struct Linha *ultima;
      int numeroLinhas;
}MultiLista;

void limpaTela(){
    system("clear");
}

char *criaString(int numeroLetras){
      char *nova = (char*)malloc(numeroLetras*sizeof(char));
      if(nova) return nova;
}

struct Nodo *criaNodo(char *palavra, int linha, int coluna){
    struct Nodo *novo = NULL;
    novo = (struct Nodo*)malloc(sizeof(struct Nodo));
    if(novo){
        int tamanhoPalavra = strlen(palavra)+1;
        novo -> proximo = NULL;
        novo -> dado.palavra = (char*)malloc(sizeof(char)*tamanhoPalavra);
        memcpy( novo->dado.palavra , palavra , tamanhoPalavra );
        novo -> linha = linha;
        novo -> coluna = coluna;
        return novo;
    }
}

struct Linha *criaLinha(struct Nodo *primeiro){
    struct Linha *nova = NULL;
    nova = (struct Linha*)malloc(sizeof(struct Linha));
    if(nova){
        nova ->primeiro = primeiro;
        nova -> ultimo = primeiro;
        nova -> abaixo = NULL;
        nova -> acima = NULL;
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
        nova ->numeroLinhas = 0;
        return nova;
    }
}

int multiListaVazia(MultiLista *m){
      if(m->primeira == NULL && m->ultima == NULL) return SIM;
      else return NAO;
}

int linhaVazia(struct Linha *l){
      if( l->numeroPalavras == 0 ) return SIM;
      else return NAO;
}

void renomeiaArquivos(){
   int ren;
   int ren1;
   
   ren = rename("arquivo.txt", "arquivoOLD.txt");
   ren1 = rename("arqTemp.txt", "arquivo.txt");
	
   if (ren == 0 && ren1 ==0) puts("Arquivos renomeados com sucesso");
   else puts("Erro: Arquivos nao foram renomeados");

}

FILE *abreArquivoLer(){
      FILE *arq;
      arq = fopen("arquivo.txt","r");
      if(arq == NULL) printf("Erro");
         return arq;
}

FILE *abreArquivoGravarTemporario(){
    FILE *arq;
    arq = fopen("arqTemp.txt","w");
    if(arq == NULL) puts("Erro");
    
    return arq;
}

void gravaArquivoTemporario(MultiLista *ml){
    FILE *arq = abreArquivoGravarTemporario();
    if(multiListaVazia(ml) == NAO){
        struct Linha *auxLinha = ml -> primeira;
        while(auxLinha != NULL){
            struct Nodo *auxNodo = auxLinha -> primeiro;
            while(auxNodo != NULL){
                fprintf(arq,"%s",auxNodo->dado.palavra);
                auxNodo = auxNodo -> proximo;
                fprintf(arq," ");
            }
            auxLinha = auxLinha -> abaixo;
            fprintf(arq,"\n");
        }
    }
    fclose(arq);
}

void liberaArquivo(FILE *a){
      fclose(a);
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

void imprimeMultiLista(MultiLista *ml){
    int cont=0;
    puts("\nIMPRIMINDO A LISTA\n");
    if(multiListaVazia(ml) == NAO){
        struct Linha *auxLinha = ml -> primeira;
        while(auxLinha != NULL){
            struct Nodo *auxNodo = auxLinha -> primeiro;
            while(auxNodo != NULL){
                printf("(%d) - %s - %d - L:%d C%d\n",cont,auxNodo->dado.palavra,numeroCaracteresString(auxNodo->dado.palavra),auxNodo->linha,auxNodo->coluna);
                auxNodo = auxNodo -> proximo;
                cont++;
            }
            auxLinha = auxLinha -> abaixo;

        }
        printf("\n");
    }
}

int inserePalavraMultilista(char *palavra, MultiLista *ml, int nL){

    if(multiListaVazia(ml)==SIM){


        struct Nodo *novoNodo = criaNodo(palavra,0,0);
        struct Linha *novaLinha = criaLinha(novoNodo);

        // CONECTANDO A NOVA LINHA NA MULTILISTA
        ml->primeira = novaLinha;
        ml->ultima = novaLinha;
        (ml->ultima->numeroPalavras)++;
        return SUCESSO;
    }else{

        if(nL == SIM){

            struct Nodo *novoNodo = criaNodo(palavra,ml->ultima->ultimo->linha + 1 , 0);
            struct Linha *novaLinha = criaLinha(novoNodo);

            // CONECTANDO A NOVA LINHA NA MULTILISTA
            novaLinha -> acima = ml-> ultima;
            ml -> ultima -> abaixo = novaLinha;
            ml -> ultima = novaLinha;
            (ml->ultima->numeroPalavras)++;
            return SUCESSO;
        }else{
        
            struct Nodo *novoNodo = criaNodo(palavra,ml->ultima->ultimo->linha,ml->ultima->ultimo->coluna + 1);
            
            // CONECTANDO O NOVO NODO NA ULTIMA POSIÇÃO DA ULTIMA LINHA
            ml->ultima->ultimo->proximo = novoNodo;
            ml->ultima->ultimo = novoNodo;
            (ml->ultima->numeroPalavras)++;
            return SUCESSO;

        }

    }
    return FRACASSO;
}

int repeticaoPalavra(MultiLista *ml, char *word){
    int cont = 0;
     struct Linha *auxLinhas = ml->primeira;
     struct Nodo *auxColunas = NULL;
     if(multiListaVazia(ml)==NAO){
          while(auxLinhas != NULL ){
            auxColunas = auxLinhas->primeiro;
              while(auxColunas != NULL){
                if(auxColunas -> dado.palavra == word){
                     cont++;
                }else auxColunas = auxColunas -> proximo;
              }
              auxLinhas = auxLinhas -> abaixo;
          }

    }
return cont;
}

void buscaPalavra(MultiLista *ml){
     char word[256];
     int linha=-1, coluna = -1;
     puts("Digite uma palavra para procurar na multilista");
     scanf("%s",word);
     struct Linha *auxLinha;
     struct Nodo *auxNodo;
     auxLinha=ml->primeira;
     int verificar=0;
     while(auxLinha != NULL){
                auxNodo=auxLinha->primeiro;
                while(auxNodo != NULL){
                    if(strcmp(auxNodo->dado.palavra,word)==0){
                        printf("\nPalavra encontrada em: \nLinha: %d\nColuna%d\n",auxNodo->linha,auxNodo->coluna);
                        verificar=1;
                    }
                    auxNodo=auxNodo->proximo;
                }
                auxLinha=auxLinha->abaixo;
     }
     if(verificar==0){printf("\nPalavra nao encontrada na multilista\n");}
} // Imprime a primeira aparição da palavra na multilista (linha e coluna dela)

void numeroPalavrasMultilista(MultiLista *ml){
    int i, cont = 0;
    struct Linha *nova = ml -> primeira;
    while (nova != NULL){
        cont = cont + nova->numeroPalavras;
        nova = nova -> abaixo;
    }
    puts("Numero de palavras da multilista: ");
    printf("%d\n", cont);
}

int numeroCaracteresTexto(){
      FILE *a = abreArquivoLer();
      char c;
      int cont = 0;
      while(( c = getc(a) ) != EOF ){
        cont++;
      }
      liberaArquivo(a);
      return cont-1;
}

info *alocaInfo (){
    info *novo = (info*)malloc(sizeof(info));
    return novo;
}

void destroiMultiLista(MultiLista *ml){

}

char *removeBarraN(char *palavra){
    int numeroLetras = strlen(palavra);
    for(int i=0;i<numeroLetras; i++){
        if(palavra[i] == '\n'){
            palavra[i] = '\0';
            i = numeroLetras;
        }
    }
    return palavra;
}

void exibePalavrasCaracterEspecifico(MultiLista *ml){
    char c;
    printf("Digite um caracter para procurar na multilista\n");
    setbuf(stdin,NULL);
    scanf("%c",&c);
    limpaTela();
     struct Linha *auxLinhas = ml ->primeira;
     if(multiListaVazia(ml)==NAO){
          while(auxLinhas != NULL ){
              struct Nodo *auxColunas = auxLinhas -> primeiro;
              while(auxColunas != NULL){
                for(int i = 0; i < numeroCaracteresString(auxColunas -> dado.palavra); i++){
                    if(  c == auxColunas -> dado.palavra[i] ){
                        puts("Palavra:");
                        puts(auxColunas -> dado.palavra);
                        puts("\nPosicao:");
                        printf("Linhas: %d - Colunas: %d\n\n", auxColunas->linha, auxColunas ->coluna);
                    } 
                }
                auxColunas = auxColunas -> proximo;
              }
              auxLinhas = auxLinhas -> abaixo;
          }
     }
}


MultiLista  *carregaEDA(){

    FILE *arq = abreArquivoLer();

    MultiLista *ml = criaMultilista();

    int max = numeroCaracteresTexto();

    char *linha = criaString(max);

    int novaLinha = NAO;
    
    char lixos[2] = " ";
    
    info *auxInfo = alocaInfo();

    if(linha){
        while( (fgets(linha, max,arq) != NULL )){
            char *aux;
            int tamanhoLinha = strlen(linha) -1;
            aux = strtok(linha,lixos);

            while (aux != NULL){
                removeBarraN(aux);
                if(inserePalavraMultilista(aux,ml,novaLinha) == FRACASSO) puts("ERRO AO LER MULTILISTA");
                if(novaLinha == SIM) novaLinha = NAO;

                aux = strtok(NULL, lixos);
            }
            novaLinha = SIM;


        }
    }else{
        puts("Erro");
    }
    free(auxInfo);
    liberaArquivo(arq);
    return ml;


}

void removePalavra(MultiLista *ml){ // Remove a ultima palavra da multilista
    int num=0;
    struct Nodo *aux,*auxatras;
    struct Linha *auxLinha;
    aux=ml->ultima->primeiro;
    if(ml->ultima->numeroPalavras>1){
        while(num==0){
                if(aux->proximo == NULL){
                        free(aux->dado.palavra);
                        free(aux);
                        auxatras->proximo=NULL;
                        num=1;
                }
                else{
                    auxatras=aux;
                    aux=aux->proximo;
                }
        }
    }else{
            free(aux->dado.palavra);
            free(aux);
            auxLinha=ml->ultima;
            ml->ultima=ml->ultima->acima;
            free(auxLinha);
    }
    imprimeMultiLista(ml);
}

void removePalavraEspecifica (MultiLista *ml){ // Remove a palavra da linha e da coluna especifica
    int linha, coluna;
    puts("Digite a posicao [linha][coluna] para remover da multilista");
    scanf("%d %d",&linha,&coluna);
    struct Nodo *auxnodo, *auxatras;
    struct Linha *auxlinha,*auxlinhaacima,*auxlinhaabaixo;
    auxlinha=ml->primeira;
    int i;
    for(i=0;i<linha;i++){
        auxlinha=auxlinha->abaixo;
    }
    auxnodo=auxlinha->primeiro;
    if(auxlinha->numeroPalavras>1){
        for(i=0;i<coluna;i++){
            auxatras=auxnodo;
            auxnodo=auxnodo->proximo;
        }
        if(coluna==0){
            auxlinha->primeiro=auxnodo->proximo;
            free(auxnodo->dado.palavra);
            free(auxnodo);
             imprimeMultiLista(ml);
            return;
        }
        if(auxnodo->proximo == NULL){
                        auxatras->proximo=NULL;
                        free(auxnodo->dado.palavra);
                        free(auxnodo);
                         imprimeMultiLista(ml);
                        return;
        }
        if(auxnodo->proximo != NULL){
            auxatras->proximo=auxnodo->proximo;
            free(auxnodo->dado.palavra);
                            free(auxnodo);
        }
    }else{if(auxlinha->abaixo==NULL){
                auxlinhaacima=auxlinha->acima;
                free(auxnodo->dado.palavra);
                free(auxnodo);
                ml->ultima=auxlinhaacima;
                free(auxlinha);
            }
            if(auxlinha->acima!=NULL){
                auxlinhaacima=auxlinha->acima;
                auxlinhaabaixo=auxlinha->abaixo;
                free(auxnodo->dado.palavra);
                free(auxnodo);
                auxlinhaacima->abaixo=auxlinhaabaixo;
                auxlinhaabaixo->acima=auxlinhaacima;
            }
    }
   free(auxlinha);
   imprimeMultiLista(ml);
}

void removeMenu(MultiLista *ml){
    int selecionar;
    printf("1 - Remover a ultima palavra da multilista\n2 - Remover uma palavra especifica da multilista\n\n");
    scanf("%d",&selecionar);
    switch(selecionar){
        case 1:
        removePalavra(ml);
        break;
        case 2:
        removePalavraEspecifica(ml);
        break;

    }
}

void modificaPalavra(MultiLista *ml){ // Edita a palavra que est� na linha e na coluna em espec�fico
    int linha, coluna;
    puts("Digite a posicao [linha][coluna] para remover da multilista");
    scanf("%d %d",&linha,&coluna);
    struct Nodo *auxnodo;
    char word[256];
    struct Linha *auxlinha;
    auxlinha=ml->primeira;
    int i,tamanhoPalavra;
    printf("Qual e a nova palavra a ser inserida?\n");
    scanf("%s",word);
    tamanhoPalavra=sizeof(word);
    for(i=0;i<linha-1;i++){
        auxlinha=auxlinha->abaixo;
    }
    auxnodo=auxlinha->primeiro;
    for(i=0;i<coluna-1;i++){
        auxnodo=auxnodo->proximo;
    }
    auxnodo->dado.palavra=(char*)malloc(sizeof(char)*tamanhoPalavra);
    memcpy( auxnodo->dado.palavra , word , tamanhoPalavra );
    imprimeMultiLista(ml);
}

void inserir(MultiLista *ml){
    puts("Digite uma palavra para inserir");
    char *palavra = criaString(MAX);
    scanf("%s",palavra);
    int opcao = 0;
    limpaTela();
    puts("Escolha uma opcao:");
    puts("1 - Inserir na mesma linha");
    puts("2 - Inserir em outra linha");
    while( opcao<1 || opcao>2) scanf("%d",&opcao);
    if(opcao == 1)  inserePalavraMultilista(palavra,ml,NAO);
    else  inserePalavraMultilista(palavra,ml,SIM);
}

void confirma(){
    char *c = criaString(5);
    puts("Digite algo para CONFIRMAR A ACAO");
    scanf("%s",c);
    getchar();
}

int imprimeOpcoes(){
    int opcao = 0;
    puts("Escolha uma opcao:");
    puts("1 - Imprimir MultiLista");
    puts("2 - Buscar uma palavra");
    puts("3 - Remover uma palavra");
    puts("4 - Exibir numero de palavras do texto");
    puts("5 - Editar uma palavra");
    puts("6 - Inserir uma palavra nova");
    puts("7 - Exibir palavras que possuem um caracter específico");
    while( opcao<1 || opcao>7) scanf("%d",&opcao);
    system("clear");
    return opcao;
}

void menuMultiLista(){
    
    MultiLista *ml = carregaEDA();
    
    switch(imprimeOpcoes()){
        case 1:
            imprimeMultiLista(ml);
            confirma();
        break;
        case 2:
            buscaPalavra(ml);
            confirma();
        break;
        case 3:
            removeMenu(ml);
            confirma();
            gravaArquivoTemporario(ml);
        break;
        case 4:
            numeroPalavrasMultilista(ml);
            confirma();
        break;
        case 5:
            modificaPalavra(ml);
            gravaArquivoTemporario(ml);
        break;
        case 6:
            inserir(ml);
            gravaArquivoTemporario(ml);
        break;
        case 7:
            exibePalavrasCaracterEspecifico(ml);
            confirma();
        break;
    }
}

void menuExterno(){
    int opcao = 0;
    int cont = 0;
    
    while (opcao<1 || opcao>2){
    
        if(cont == 0){
            menuMultiLista();
            confirma();
            limpaTela();
            cont++;
            opcao = 0;
        }else{
        limpaTela();
        puts("Escolha uma opcao:");
        puts("1 - para REPETIR");
        puts("2 - para SAIR");
        scanf("%d",&opcao);
        if(opcao == 1){
            limpaTela();
            menuMultiLista();
            confirma();
            opcao=0;
        }
        if (opcao == 2) renomeiaArquivos();
        }
    }
    
}

int main(){
    
    menuExterno();
    
    return 0;

}

