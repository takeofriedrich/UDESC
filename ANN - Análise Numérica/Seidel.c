#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define FOR(i,j) for(int i=0;i<j;i++)

double xn(double **a, double *b, double *s, int n, int m, int variavel){

    double novox = b[variavel];

    FOR(i,m){

        if(i==variavel)
            i++;

        novox-= a[variavel][i]*s[i];

    }

    novox *= 1/a[variavel][variavel];

    return novox;
}

int main(){

    double **a;
    double *b, *s;

    int n,m,k;

    printf("Digite a ordem da matriz dos coeficientes:\n");
    scanf("%d %d",&n,&m);

    a = (double**)calloc(n,sizeof(double*));

    FOR(i,n)
    a[i] = (double*)calloc(m,sizeof(double));

    b = (double*)calloc(n,sizeof(double));

    s = (double*)calloc(n,sizeof(double));

    printf("Digite a matriz dos coeficientes:\n");
    FOR(i,n){
        FOR(j,m){
            scanf("%lf",&a[i][j]);
        }
    }

    printf("Digite o vetor b:\n");
    FOR(i,n){
            scanf("%lf",&b[i]);
        }

    printf("Digite o vetor de estimativas iniciais:\n");
    FOR(i,n){
            scanf("%lf",&s[i]);
        }

    printf("Digite o numero de iteracoes:\n");
    scanf("%d",&k);

        // FAZ AS "K" ITERAÇÕES
        FOR(i,k){

		printf("Iteracao %d\n",i+1);

            // CRIAR UMA NOVA SOLUÇÃO PARA CADA VARIAVEL
            FOR(j,n){

                s[j] = xn(a,b,s,n,m,j);
		printf("X%d = %.5lf\n",j,s[j]);

            }

        }

    //printf("Para %d iteracoes, o vetor solucao assume:\n",k);
    //FOR(i,n){
    //    printf("%.4lf\n",s[i]);
    //}


    FOR(i,n)
    free(a[i]);
    free(a);
    free(b);
    free(s);

    return 0;
}
