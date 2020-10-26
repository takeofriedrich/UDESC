#include <stdio.h>
#include <stdlib.h>

int main (){

    int i=1,j=2,k,cont1;//Variáveis da sequencia de Fibonacci
    int prin1=0,prin2=0;//Variáveis para ser primo

    for(cont1=1;cont1<=30;cont1++){

    k=i+j;

        for(prin1=k-1;prin1>1;prin1--){
            if(k%prin1==0){//Para ser primo
                prin2=1;
            }
        }
        if(prin2==0){
        printf("\n%d  Eh primo",k);
        }else{
        printf("\n%d  Nao eh primo",k);
        }
        prin2=0;

    i=j;
    j=k;

    }

return 0;

}
