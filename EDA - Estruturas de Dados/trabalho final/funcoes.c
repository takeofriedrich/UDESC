#include <stdio.h>
#include <string.h>

#define SIM 1
#define NAO 0

#define SUCESSO 1
#define FRACASSO 0

#define MAX 20

typedef struct 

struct Nodo{
    struct Nodo *proximo;
    info *palavra;
    int linha;
    int coluna;
};

struct Linha{
      struct Nodo *primeiro;
      struct Nodo *ultimo;
      struct Linha *acima;
      struct Linha *abaixo;
      int numeroPalavras;
};

typedef struct{
      struct Linha *primeira;
      struct Linha *ultima;
      int numeroLinhas;
}MultiLista;

char *criaString(int numeroLetras); // Retorna uma string do tamanho numeroDeLetras
struct Nodo *criaNodo(); // Retorna o nodo vazio
struct Linha *criaLinha(); // Retorna uma linha vazia
MultiLista *criaMultilista(); // Retorna uma multilista vazia

int multiListaVazia(MultiLista *m); // Retorna SIM ou NAO
int linhaVazia(struct Linha *l); // Retorna SIM ou NAO

FILE *abreArquivoLer(); // Retorna um arquivo aberto no modo "r"
void liberaArquivo(FILE *a); // Dá free no arquivo aberto

int numeroCaracteresString(char *palavra); // Retorna o numero de letras da string

                                            // FUNCOES MEIO PRONTAS

void inserePalavraMultilista(char *palavra, MultiLista *ml, int novaLinha); // Insere uma palavra na multilista, se novaLinha for igual a SIM ele insere em uma linha nova, se for igual a NAO ele insere na ultima linha 
//( BY TAKEO)

                                            // FUNCOES A FAZER

// QUESTAO A ( BY TAKEO)
void imprimeMultiLista(MultiLista *ml); // Imprime as palavras da multilista

// QUESTAO B ( BY DAN )
void buscaPalavra(MultiLista *ml, char *palavra); // Imprime a primeira aparição da palavra na multilista ( linha e coluna dela)

// QUESTAO C
void removePalavra(MultiLista *ml); // Remove a ultima palavra da multilista

// QUESTAO D
void removePalavraEspecifica (MultiLista *ml, int linha, int coluna); // Remove a palavra da linha e da coluna especifica

// QUESTAO E ( BY DAN )
int repeticaoPalavra(MultiLista *ml, char *palavra); // Retorna o numero de vezes que a palavra existe dentro da multilista

// QUESTAO F ( BY DAN)
int numeroPalavrasMultilista(MultiLista *ml); // Retorna o numero de palavras que existem na multilista

// QUESTAO G
void modificaPalavra(MultiLista *ml, int linha, int coluna); // Edita a palavra que está na linha e na coluna em específico

// QUESTAO I ( BY DAN)
void exibePalavrasCaracterEspecifico(MultiLista *ml, char c); // Printa todas as palavras que possuem esse caracter especifico e sua localização

// QUESTAO J


