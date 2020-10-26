#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int semente;

int **CriaMatrizAdjacencia (int num_membros);
void DesalocaMatriz(int num_membros, int **matriz_adjacencia);
void ImprimeMatriz(int num_membros, int **matriz_adjacencia);
void MarcaComoAmigo (int pessoa1, int pessoa2, int **matriz_adjacencia);
float GeraNumeroAleatorio();
void GeraRedeSocialAleatoria( float p, int num_membros, int **matriz_adjacencia);
int numAmigosEmComum (int v, int u, int num_membros, int **matriz_adjacencia);
void LimpaTela();
float coeficienteAglomeracao (int v, int num_membros, int **matriz_adjacencia);

int main(){

    int i,j;

    int u,v;

    int num_membros;
    int **matriz_adjacencia;

    printf("Entre com o numero de membros da rede social:\n");
    scanf("%d",&num_membros);
    LimpaTela();

    printf("Entre com a semente que sera usada na geracao de numeros aleatorios:\n");
    scanf("%d",&semente);
    srand(semente);
    LimpaTela();

    matriz_adjacencia = CriaMatrizAdjacencia(num_membros);

    GeraRedeSocialAleatoria(GeraNumeroAleatorio(), num_membros, matriz_adjacencia);

    printf("\n");

    ImprimeMatriz(num_membros,matriz_adjacencia);

    printf("\n");
    for(i=0;i<num_membros;i++){
        for(j=i+1;j<num_membros;j++){
            printf("Numero de amigos em comum entre %d e %d eh: %d\n",i,j,numAmigosEmComum(i,j,num_membros,matriz_adjacencia));
        }
    }

    printf("\n");
    for(i=0;i<num_membros;i++)
        printf("A probabilidade de dois amigos de %d tambem serem amigos entre si eh de: %.2f\n",i,coeficienteAglomeracao(i,num_membros,matriz_adjacencia)*100);



    DesalocaMatriz(num_membros,matriz_adjacencia);
    system("pause");
    return 0;
}

int **CriaMatrizAdjacencia (int num_membros){

    int **matriz;
    int i,j;

    matriz = (int**)calloc(sizeof(int*),num_membros);
    for(i=0;i<num_membros;i++)
        matriz[i] = (int*)calloc(sizeof(int),num_membros);

    for(i=0;i<num_membros;i++)
        for(j=0;j<num_membros;j++)
            matriz[i][j] = 0;

    return matriz;
}

void DesalocaMatriz(int num_membros, int **matriz_adjacencia){

    int i;

    for(i=0;i<num_membros;i++)
        free(matriz_adjacencia[i]);

    free(matriz_adjacencia);

}

void ImprimeMatriz(int num_membros, int **matriz_adjacencia){

    int i,j;

    printf(" \t");
    for(i=0;i<num_membros;i++){
        printf("%d\t",i);
    }
    printf("\n\n");

    for(i=0;i<num_membros;i++){
        printf("%d\t",i);
        for(j=0;j<num_membros;j++){
            printf("%d\t",matriz_adjacencia[i][j]);
        }
        printf("\n\n");
    }

}

void MarcaComoAmigo (int pessoa1, int pessoa2, int **matriz_adjacencia){

    matriz_adjacencia[pessoa1][pessoa2] = 1;
    matriz_adjacencia[pessoa2][pessoa1] = 1;

}

float GeraNumeroAleatorio(){

    int numInt;
    float x;

    numInt = (rand()%100);
    x = (float)numInt / 100.00;

    return (x);
}

void GeraRedeSocialAleatoria( float p, int num_membros, int **matriz_adjacencia){

    int i,j;
    float r;

    for(i=0;i<num_membros-1;i++){
        for(j=i+1;j<num_membros;j++){
            r = GeraNumeroAleatorio();
            if( r < p )
                MarcaComoAmigo(i,j, matriz_adjacencia);
        }
    }
}

int numAmigosEmComum (int v, int u, int num_membros, int **matriz_adjacencia){

    int contadorAmigos = 0;
    int i;

    for( i=0;i<num_membros;i++ ){
        if( matriz_adjacencia[u][i] == 1 && matriz_adjacencia[v][i] == 1 ){
            contadorAmigos++;
        }
    }

    return contadorAmigos;

}

void LimpaTela(){
    system("CLS");
}

float coeficienteAglomeracao (int v, int num_membros, int **matriz_adjacencia){

    int amigosV = 0;
    int cont=0;
    float maxAmizades, contFloat;
    int i,j,k;
    int *vetorAuxiliar;


    for(i=0;i<num_membros;i++){
        if(i == v)
            i++;
        if(matriz_adjacencia[v][i] == 1){
            amigosV++;
        }
    }

    if(amigosV == 1 || amigosV == 0)
        return 0;

    vetorAuxiliar = (int*)calloc(sizeof(int),amigosV);

    for(i=0;i<num_membros;i++){
        if(i == v)
            i++;
        if(matriz_adjacencia[v][i] == 1){
            vetorAuxiliar[cont] = i;
            cont++;
        }
    }

    cont = 0;
    for( i=0; i<amigosV; i++){
        for( j=i+1; j<amigosV; j++){
            if(matriz_adjacencia[vetorAuxiliar[i]][vetorAuxiliar[j]] == 1){
                cont++;
            }
        }
    }

    maxAmizades = amigosV*(amigosV - 1)/2.0;
    contFloat = (float)cont;

    free(vetorAuxiliar);

    return contFloat / maxAmizades;

}
