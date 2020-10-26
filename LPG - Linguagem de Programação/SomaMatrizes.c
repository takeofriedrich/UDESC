#include <stdlib.h>
#include <stdio.h>
#define NOMEARQUIVO "matriz.txt"

void ImprimeMatriz(int **m, int lin, int col);

void SomaMatriz(int **m1, int **m2, int **mr, int lin, int col);

int main(){

    FILE *arq;

    arq = fopen(NOMEARQUIVO,"r");

    int lin, col;

    int i,j;

    int **m1, **m2, **mr;

    if(arq == NULL){
        printf("Erro ao abrir arquivo\n");
    }else{

        fscanf(arq,"%d %d",&lin, &col);

        fclose(arq);

        m1 = (int**)calloc(sizeof(int),lin);
        for(i=0;i<lin;i++)
            m1[i] = (int*)calloc(sizeof(int),col);

        m2 = (int**)calloc(sizeof(int),lin);
        for(i=0;i<lin;i++)
            m2[i] = (int*)calloc(sizeof(int),col);

        mr = (int**)calloc(sizeof(int),lin);
        for(i=0;i<lin;i++)
            mr[i] = (int*)calloc(sizeof(int),col);


        for(i=0;i<lin;i++){
            for(j=0;j<col;j++){
                printf("Digite o elemento %dx%d da matriz 1\n",i,j);
                scanf("%d",&m1[i][j]);
                printf("\n");
            }
        }

        for(i=0;i<lin;i++){
            for(j=0;j<col;j++){
                printf("Digite o elemento %dx%d da matriz 2\n",i,j);
                scanf("%d",&m2[i][j]);
                printf("\n");
            }
        }

        arq = fopen(NOMEARQUIVO,"w");

        fprintf(arq,"%d\t%d\n",lin,col);

        for(i=0;i<lin;i++){
            for(j=0;j<col;j++){
                fprintf(arq,"%d\t",m1[i][j]);
            }
            fprintf(arq,"\n");
        }

        for(i=0;i<lin;i++){
            for(j=0;j<col;j++){
                fprintf(arq,"%d\t",m2[i][j]);
            }
            fprintf(arq,"\n");
        }

        SomaMatriz(m1,m2,mr,lin,col);

        ImprimeMatriz(mr,lin,col);


        for(i=0;i<lin;i++){
            free(m1[i]);
        }
        free(m1);

        for(i=0;i<lin;i++){
            free(m2[i]);
        }
        free(m2);

        for(i=0;i<lin;i++){
            free(mr[i]);
        }
        free(mr);

    }

    return 0;
}

void SomaMatriz(int **m1, int **m2, int **mr, int lin, int col){

    int i, j;

    for(i=0;i<lin;i++){
        for(j=0;j<col;j++){
           mr[i][j] = m1[i][j] + m2[i][j];
        }
    }

}

void ImprimeMatriz(int **m, int lin, int col){

    int i, j;

    for(i=0;i<lin;i++){
        for(j=0;j<col;j++){
           printf("%d\t",m[i][j]);
        }
    printf("\n");
    }

}
