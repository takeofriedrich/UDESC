#include <stdio.h>
#include <rpc/rpc.h>
#include "tools.h"

// Interface gerada pelo RPCGen a partir da IDL (hw.x) especificada
#include "hw.h"

int main(int argc, char *argv[])
{
	// Estrutura RPC de comunicação
	CLIENT *cl;

	// Parâmetros das funçcões
	char *par_f1 = (char *)malloc(256 * sizeof(char));
	int par_f2;
	struct envio par_f3;

	// Retorno das funções
	char **ret_f0 = NULL;
	int *ret_f1 = NULL;
	int *ret_f2 = NULL;
	int *ret_f3 = NULL;

		// Verificação dos parâmetros oriundos da console
	if (argc != 4)
	{
		printf("ERRO: ./client <hostname> <username> <filename>\n");
		exit(1);
	}

	// Conexão com servidor RPC
	cl = clnt_create(argv[1], PROG, VERS, "tcp");
	if (cl == NULL)
	{
		clnt_pcreateerror(argv[1]);
		exit(1);
	}

	FILE *fileread;
	char *msg = NULL;

	if (argc != 4)
	{
		printf("ERRO: ./main filename\n");
		exit(1);
	}

	fileread = fopen(argv[3], "r");
	if (fileread == NULL)
	{
		printf("Error: Na abertura dos arquivos (%s).", argv[3]);
		exit(1);
	}

	msg = readline(fileread);
	printf("[%s]\n", msg);

	fclose(fileread);

	char *data = wtime();
	par_f3.data = malloc(sizeof(char) * strlen(data) + 1);
	memcpy(par_f3.data, data, strlen(data) + 1);
	par_f3.nome = malloc(sizeof(char) * strlen(argv[2]) + 1);
	memcpy(par_f3.nome, argv[2], strlen(argv[2]) + 1);
	// par_f3.nome = argv[2];
	par_f3.texto = malloc(sizeof(char) * strlen(msg) + 1);
	memcpy(par_f3.texto, msg, strlen(msg) + 1);
	// ar_f3.texto = msg;

	ret_f3 = func3_1(&par_f3, cl);
	if (ret_f3 == NULL)
	{
		clnt_perror(cl, argv[1]);
		exit(1);
	}

	return 0;
}
