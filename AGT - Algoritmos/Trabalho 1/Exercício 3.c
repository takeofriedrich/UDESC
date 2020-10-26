#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){

    int a,n,c,prim=0,perf;


        scanf("%d",a);
        for(a=n-1;a>1;a--){
            prim=a;
            if(n%a==0){ // nao eh primo
                c=1;
            }
        }

        if(c==0){


        prim=0;
        printf("%d é Primo",prim);
        }
return 0;
    }

