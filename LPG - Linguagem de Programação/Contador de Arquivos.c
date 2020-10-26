#include <stdlib.h>
#include <stdio.h>

int main(){
    char prod [30];
    int qtd, valor, total =0;

    FILE *f;
    int cont=0;
    if ((f =fopen("C:\\temp\\ArqGrav.txt","r") == NULL))
        {
        printf ("O arquivo nao pode ser aberto");
        return (1);
        }
    else {
            printf("Teste\n");
        while (cont<=6){
            fscanf (f,"%s %d %d",prod,&qtd,&valor);
            total = total + qtd*valor;
            cont++;
            }
        printf ("total= %d\n",total);
        int fclose (FILE *f);
        system ("pause");
         }
return 0;
}
