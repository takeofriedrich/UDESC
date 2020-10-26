#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void LeMatriz(int **matriz, int lin, int col);
void ImprimeMatriz(int **matriz, int lin, int col);
void LimpaTela();

int main(){

    int **matriz1, **matriz2, **matriz3;

    int lin1, lin2, col1, col2, lin3, col3;

    int i,j,k;

    printf("Digite a ordem matriz 1:\n");
    scanf("%d",&lin1);
    scanf("%d",&col1);
    LimpaTela();

    printf("Digite a ordem matriz 2:\n");
    scanf("%d",&lin2);
    scanf("%d",&col2);
    LimpaTela();

    if(col1 != lin2){
        printf("Impossivel multiplicar as duas matrizes\n\n");
        return 0;
    }

    lin3 = lin1;
    col3 = col2;


    matriz1 = (int**)calloc(lin1,sizeof(int*));
    for(i=0;i<lin1;i++){
        *(matriz1+i) = (int*)calloc(col1,sizeof(int));
    }

    matriz2 = (int**)calloc(lin2,sizeof(int*));
    for(i=0;i<lin2;i++){
        *(matriz2+i) = (int*)calloc(col2,sizeof(int));
    }

    matriz3 = (int**)calloc(lin3,sizeof(int*));
    for(i=0;i<lin3;i++){
        *(matriz3+i) = (int*)calloc(col3,sizeof(int));
    }

    printf("Digite os valores da matriz 1:\n");
    LeMatriz(matriz1,lin1,col1);
    LimpaTela();

    printf("Digite os valores da matriz 2:\n");
    LeMatriz(matriz2,lin2,col2);
    LimpaTela();

    MultiplicaMatriz(matriz1,lin1,col1,matriz2,lin2,col2,matriz3);

    ImprimeMatriz(matriz3,lin3,col3);

    for(i=0;i<lin1;i++){
        free(*(matriz1+i));
    }

    for(i=0;i<lin2;i++){
        free(*(matriz2+i));
    }

    for(i=0;i<lin3;i++){
        free(*(matriz3+i));
    }

    free(matriz1);
    free(matriz2);
    free(matriz3);

    return 0;
}

void LimpaTela(){
    system("CLS");
}

void LeMatriz(int **matriz, int lin, int col){

    int i,j;

    for(i=0;i<lin;i++){
        for(j=0;j<col;j++){
            printf("[%d]x[%d]:\n",i,j);
            scanf("%d",&matriz[i][j]);
        }
    }
    printf("\n");

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

void MultiplicaMatriz (int **matriz1, int lin1, int col1, int **matriz2, int lin2, int col2, int **resultado){

    int i,j,k;

    for (i=0;i<lin1; i++) {
        for (j=0; j<lin1; j++) {
            for (k=0; k<col1; k++) {
                resultado[i][j] = resultado[i][j] + (matriz1[i][k] * matriz2[k][j]);
            }
        }
    }

}
