#include <stdlib.h>
#include <stdio.h>
#include <math.h>

typedef struct ponto{

    float x;
    float y;

}ponto;

float distancia_pontos(ponto p1, ponto p2){

    float parte1 = pow(p1.x-p2.x,2);

    float parte2 = pow(p1.y-p2.y,2);

    return sqrt(parte1+parte2);
}

int EhOuNaoEh(ponto inf, ponto sup, ponto pont){

    if((inf.x <= pont.x && pont.x <= sup.x) && (inf.y <= pont.y && pont.y <= sup.y)){
        return 1;
    }else{
        return 0;
    }

}

void LePontos( ponto *p1){

    float x, y;

    scanf("%f",&x);
    scanf("%f",&y);

    p1->x = x;
    p1->y = y;
}

int main(){

    ponto inf,sup, pont;

    printf("Digite as coordenadas do vertice inferior:\n");
    LePontos(&inf);

    printf("Digite as coordenadas do vertice superior:\n");
    LePontos(&sup);

    printf("Digite as coordenadas do ponto:\n");
    LePontos(&pont);

    int funcao = EhOuNaoEh(inf,sup,pont);

    if(  funcao == 1){
        printf("\nEsta dentro do retangulo");
    } else{
       printf("\nNao esta dentro do retangulo");
    }


    return 0;
}
