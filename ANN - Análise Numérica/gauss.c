#include <stdio.h>
#include <stdlib.h>

int main(){

  double termo;
  double m;
  int n;

  printf("\nDigite a quantidade variáveis \n");
  scanf("%d",&n);

  double coeficientes[n][n+1]; // Matriz dos coeficientes
  double x[n]; // Vetor das soluções

  printf("\nDigite a matriz extendida \n");

  for(int i=0;i<n;i++){
    for(int j=0;j<n+1;j++){
      scanf("%lf",&coeficientes[i][j]);
    }

  }

  printf("\nMatriz antes do escalonamento:\n");

  for(int i=0;i<n;i++){

    for(int j=0;j<n+1;j++){
      printf("%lf",coeficientes[i][j]);

      if(j==n) printf("\n");
      else printf("\t");

    }



  }

  // FAZ O ESCALONAMENTO DA MATRIZ

  for(int i=0;i<n-1;i++){

    for(int j=i+1;j<n;j++){

      m = -1*(coeficientes[j][i] / coeficientes[i][i]);

      for(int k=0; k < n+1 ; k++){

        coeficientes[j][k] = (coeficientes[i][k] * m) + coeficientes[j][k];

      }

    }

    printf("\nMatriz atualizada:\n");

      for(int j=0; j<n; j++){

        for(int k=0; k<n+1; k++){

          printf("%.8lf", coeficientes[j][k]);

          if(k == n) printf("\n");
          else printf(" ");

        }
      }
    }

  // FIM DO METODO DE GAUSS

  // RESOLVENDO O SISTEMA

  int aux;
  int cont=0;

  for(int i=0;i<n;i++){

    termo = 0;
    aux = n-i;

    for(int j=aux; j<n; j++){

      termo += (x[j]*coeficientes[n-i-1][j]);

    }

    x[n-i-1]=(coeficientes[n-1-i][n]-termo)/coeficientes[n-i-1][n-i-1];


  }

  // FIM DA RESOLUÇÃO

  printf("\nVetor solução: \n");

  for(int i=0;i<n;i++){
    printf("x[%d] = %lf \n",i, x[i]);
  }


}
