#include <rpc/rpc.h>

// Interface gerada pelo RPCGen a partir da IDL (hw.x) especificada
#include "hw.h"
#include "tools.h"

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
char **func0_1_svc(void *a, struct svc_req *req)
{
     static char msg[256];
     static char *p;

     printf("FUNC0 (sem parâmetros)\n");
     strcpy(msg, "Hello Func0!");
     p = msg;

     return (&p);
}

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
int *func1_1_svc(char **a, struct svc_req *req)
{
     static int ret = 1;

     printf("FUNC1 (%s)\n", *a);

     return (&ret);
}

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
int *func2_1_svc(int *a, struct svc_req *req)
{
     static int ret = 10;

     printf("FUNC2 (%d)\n", *a);
     return (&ret);
}
int incrementaContador()
{
     FILE *read = fopen("contador.txt", "r");
     int cont = 0;
     fscanf(read, "%d", &cont);
     fclose(read);

     FILE *write = fopen("contador.txt", "w");
     cont++;
     fprintf(write, "%d", cont);
     fclose(write);
     return cont;
}

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
int *func3_1_svc(struct envio *a, struct svc_req *req)
{
     static int ret = 0;

     int cont = incrementaContador();
     int soma = (strlen(a->data) + strlen(a->nome) + strlen(a->texto) + 20);
     char *buffer = malloc(sizeof(char) * soma);
     strcpy(buffer, "");
     char *c1 = strcat(buffer, a->data);
     char *c2 = strcat(c1, a->nome);

     char *barraN = malloc(sizeof(char) * 2);
     strcpy(barraN, "\n");

     char *c3 = strcat(c2, barraN);

     char *c4 = strcat(c3, a->texto);

     char *nome = malloc(sizeof(char) * 100);
     strcpy(nome, "");
     if (cont < 10)
     {
          sprintf(nome, "log0%d.txt", cont);
     }
     else
     {
          sprintf(nome, "log%d.txt", cont);
     }

     FILE *file = fopen(nome, "w+");

     writeline(c4, file);
     fclose(file);

     static int x = 12;
     return (&x);
}
