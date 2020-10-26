#include "stdlib.h"
#include "stdio.h"
#include "string.h"
#include "math.h"

typedef struct arquivo
{
    char *nome;
    int *tam;
} arquivo;

void quick_sort(arquivo **array, int esq, int dir)
{
    // Função adaptada de: https://www.vivaolinux.com.br/script/Ordenacao-QuickSort

    int i = esq;
    int j = dir;

    int meio = (int)((i + j) / 2);

    arquivo *pivo = array[meio];
    arquivo *aux;

    do
    {
        while (*(array[i]->tam) < *(pivo->tam))
            i++;
        while (*(array[j]->tam) > *(pivo->tam))
            j--;

        if (i <= j)
        {
            aux = array[i];
            array[i] = array[j];
            array[j] = aux;
            i++;
            j--;
        }
    } while (j > i);

    if (esq < j)
    {
        quick_sort(array, esq, j);
    }

    if (i < dir)
    {
        quick_sort(array, i, dir);
    }
}

int main(int argc, char *argv[])
{

    if (argc < 2 || argc > 2)
    {
        printf("Muitos argumentos!\n");
        return 0;
    }

    FILE *arq = fopen(argv[1], "r");

    if (arq == NULL)
    {
        printf("Erro\n");
        return 0;
    }

    // Tamanho máximo de arquivo 256
    char *aux = malloc(sizeof(char) * 256);

    int *aux2 = malloc(sizeof(int *));

    int cont = 0;

    // Primeira passada pelo arquivo conta a quantidade de linhas, ignora os valores lidos!
    while (!feof(arq))
    {
        fscanf(arq, "%s %d", aux, aux2);
        cont++;
    }

    // A partir do contador aloca um array da estrutura arquivo (nome[256] e tamanho)
    arquivo **arquivos = malloc(sizeof(arquivo *) * cont);

    // Volta o ponteiro para o inicio do arquivo
    arq = fopen(argv[1], "r");

    int contadorZeros = 0;     // Variável que conta a quantidade de zeros
    unsigned long int sum = 0; // Variável que soma todos os bytes utilizados

    // Laço de repetição para alocar o array de arquivos e ler os valores do texto
    for (int i = 0; i < cont; i++)
    {
        arquivos[i] = (arquivo *)malloc(sizeof(arquivo));
        arquivos[i]->nome = (char *)malloc(sizeof(char) * 256);
        arquivos[i]->tam = (int *)malloc(sizeof(int));
        fscanf(arq, "%s %d", aux, aux2);
        memcpy(arquivos[i]->nome, aux, sizeof(char) * 256);
        memcpy(arquivos[i]->tam, aux2, sizeof(int));
    }

    fclose(arq);

    // Laço de repetição para contar a quantidade de arquivos que possuem tamanho 0 e calcular a quantidade de bytes total
    for (int i = 0; i < cont; i++)
    {
        if (*(arquivos[i]->tam) == 0)
        {
            contadorZeros++;
        }
        if (sum < 4294967295) // Soma até que estoure o tamanho da variável unsigned long int
        {
            sum += *(arquivos[i]->tam);
        }
    }

    // Ordenação do array
    quick_sort(arquivos, 0, cont - 1);

    // Calculo da média
    int media = (int)(sum / cont);

    printf("a) Número total de arquivos: %d\n", cont);

    // Como o array foi ordenado, peguei as informações da última posição
    printf("b) Maior arquivo: %s %d bytes\n", arquivos[cont - 1]->nome, *(arquivos[cont - 1]->tam));

    printf("c) Numero de arquivos com tamanho zero: %d\n", contadorZeros);

    printf("c) Porcentagem de arquivos com tamanho zero: %f%%\n", contadorZeros * 100.00 / cont);

    printf("d) Média de tamanho do arquivo: %d\n", media);

    // Para ver quantos arquivos estavam na média, defini uma tolerância, não sei uma boa métrica para isso
    // Gostaria que o professor comentasse alguma no feedback, mas para não ficar um valor absurdo peguei o tamanho do arquivo
    // Que representa uma "mediana de 5%", caso o professor deseje o pedido no enuciado é só descomentar a linha 142

    int contMenores = 0;
    int contIguais = 0;
    int contMaiores = 0;

    int tolerancia = *(arquivos[(int)(cont * 0.05)]->tam);
    //int tolerancia = 0;

    for (int i = 0; i < cont; i++)
    {
        if (*(arquivos[i]->tam) < media - tolerancia)
        {
            contMenores++;
        }
        else if (*(arquivos[i]->tam) > media + tolerancia)
        {
            contMaiores++;
        }
        else
        {
            contIguais++;
        }
    }

    printf("\tPara uma tolerancia de: %d\n", tolerancia);
    printf("d) Quantidade de arquivos menores que a média: %d\n", contMenores);
    printf("d) Quantidade de arquivos iguais a média: %d\n", contIguais);
    printf("d) Quantidade de arquivos maiores que a média: %d\n", contMaiores);

    int mediana = 0;

    // Mediana possui duas possibilidades:
    // |arquivos| = par => faz a média dos dois elementos centrais
    // |arquivos| = impar => elemento central é a mediana

    if (cont % 2 == 0)
    {
        mediana += *(arquivos[cont / 2]->tam);
        mediana += *(arquivos[(cont / 2) - 1]->tam);
        mediana /= 2;
    }
    else
    {
        mediana = *(arquivos[(int)(cont / 2)]->tam);
    }

    printf("e) Mediana de tamanho do arquivo: %d\n", mediana);

    // Para a questão f, peguei o arquivo do meio
    int tamanhoArquivoMeio = *(arquivos[cont / 2]->tam);

    printf("\tTamanho do meio: %d\n", tamanhoArquivoMeio);

    // Para analisar se ele pertence a base 2, tirei o log 2 e analisei se tal valor é exato (sem casas decimais)
    // Se sim significa que esse tamanho de bloco é suficiente para 50% dos arquivos caberem
    // Se não é necessário pegar a parte exata desse log2, somar 1 e fazer 2 elevado a esse valor

    float log2Soman = log2(tamanhoArquivoMeio);

    unsigned long tamanho = 0;

    if (log2Soman / (int)(log2Soman) > 1)
    {
        tamanho = pow(2, (int)(log2Soman) + 1);
    }
    else
    {
        tamanho = tamanhoArquivoMeio;
    }

    printf("f) Menor tamanho de bloco: %ld\n", tamanho);

    int contCabemBloco = 0;

    for (int i = 0; i < cont; i++)
    {
        if (*(arquivos[i]->tam) <= tamanho)
        {
            contCabemBloco++;
        }
    }

    printf("f) Porcentagem de arquivos que caberiam nesse bloco: %f%%\n", contCabemBloco * 100.00 / cont);

    int qntBlocos = 0;

    if (*(arquivos[cont - 1]->tam) % tamanho == 0)
    {
        qntBlocos = *(arquivos[cont - 1]->tam) / tamanho;
    }
    else
    {
        qntBlocos = (*(arquivos[cont - 1]->tam) / tamanho) + 1;
    }

    printf("f) Maior arquivo ocuparia: %d blocos\n", qntBlocos);

    // Contadores para analisar quantos precisam

    int contSemInd = 0;
    int contIndSim = 0;
    int contIndDup = 0;
    int contIndTri = 0;

    for (int i = 0; i < cont; i++)
    {
        if (*(arquivos[i]->tam) <= 49152) // 12 ponteiros diretos
        {
            contSemInd++;
        }
        else if (*(arquivos[i]->tam) <= 4243456) // 12 ponteiros diretos mais 1024 ponteiros indiretos
        {
            contIndSim++;
        }
        else if (*(arquivos[i]->tam) <= 18225504742014976) // 12 ponteiros diretos mais 1048576 ponteiros indiretos
        {
            contIndDup++;
        }
        else // 12 ponteiros diretos mais 1024*1024*1024 ponteiros indiretos, não considerei mais um caso porque acho que o meu computador não suportaria
        {
            contIndTri++;
        }
    }

    printf("\tArquivos sem indireção: %d\n", contSemInd);
    printf("\tArquivos com indireção simples: %d\n", contIndSim);
    printf("\tArquivos com indireção dupla: %d\n", contIndDup);
    printf("\tArquivos com indireção tripla: %d\n", contIndTri);

    printf("g) Porcentagem de arquivos sem indireção: %f%%\n", contSemInd * 100.00 / cont);
    printf("g) Porcentagem de arquivos com indireção simples: %f%%\n", contIndSim * 100.00 / cont);
    printf("g) Porcentagem de arquivos com indireção dupla: %f%%\n", contIndDup * 100.00 / cont);
    printf("g) Porcentagem de arquivos com indireção tripla: %f%%\n", contIndTri * 100.00 / cont);

    unsigned long int desperdicio = 0;

    // Para calcular o desperdicio, como o tamanho do meu bloco é 4096 (coincidentemente o mesmo valor da letra f)
    // basta ir acumulando o resto da divisão por esse valor

    for (int i = 0; i < cont; i++)
    {

        if (*(arquivos[i]->tam) % 4096 != 0)
        {
            desperdicio += *(arquivos[i]->tam) % 4096;
        }
    }

    printf("h) Quantidade de bytes desperdiçado: %ld bytes\n", desperdicio);
    printf("h) Porcentagem de bytes desperdiçado: %f%%\n", desperdicio * 100.00 / sum);

    free(aux);
    free(aux2);

    for (int i = 0; i < cont; i++)
    {
        free(arquivos[i]->nome);
        free(arquivos[i]->tam);
        free(arquivos[i]);
    }
    free(arquivos);

    
    return 0;
}