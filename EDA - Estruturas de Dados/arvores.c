#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define SIM 1
#define NAO 0

#define SUCESSO 1
#define FRACASSO 0

typedef int tipoChave;

typedef struct{
    tipoChave identificador;
    int idade;
    int nome[30];
}info;

typedef struct noABB{
    info dados;
    struct noABB *esq;
    struct noABB *dir;
}Nodo;

typedef struct ABB{
    Nodo *raiz;
    int tamInfo;
}Arvore;

Arvore *cria(int tamInfo){
    Arvore *descritor = (Arvore*)malloc(sizeof(Arvore));
    if(descritor){
        descritor->raiz = NULL;
        descritor->tamInfo = tamInfo;
        return descritor;
    }
}

void freeNodo(Nodo *n){
    if(n){
        freeNodo(n->esq);
        freeNodo(n->dir);
        free(n);
    }
}

void reinicia(Arvore *a){
    freeNodo(a->raiz);
    a->raiz = NULL;
}

Arvore *destroi(Arvore *a){
    reinicia(a);
    free(a);
    return NULL;
}

int busca(Arvore *a, info *destino, tipoChave chaveDeBusca){
    Nodo *aux = a->raiz;
    while(aux!=NULL && aux->dados.identificador != chaveDeBusca){
        if(chaveDeBusca < (aux->dados.identificador) ) aux = aux->esq;
        else aux = aux->dir;
    }
    if(aux!=NULL){
        memcpy(destino,&(aux->dados),a->tamInfo);
        return SUCESSO;
    }else return FRACASSO;
}

int insere(Arvore *a, info *aInserir){
    Nodo *aux1, *aux2, *novo;
    
    aux1 = a->raiz;
    aux2 = a->raiz;
    
    while(aux1 != NULL){
        if(aux1->dados.identificador == aInserir->identificador) return FRACASSO; // Esse nodo já está na árvore
        else aux2 = aux1;
        if(aInserir->identificador<aux1->dados.identificador) aux1 = aux1 -> esq;
        else aux1 = aux1 -> dir;
    }
    
    novo = (Nodo*)malloc(sizeof(Nodo));
    if(novo){
        memcpy(&(novo->dados),aInserir,a->tamInfo);
    
        if(aux2 != NULL){
            if(novo->dados.identificador < aInserir->identificador) aux2->esq = novo;
            else aux2->dir = novo;
        }else a->raiz = novo;
        return SUCESSO;
    }
    return FRACASSO;
}

int removeNodo(Arvore *a, tipoChave chaveDeBusca){
    Nodo *substituto, *paiSubstituto, *alvo, *paiAlvo, *proximo;
    alvo = a->raiz;
    
    while(alvo!=NULL && (alvo->dados.identificador != chaveDeBusca)){
        paiAlvo = alvo;
        if(chaveDeBusca < alvo->dados.identificador) alvo = alvo->esq;
        else alvo = alvo->dir;
    }
    
    if(alvo==NULL) return FRACASSO; // Essa chave não existe dentro da árvore
    
    if(alvo->esq == NULL){
        if(alvo->dir == NULL) substituto = NULL; // Alvo é uma folha
        else substituto = alvo ->dir;
    }else{ // Se o alvo a esquerda não for nulo
        if(alvo->dir == NULL) substituto = alvo->esq;
        else{
            paiSubstituto = alvo;
            substituto = alvo->dir;
            proximo = substituto ->esq;
            while(proximo!=NULL){
                paiSubstituto = substituto;
                substituto = proximo;
                proximo = proximo -> esq;
            }
            if(paiSubstituto!=alvo){
                paiSubstituto -> esq = substituto -> dir;
                substituto -> dir = alvo -> dir;
            }
            substituto -> esq = alvo -> esq;
        }
    }
    
    if(alvo==a->raiz) a->raiz = substituto;
    else{
        if(alvo == paiAlvo->esq) paiAlvo->esq = substituto;
        else paiAlvo->dir = substituto;
    }
    
    free(alvo);
    return SUCESSO;
    
}

int main(){

  return 0;
}
