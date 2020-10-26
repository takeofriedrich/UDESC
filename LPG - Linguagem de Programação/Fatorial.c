#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void LimpaTela(){
    system("CLS");
}

void Linha(){
    printf("__________________________________________________________\n");
}

void PulaLinha(){
    printf("\n");
}

int fatorial(int num){

    if(num==0)
        return 1;

    int cont, fatorial;

    fatorial=num;
    for(cont=num-1;cont>1;cont--){
        fatorial=fatorial*cont;
    }

return fatorial;
}

int main() {

    int controle=0, x, fat;

    while(controle!=1){

        Linha();
        printf("\n\tDigite um numero para saber o seu fatorial\n");
        Linha();
        scanf("\n%d",&x);

        fat=fatorial(x);

        LimpaTela();
        Linha();
        printf("\n\t%d! = %d\n",x,fat);
        Linha();
        printf("\nDigite 0 para tentar outros valores");
        printf("\nDigite 1 para sair\n");
        Linha();
        PulaLinha();
        scanf("%d",&controle);
        LimpaTela();

    }

    return 0;
}
