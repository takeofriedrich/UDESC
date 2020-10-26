#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void LimpaTela(){
    system("CLS");
}

void Linha(){
    printf("__________________________________________________________\n");
}

void PulaLinha(){
    printf("\n");
}

int quadratica(int a, int b, int c, int *x1, int *x2){

    int delta;

    delta = pow(b,2)-4*a*c;

    if(delta<0)
        return 0;

    *x1= (-b+sqrt(delta))/2;
    *x2= (-b-sqrt(delta))/2;

}

int main(){

    int a,b,c,x1,x2,controle=0;

    while(controle!=1){

        Linha();
        printf("\n\tDigite o coeficiente A:\n");
        Linha();
        scanf("\n%d",&a);
        LimpaTela();
        Linha();
        printf("\n\tDigite o coeficiente B:\n");
        Linha();
        scanf("\n%d",&b);
        LimpaTela();
        Linha();
        printf("\n\tDigite o coeficiente C:\n");
        Linha();
        scanf("\n%d",&c);

        LimpaTela();

        if(quadratica(a,b,c,&x1,&x2)==0){
            LimpaTela();
            Linha();
            printf("\n\tRaizes imaginarias\n");
            Linha();
            printf("\nDigite 0 para tentar outros valores");
            printf("\nDigite 1 para sair\n");
            Linha();
            PulaLinha();
            scanf("%d",&controle);
            LimpaTela();
        }else{

            LimpaTela();
            Linha();
            printf("\n\tRaiz 1 = %d \n\tRaiz 2 = %d\n",x1,x2);
            Linha();
            printf("\nDigite 0 para tentar outros valores");
            printf("\nDigite 1 para sair\n");
            Linha();
            PulaLinha();
            scanf("%d",&controle);
            LimpaTela();

        }

    }

}
