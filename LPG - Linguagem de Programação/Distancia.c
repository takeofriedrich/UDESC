#include <stdlib.h>
#include <stdio.h>
#include <math.h>

typedef struct ponto{

    float x;
    float y;
    float z;

}ponto;

float distancia_pontos(ponto p1, ponto p2){

    float parte1 = pow(p1.x-p2.x,2);

    float parte2 = pow(p1.y-p2.y,2);

    float parte3 = pow(p1.z-p2.z,2);

    return sqrt(parte1+parte2+parte3);
}

void LePontos( ponto *p1){

    float x, y, z;

    scanf("%f",&x);
    scanf("%f",&y);
    scanf("%f",&z);

    p1->x = x;
    p1->y = y;
    p1->z = z;
}

int main(){

    ponto u,v;

    printf("Digite as coordenadas do 1o ponto:\n");
    LePontos(&u);

    printf("Digite as coordenadas do 2o ponto:\n");
    LePontos(&v);

    printf("A distancia entre os pontos eh:\n");
    printf("%.2f",distancia_pontos(u,v));

    return 0;
}
