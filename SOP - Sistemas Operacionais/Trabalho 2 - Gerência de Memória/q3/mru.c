#include "mru.h"

void* imprimeLong2(void *valor){
    printf("%ld ",(long)(valor));
}

/*
    Pseudocódigo: (talvez as operações estejam fora de ordem, mas a lógica continua)

    Percorre as entradas lógicas
        O conjunto de físicas está cheio?
            Não:
                Página já está nas físicas?
                    Não:
                        Adiciona ela nas físicas
                        Cria sua entrada no array de idades (precisam estar mapeadas no mesmo index)
                        Incrementa em 1 a idade das demais páginas
                        Incrementa em 1 o contador de falta de páginas
                    Sim:
                        Zera a idade da página física em questão
                        Incrementa em 1 a idade das demais páginas
            Sim:
                Página já está nas físicas?
                    Sim:
                        Zera a idade da página física em questão
                        Incrementa em 1 a idade das demais páginas
                    Não:
                        Procura a vitima das fisicas que possui a maior idade
                        Retira a vitima da fisicas
                        Retira a entrada da vitima da lista de idades
                        Incrementa em 1 a idade das demais páginas
                        Adiciona nas físicas a nova página
                        Cria sua entrada no array de idades (precisam estar mapeadas no mesmo index)
                        Incrementa em 1 o contador de falta de páginas
    fimAlgoritmo
*/

int mru(list *logicas, int npf){

    if(npf<1) return -1;

    list *fisicas = list_create(sizeof(long));
    list *idades = list_create(sizeof(int));

    int max = logicas->tam;
    int flag;

    push(fisicas,elementAt(logicas,0),0);
    push(idades,elementAt(fisicas,0),0);

    int falta = 1;

    for(int cont=1;cont!=max;cont++){

        if(fisicas->tam < npf){

            flag = -1;

            for(int i=0;i<fisicas->tam;i++){

                if((long)(elementAt(fisicas,i)) == (long)(elementAt(logicas,cont))){
                    flag = i;
                    break;
                }
            }

            if(flag == -1){ // página não está nas físicas

                for(int i=0;i<idades->tam;i++){

                    int *iddTmp = (int*)elementAt(idades,i);
                    replaceAt(idades,i,iddTmp+1);

                }

                push(fisicas,elementAt(logicas,cont),0);
                push(idades,0,0);

                falta++;

            }else{ // página já estava nas físicas

                for(int i=0;i<idades->tam;i++){

                    int *iddTmp = (int*)elementAt(idades,i);
                    replaceAt(idades,i,iddTmp+1);
                    
                }

                replaceAt(idades,flag,0);

            }

        }else{ // agora as páginas físicas já estão cheias

            flag = -1;

            for(int i=0;i<fisicas->tam;i++){

                if((long)(elementAt(fisicas,i)) == (long)(elementAt(logicas,cont))){
                    flag = i;
                    break;
                }
            }

            if(flag == -1){ // ocorre a falta de página

                int *maior = (int*)elementAt(idades,0);
                int pos = 0;

                for(int i=1;i<idades->tam;i++){

                    if((int*)(elementAt(idades,i)) > maior){
                        maior = (int*)(elementAt(idades,i));
                        pos = i;
                    }
                }

                pop(fisicas,pos);
                pop(idades,pos);

                for(int i=0;i<idades->tam;i++){

                    int *iddTmp = (int*)elementAt(idades,i);
                    replaceAt(idades,i,iddTmp+1);

                }

                push(fisicas,elementAt(logicas,cont),0);
                push(idades,0,0);

                falta++;

            }else{ // encontrou a página

                for(int i=0;i<idades->tam;i++){

                    int *iddTmp = (int*)elementAt(idades,i);
                    replaceAt(idades,i,iddTmp+1);

                }

                replaceAt(idades,flag,0);

            }

        }

    }

    list_destroy(fisicas);
    list_destroy(idades);

    return falta;

}