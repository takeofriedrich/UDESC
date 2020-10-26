#include <stdlib.h>
#include <stdio.h>
#include "lista.h"

typedef struct reqs
{
    list *iniciais;
    list *quantidades;
    list *operacoes;
} requisicoes;

void quick_sort(requisicoes *reqs, int esq, int dir);

void adiciona(requisicoes *req, int *aux1, int *aux2, char *aux3);

void fundiFinal(requisicoes *req);

int main()
{

    int *aux1 = malloc(sizeof(int));
    *aux1 = 0;
    int *aux2 = malloc(sizeof(int));
    *aux2 = 0;
    char *aux3 = malloc(sizeof(char));
    *aux3 = 0;

    requisicoes *req = malloc(sizeof(requisicoes));

    req->iniciais = list_create(sizeof(int));
    req->quantidades = list_create(sizeof(int));
    req->operacoes = list_create(sizeof(char));

    int esq = 0;
    int dir = 0;

    char flag = 0;

    while (1)
    {

        scanf("%d", aux1); // inicial
        if (*aux1 == -1)
            break;
        scanf("%d %c", aux2, aux3); // tamanho e tipo

        adiciona(req, aux1, aux2, aux3); // adiciona fundindo requisições
    }

    quick_sort(req, 0, req->iniciais->tam - 1); // ordena a lista

    fundiFinal(req); // realiza a fundição final

    for (int i = 0; i < req->iniciais->tam; i++)
    {
        printf("%d %d %c\n", *((int *)(elementAt(req->iniciais, i))), *((int *)(elementAt(req->quantidades, i))), *((char *)(elementAt(req->operacoes, i))));
    }

    list_destroy(req->iniciais);
    list_destroy(req->quantidades);
    list_destroy(req->operacoes);

    free(req);

    free(aux1);
    free(aux2);
    free(aux3);

    return 0;
}

void adiciona(requisicoes *req, int *aux1, int *aux2, char *aux3)
{
    int flag = 0;

    for (int i = 0; i < req->iniciais->tam; i++)
    {
        int inicial = *((int *)(elementAt(req->iniciais, i)));
        int tamanho = *((int *)(elementAt(req->quantidades, i)));
        char tipo = *((char *)(elementAt(req->operacoes, i)));

        if (tipo != *aux3) // w == w  | r == r
            continue;

        // se a requisição que entrou esta dentro do intervalo e não ultrapassa 64, pode fundir apenas o tamanho
        if (*aux1 >= inicial && *aux1 <= (inicial - 1 + tamanho) && inicial + *aux2 < inicial + 64)
        {
            replaceAt(req->quantidades, i, &tamanho);
            flag = 1;
            break;
        }
        else if (inicial == *aux1 + *aux2 && *aux1 + tamanho + *aux2 < *aux1 + 64)
        {
            // mas se for o caso de a nova requisição estiver antes do intervalo, realiza a uniao
            flag = 1;
            int val = tamanho + *aux2;
            replaceAt(req->iniciais, i, aux1);
            replaceAt(req->quantidades, i, &val);
            break;
        }
    }

    // se não teve fundição, apenas junta ela na lista
    if (flag == 0)
    {
        push(req->iniciais, aux1, req->iniciais->tam);
        push(req->quantidades, aux2, req->quantidades->tam);
        push(req->operacoes, aux3, req->operacoes->tam);
    }
}

// mesma ideia da função anterior, entretanto apenas elimina requisições não necessárias
void fundiFinal(requisicoes *req)
{

    int *aux1 = malloc(sizeof(int));
    *aux1 = 0;
    int *aux2 = malloc(sizeof(int));
    *aux2 = 0;
    char *aux3 = malloc(sizeof(char));
    *aux3 = 0;
    int flag = 0;

    int j = 0;

    while (j != req->iniciais->tam)
    {

        aux1 = ((int *)(elementAt(req->iniciais, j)));
        aux2 = ((int *)(elementAt(req->quantidades, j)));
        aux3 = ((char *)(elementAt(req->operacoes, j)));

        for (int i = 0; i < req->iniciais->tam; i++)
        {
            if (i == j)
                continue;

            int inicial = *((int *)(elementAt(req->iniciais, i)));
            int tamanho = *((int *)(elementAt(req->quantidades, i)));
            char tipo = *((char *)(elementAt(req->operacoes, i)));

            if (tipo != *aux3)
                continue;

            if (*aux1 >= inicial && *aux1 <= (inicial - 1 + tamanho) && inicial + *aux2 < inicial + 64)
            {
                tamanho += *aux2;
                replaceAt(req->quantidades, i, &tamanho);
                flag = 1;
                pop(req->iniciais, j);
                pop(req->quantidades, j);
                pop(req->operacoes, j);
                break;
            }
            else if (inicial == *aux1 + *aux2 && *aux1 + tamanho + *aux2 < *aux1 + 64)
            {
                flag = 1;
                int val = tamanho + *aux2;
                replaceAt(req->iniciais, i, aux1);
                replaceAt(req->quantidades, i, &val);
                pop(req->iniciais, j);
                pop(req->quantidades, j);
                pop(req->operacoes, j);
                break;
            }
        }
        j++;
    }
}

void quick_sort(requisicoes *reqs, int esq, int dir)
{
    // Função adaptada de: https://www.vivaolinux.com.br/script/Ordenacao-QuickSort

    int i = esq;
    int j = dir;

    int meio = (int)((i + j) / 2);

    int pivo = *((int *)(elementAt(reqs->iniciais, meio)));
    int aux;

    int aux2;
    char aux3;

    do
    {
        while (*((int *)(elementAt(reqs->iniciais, i))) < pivo)
            i++;
        while (*((int *)(elementAt(reqs->iniciais, j))) > pivo)
            j--;

        if (i <= j)
        {

            aux = *((int *)(elementAt(reqs->iniciais, i)));
            aux2 = *((int *)(elementAt(reqs->quantidades, i)));
            aux3 = *((int *)(elementAt(reqs->operacoes, i)));

            replaceAt(reqs->iniciais, i, elementAt(reqs->iniciais, j));
            replaceAt(reqs->quantidades, i, elementAt(reqs->quantidades, j));
            replaceAt(reqs->operacoes, i, elementAt(reqs->operacoes, j));

            replaceAt(reqs->iniciais, j, (int *)(&aux));
            replaceAt(reqs->quantidades, j, (int *)(&aux2));
            replaceAt(reqs->operacoes, j, (int *)(&aux3));

            i++;
            j--;
        }
    } while (j > i);

    if (esq < j)
    {
        quick_sort(reqs, esq, j);
    }

    if (i < dir)
    {
        quick_sort(reqs, i, dir);
    }
}