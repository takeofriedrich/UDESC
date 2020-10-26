#include <stdlib.h>
#include <stdio.h>

void LeMatriz(int **matriz, int lin, int col);
void ImprimeMatriz(int **matriz, int lin, int col);
void DesalocaMatriz(int **matriz, int lin);
int **AlocaMatriz(int lin, int col);

int main(){

    int **matriz;
    int lin, col;
    int i,j;

    printf("Digite as dimensoes da matriz a ser alocado:\n");
    scanf("%d",&lin);
    scanf("%d",&col);

    matriz = AlocaMatriz(lin,col);

    LeMatriz(matriz,lin,col);

    printf("A matriz lida eh:\n");

    ImprimeMatriz(matriz,lin,col);

    DesalocaMatriz(matriz,lin);

    return 0;
}

void LeMatriz(int **matriz, int lin, int col){

    int i,j;

    for(i=0;i<lin;i++){
        printf("Digite os elementos da linha %d:\n",i);
        for(j=0;j<col;j++){
            scanf("%d",&matriz[i][j]);
        }
    }

}

void ImprimeMatriz(int **matriz, int lin, int col){

    int i,j;

    for(i=0;i<lin;i++){
        for(j=0;j<col;j++){
            printf("%d\t",matriz[i][j]);
        }
        printf("\n");
    }

}

void DesalocaMatriz(int **matriz, int lin){

    int i;

    for(i=0;i<lin;i++){
        free(matriz[i]);
    }

    free(matriz);

}

int **AlocaMatriz(int lin, int col){

    int i,j;

    int **matriz;

    matriz = (int**)malloc(lin*sizeof(int*));

    for(i=0;i<col;i++){
        matriz[i] = (int*)malloc(col*sizeof(int));
    }

    return matriz;

}
