#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#define ITERACOES 100
#define ERRO 0.0001

// Autor: Vinícius Takeo Friedrich Kuwaki

int r,k;

// Função que retorna o valor de uma função f, sendo f(x) do tipo f(x)= x^r - k
double f(double x){
	return (double)(pow(x,r) - k);
}

// Função que retorna o valor da primeira derivada de f', sendo f'(x) = r*(x^(r-1))
double f_linha(double x){
	return (double)(r*pow(x,r-1));
}

// Função que retorna o p da iteração seguinte, pela formula:
// Pn = Pn-1 - ( f(Pn-1) / f'(Pn-1) )
double next_p(double x){
    return x - (f(x)/f_linha(x));
}

int main(){

	double p;
	double p_anterior; // Variável auxiliar que armazena o valor calculado na iteração anterior

	printf("\nSeja uma função da forma x^r - k\n");
	printf("\nDigite r\n");
	scanf("%d",&r);
	printf("\nDigite k\n");
	scanf("%d",&k);

	printf("\nDigite uma estimativa inicial\n");
	scanf("%lf",&p);
	printf("\n");

	// O algoritmo se repete ITERACOES vezes, ou até que a condição do erro seja atendida
	for(int i=1;i<=ITERACOES;i++){

		printf("Iteracao: %d\n",i);
    printf("P%d = %.10lf\n",i,p);
    printf("f(P%d) = %.10lf\n",i,f(p));
    printf("f'(P%d) = %.10lf\n\n",i,f_linha(p));

		p_anterior = p; // Armazena o valor antigo de p em uma variável auxiliar
    p = next_p(p); // Calcula o novo valor de p

		// Se o módulo da diferença entre p e p_anterior for menor ou igual ao erro o algoritmo para
		if(fabs(p-p_anterior) <= ERRO){
			return 0;
		}

	}

	return 0;
}
