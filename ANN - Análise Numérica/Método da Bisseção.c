#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#define ITERACOES 100
#define ERRO 0.0001

// Autor: Vinícius Takeo Friedrich Kuwaki

/* Calcula o valor de f(x), sendo f(x) = x^r - k
*/
double f(int r, int k, double x){
	return (double)(pow(x,r) - k);
}

/* Calcula o valor do ponto médio do intervalo
*/
double valor_n(double a, double b){

	return (a+b)/2.0;
}

int main(){

	int r; // Expoente da f(x)
	int k; // Constante da f(x)


	// Intervalo [a,n,b], sendo a e b os extremos e n o ponto médio
	double n;
	double a;
	double b;

	// Valores de f(a), f(b) e f(n)
	double f_a;
	double f_b;
	double f_n;

	printf("Seja uma função na forma x^r - k \n");

	printf("Digite r\n");
	scanf("%d",&r);

	printf("Digite k\n");
	scanf("%d",&k);

	printf("Digite um intervalo [a,b]\n");
	scanf("%lf %lf",&a,&b);

	// Calcula o valor médio do intervalo dado pelo usuário
	n = valor_n(a,b);

  if( f(r,k,a) == 0  ){

			// Se o ponto a for raiz da função o algoritmo para
			printf("---> Raiz final: %lf\n",a);

	}else{
		// Se o ponto b for raiz da função o algoritmo para
		if( f(r,k,b) == 0  ){

			printf("---> Raiz final: %lf\n",b);

		}else{ // Se nenhum dos extremos forem raizes, então o algoritmo irá procurar uma aproximação para a raiz

			// Enquanto
			for(int i=1;i<=ITERACOES;i++){ // O algoritmo se repetirá ITERACOES vezes

					printf("\nIteracao %d:\n",i);

					// Calcula o valor médio do novo intervalo
					n = valor_n(a,b);

					// Calcula os valores de f(a), f(b) e f(n)
					f_a = f(r,k,a);
					f_b = f(r,k,b);
					f_n = f(r,k,n);

					printf("a%d = %.15lf\n",i,a);
					printf("n%d = %.15lf\n",i,n);
					printf("b%d = %.15lf\n",i,b);
					printf("f(a%d) = %.15lf\n",i,f_a);
					printf("f(n%d) = %.15lf\n",i,f_n);
					printf("f(b%d) = %.15lf\n",i,f_b);

					// Se o modulo do intervalo for menor ou igual ao erro ou o modulo de f no ponto médio for menor ou igual ao erro o algoritmo para
					if( fabs((b-a))<= ERRO || fabs(f_n)<= ERRO){
						return 0;
					}

					// Pelo teorema de bolzano, se o intervalo [a,n], sendo n o ponto médio, possuir uma raiz dentro dele, então o intervalo da proxima iteraçao é [a,n]
					if( f(r,k,a)*f(r,k,n) < 0){
						b=n;
					}

					// Pelo teorema de bolzano, se o intervalo [n,b], sendo n o ponto médio, possuir uma raiz dentro dele, então o intervalo da proxima iteraçao é [n,b]
					if( f(r,k,n)*f(r,k,b) < 0){
						a=n;
					}

				}

			}



      }
			return 0;
}
