#include <stdlib.h>
#include <stdio.h>
#include "string.h"
#include "lista.h"
#include "fifo.h"
#include "mru.h"

int npf;

/*
    Comentários referentes a estrutura de listas estão em list.h
*/

void* imprimeLong(void *valor){
    printf("%ld ",(long)(valor));
}

int main(int argc, char *argv[])
{

    npf = atoi(argv[1]);

    list *logicas  = list_create(sizeof(long));

    long valor;

    for(int i=0;valor!=-1;i++){
        scanf("%ld",&valor);
        push(logicas,(void*)(valor),i);
    }

    if(logicas->tam > 1){
        pop(logicas,logicas->tam);
    }else{
        pop(logicas,0);
    }
    
    if(logicas->tam>-1){
        int fifoFalta = fifo(logicas,npf);
        printf("FIFO:\t%d faltas de pagina\n",fifoFalta);

        int mruFalta = mru(logicas,npf);
        printf("MRU:\t%d faltas de pagina\n",mruFalta);
    }
    
    list_destroy(logicas);

    return 0;
}