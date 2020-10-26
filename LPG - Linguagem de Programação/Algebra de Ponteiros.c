#include <stdlib.h>

void LeMatriz(int *p, int lin, int col);

int main(){

    int *matriz, tamlin, tamcol;

    printf("Digite o numero de linhas e colunas\n");
    scanf("%d",&tamlin);
    scanf("%d",&tamcol);

    matriz= (int*)malloc(tamlin*tamcol*sizeof(int));

    LeMatriz(matriz,tamlin,tamcol);
    system("CLS");
    ImprimeMatriz(matriz,tamlin,tamcol);

    free(matriz);
    return 0;

}

void LeMatriz(int *p, int lin, int col){

    int i;

    for(i=0;i<lin*col;i++)
        scanf("%d",p+i);

}

void ImprimeMatriz(int *p, int lin, int col){

    int i,j;

    for(i=0;i<lin*col;i++)
        printf("%d\n",*p+i);

}

