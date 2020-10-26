#include <stdio.h>
#include <stdlib.h>
int main()
{
int n=0;
printf("----------------------------------------------------------------------\nPrograma simples para resolver sistema pelo metodo de Gauss\nComputacao Cientifica - Eng. Eletronica\nAluno: Diego Rodrigues Ferreira \n----------------------------------------------------------------------\n\n\nDigite o numero de variaveis do sistema:\n");
scanf("%d",&n);
float A[n][n+1];
float x[n];
float termo;
int i;
int j;
int k;
int l;
float m;
	printf("Digite os valores dos coficientes e termos independentes do sistema\n");
		for (i=0; i<n;i++){
		for (j=0; j<n+1; j++){
	printf("Valor do termo A(%d,%d)\n",i+1,j+1);
	scanf("%f",&A[i][j]);
		printf ("\nValor termo A(%d,%d)=%f\n",i+1,j+1,A[i][j]);
					}
				}
	printf("\nMatriz A:\n\n");
		for(i=0; i<n; i++) {
		for (j=0;j<n+1;j++){
			printf ("%f",A[i][j]);
		if(j==n) printf("\n");
		else printf("\t");
					}
				}
/*Implementando Método de Gauss*/
		for (k=0;k<n-1;k++){
		for (i=k+1; i<n;i++){
/*Multiplicadores*/
		m=-1*(A[i][k]/A[k][k]);
			for (j=0;j<n+1;j++){
		A[i][j]=(A[k][j]*m)+A[i][j];
						}
					}
	printf("\nMatriz A Transformada em Gauss:\n\n");
		for(i=0; i<n; i++) {
		for (j=0;j<n+1;j++){
	printf ("%f",A[i][j]);
		if(j==n) printf("\n");
		else printf("\t");
					}
						}
					}
/*Resolvendo o sistema*/
	for (i=0;i<n;i++){
		termo=0;
		l=n-i;
	for (j=l; j<n;j++){
	termo=termo+(x[j]*A[n-i-1][j]);
					}
	printf ("\ntermo=%f\n",termo);
		x[n-i-1]=(A[n-1-i][n]-termo)/A[n-i-1][n-i-1];
	printf ("\nVariavel:\nx%d=%13.2f\n",n-i,x[n-i-1]);
					}
return 0;
}
