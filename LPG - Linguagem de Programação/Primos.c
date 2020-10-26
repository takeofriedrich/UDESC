#include <stdio.h>
#include <stdlib.h>
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

int main(){

    int numero,anteriores,alerta=0,continuacao;

    Linha();
    printf("\nDigite um numero para saber se ele eh primo\n");
    Linha();
    scanf("%d",&numero);
    LimpaTela();

    if(numero==0 ||numero==1)
        printf("\n%d eh primo\n",numero);

    if(numero%anteriores==0){ // nao eh primo
        printf("\n%d nao eh primo\n",numero);
    }else{
        printf("\n%d eh primo\n",numero);
        }

return 0;
}
