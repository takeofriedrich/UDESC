#include "fifo.h"

/*
    Pseudocódigo: (talvez as operações estejam fora de ordem, mas a lógica continua)

    Percorre as entradas lógicas
        O conjunto de físicas está cheio?
            Não:
                Página já está nas físicas?
                    Não:
                        Adiciona ela nas páginas físicas
                        Adiciona ela na fila
                        Incrementa em 1 o contador de falta de páginas
                    Sim:
                        Não realiza nenhuma operação
            Sim:
                Página já está nas físicas?
                    Sim:
                        Não realiza nenhuma operação
                    Não:
                        Procura a vitima das físicas, no caso a de mais prioridade na fila
                        Substitui a vitima
                        Incrementa em 1 o contador de falta de páginas
    fimAlgoritmo
*/

int fifo(list *logicas, int npf){

    if(npf<1) return -1;

    list *fisicas  = list_create(sizeof(long));

    int max = logicas->tam; // npf-1
    
    list *fifo = list_create(sizeof(long));

    push(fisicas,elementAt(logicas,0),0);
    push(fifo,elementAt(logicas,0),0);

    int falta = 1;

    for(int cont=1;cont!= max ;cont++){

        if(fisicas->tam < npf){

            int flag = 0;

            for(int i=0;i<fisicas->tam;i++){
                if((long)elementAt(fisicas,i) == (long)elementAt(logicas,cont)){
                    flag = 1;
                    break;
                }
            }

            if(flag == 0){
                push(fisicas,elementAt(logicas,cont),fisicas->tam);
                push(fifo,elementAt(logicas,cont),fifo->tam);
                falta++;
            }

        }else{

            int flag = 0;


            for(int i=0;i<fisicas->tam;i++){
                if((long)elementAt(fisicas,i) == (long)elementAt(logicas,cont)){
                    flag = 1;
                }
            }

            if(flag == 0){
                void* vitima = elementAt(fifo,0);
                pop(fifo,0);

                for(int i=0;i<fisicas->tam;i++){
                    if(elementAt(fisicas,i) == vitima){
                        replaceAt(fisicas,i,elementAt(logicas,cont));
                        push(fifo,elementAt(logicas,cont),fifo->tam);
                        falta++;
                        break;
                    }
                }
            }
 
        }
    }

    list_destroy(fifo);
    list_destroy(fisicas);
    return falta;
}