#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){

    int m,i,fat,som=0,div=0;

    printf("Digite um valor de m\n");
    scanf("%d",&m);

    if(m%2==0){//M é par

        for(i=1;i<m;i++){

            if(m%i==0){
                div++;
            }
        }

    printf("%d possui %d divisores",m,div);

    }else{

    if(m<=12){//M é impar

            printf("%d! = ",m);
            for(fat=1;m>1;m--){
                fat=fat*m;
            }
                printf("%d",fat);
            }else{

                for(i=1;i<=m;i++){
                som=som+i;
                }

                printf("\nA soma dos inteiros de 1 ate %d eh= %d",m,som);
            }
    }

    return 0;
}




