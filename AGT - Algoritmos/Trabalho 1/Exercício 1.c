#include <stdio.h>
#include <stdlib.h>

int main (){

    int i=1,j=2,k,a;//Variáveis da sequencia de Fibonacci
    int b=0,c=0;//Variáveis para ser primo

    for(a=1;a<=30;a++){

    k=i+j;

        for(b=k-1;b>1;b--){
            if(k%b==0){//Para ser primo
                c=1;
            }
        }
        if(c==0){
        printf("\n%d  Eh primo",k);
        }else{
        printf("\n%d  Nao eh primo",k);
        }
        c=0;

    i=j;
    j=k;

    }

return 0;

}
