#include <stdio.h>
#include <stdlib.h>

int main (){

    int i,j,cont=0, vetor[5];

    printf("Digite 5 valores diferentes\n");
    for(i=0;i<=4;i++){ // Defini o vetor com tamanho igual a 10
        scanf("%d",&vetor[i]);
    }

    for(i=0;i<=4;i++){
        for(j=0;j<=4;j++){
            if(vetor[i]<vetor[j]){
                cont++;
            }
            if(cont==4){
                printf("O menor valor do vetor eh %d, na posicao %d",vetor[i],i);
            }
        }
        cont=0;
    }

    return 0;
}



