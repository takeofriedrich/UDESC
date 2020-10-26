#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct no{
    struct no *proximo;
    struct no *anterior;
    void *n;
}No;

typedef struct lista{
    struct no *primeiro;
    int tamanho;
    int tipo;
}Lista;

Lista *listaConstrutor(int tipo){
    Lista *nova = (Lista*)malloc(sizeof(Lista));
    nova->primeiro = NULL;
    nova->tamanho = 0;
    nova->tipo = tipo;
}

void imprimeLista(Lista *l, void(imprime)(void *valor)){
    No *aux = l->primeiro;
    while(aux!=NULL){
        imprime(aux->n);
        aux = aux->proximo;
    }
    printf("\n");
}

int listaVazia(Lista *l){
    if(l->primeiro == NULL){
        return 1;
    }else return -1;
}

No *noConstrutor(Lista *l, void *valor){
    No *novo = malloc(sizeof(No));
    novo->anterior = NULL;
    novo->proximo = NULL;
    novo->n = malloc(l->tipo);
    memcpy(&(novo->n),&valor,l->tipo);
    return novo;
}

void noDestrutor(No *n){
    n->n = NULL;
    n = NULL;
    free(n);
}

int adicionaLista(Lista *l, void *valor, int posicao){
    No *novo = noConstrutor(l,valor);
    if(listaVazia(l)==1){
        l->primeiro = novo;
        l->tamanho++;
        return 1;
    }else{
        if(posicao > l->tamanho + 1){
            return -1;
        } 
        else{
           if(posicao == 0){
                novo->proximo=l->primeiro;
                l->primeiro->anterior=novo;
                l->primeiro=novo;
                l->tamanho++;
                return 1;
            }else if(posicao == l->tamanho){
                No *aux = l->primeiro;
                while(aux->proximo!=NULL) aux = aux->proximo;
                novo->anterior = aux;
                aux->proximo = novo;
                l->tamanho++;
                return 1;
            }else{
                No *aux = l->primeiro;
                for(int i=0;i<posicao;i++) aux = aux->proximo;
                novo->proximo = aux;
                novo->anterior = aux->proximo;
                aux->anterior->proximo = novo;
                aux->anterior = novo;
                l->tamanho++;
                return 1;
            } 
        }
        
    }
    return -1;
}

int removeLista(Lista *l, int posicao){

    if(posicao > l->tamanho) return -1;
    else if(l->tamanho == 1){
        puts("Caso 1");
        noDestrutor(l->primeiro);
        l->tamanho--;
        return 1;
    }else if(posicao == 0){
        puts("Caso 2");
        No *aux = l->primeiro->proximo;
        noDestrutor(l->primeiro);
        l->primeiro = aux;
        l->tamanho--;
        return 1;
    }else if(posicao == l->tamanho - 1){
        puts("Caso 3");
        No *aux = l->primeiro;
        while(aux->proximo!=NULL) aux = aux->proximo;
        No *aux2 = aux->anterior;
        noDestrutor(aux);
        aux2->proximo = NULL;
        l->tamanho--;
        return 1;
    }else{
        No *aux = l->primeiro;
        for(int i=0;i<posicao;i++) aux = aux->proximo;
        aux->anterior->proximo = aux->proximo;
        aux->proximo->anterior = aux->anterior;
        noDestrutor(aux);
        l->tamanho--;
        return 1;
    }
    return -1;
}
