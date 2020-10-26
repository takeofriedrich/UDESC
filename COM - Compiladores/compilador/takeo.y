%{

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "lista.h"
#include <string.h>

list *variaveis;
list *tipos;

list *parametros;

int quantidadeParametros = 0;

int whileAtivo = 0;

int labels = 10;
int fors = 10;
int whiles = 10;

int inFunc = 0;

extern int yylex();
extern int yyparse();
extern FILE* yyin;
extern FILE *yyout;
FILE *selecoes;

void *imprimeString(void *data);
void *imprimeInteiro(void *data);
void imprimeBefore();
void imprimeAfter();
void read();
void empilhaPrint(char *c);
void writeOutput(char *s);
void yyerror(const char* s);
void imprimeFimMain();

void somaIdentValor(char *ident, int valor);
void atribuiInteiro(char *nome, int valor);
void atribuiPilha(char *nome);
char* itoa(int val);

void imprimeValor(char *identificador);
int idIdentificador(char *identificador);

void leValor(char *identificador);

void somaInteiroInteiro(int a, int b);
void criaVariavel(char *identificador);

void somaVarVar(char *identificador1, char *identificador2);
void atribuicaoSoma(char *identificador);

void novoInteiroSemInicializacao(char *identificador);

void ifIdentIgualInteiro(char *identificador, int valor);
void ifIdentMenorInteiro(char *identificador, int valor);

void volta();
void voltaWhile();

void desvioElse();

int invocaFor(char *identificador, int inicial);
void finalizaFor(int idIdentificador, int limitante, int passo);

void invocaWhile();
void finalizaWhile();

void criaFuncao(int tipo, char *nome);
void finalizaFuncao(int tipo);
void adicionaParametro(int tipo,char *nome);

void preparaParaChamarFuncao(char *nome);
void preparaParaChamarFuncao2(int valor);

void chamaFuncaoAtribuindo(char *identificador, char *nome);

%}


%union {
	int ival;
	float fval;
	char *str;
}

/* Declaração dos tokens... */

%token<ival> T_INT
%token<fval> T_REAL
%token<ival> T_BOOL
%token<str> T_IDENT
%token<str> T_LITERAL
%token<str> T_STR
%token<ival> T_TRUE
%token<ival> T_FALSE 

%token T_END_LINE T_DOIS_PONTOS T_VIRGULA
%token T_STRING_TIPO T_BOOL_TIPO T_INT_TIPO T_REAL_TIPO
%token T_MAIN T_RETURN
%token T_IF T_WHILE T_FOR
%token T_PRINT
%token T_READ


%left T_PLUS T_MINUS
%left T_MULTIPLY T_DIVIDE
%left T_APPEND
%left T_PAR_LEFT T_CHA_LEFT 
%left T_PAR_RIGHT T_COL_RIGHT T_CHA_RIGHT

%left T_EQQ T_LESS T_MORE T_EQUAL
%left T_OR T_AND

%type<str> string
%type<ival> repeticao_label
%type<str> novo_inteiro
%type<ival> tipo
%type<str> chamada_funcao


%start inicial

%nonassoc T_COL_LEFT

%nonassoc T_THEN1
%nonassoc T_THEN2
%nonassoc T_ELSE

%nonassoc T_IDENT
%nonassoc T_PREC_STR
%nonassoc T_RET


%%

inicial: global main   			
		| main   				
		| main funcao			
		| global main funcao    
		;						

global: identificadores				
		|  global identificadores	
		;

main: tipo T_MAIN T_PAR_LEFT parametros T_PAR_RIGHT T_CHA_LEFT escopo retorno T_CHA_RIGHT {imprimeFimMain();}
	;

tipo: T_INT_TIPO			{$$=1;}
	| T_BOOL_TIPO			{$$=2;}
	| T_REAL_TIPO			{$$=3;}
	| T_STRING_TIPO			{$$=4;}
	;

parametros: tipo T_IDENT							{adicionaParametro($1,$2);}
	| tipo T_IDENT T_VIRGULA parametros				{adicionaParametro($1,$2);}
	| 
	;

parametros_chamada: T_IDENT							{preparaParaChamarFuncao($1);}
	| T_IDENT T_VIRGULA parametros_chamada			{preparaParaChamarFuncao($1);}
	| T_INT											{preparaParaChamarFuncao2($1);}
	| T_INT T_VIRGULA parametros_chamada			{preparaParaChamarFuncao2($1);}
	| 
	;

funcao: tipo T_IDENT T_PAR_LEFT parametros T_PAR_RIGHT T_CHA_LEFT {criaFuncao($1,$2);} escopo {finalizaFuncao($1);} T_CHA_RIGHT	
	;

chamada_funcao: T_IDENT T_PAR_LEFT parametros_chamada T_PAR_RIGHT			{$$=$1;}
			;

escopo: identificadores
	| escopo identificadores 
	| chamada_funcao
	| escopo chamada_funcao
	| repeticao_varias_linhas
	| escopo repeticao_varias_linhas 
	| repeticao_uma_linha
	| escopo repeticao_uma_linha
	| selecao_varias_linhas					
	| escopo selecao_varias_linhas 			
	| selecao_uma_linha
	| escopo selecao_uma_linha
	| io									
	| escopo io 
	| operacao
	| escopo operacao 
	| retorno
	;

comando_unico: selecao_uma_linha
	| repeticao_uma_linha        
	| io
	| operacao
	;

retorno: T_RETURN T_IDENT T_END_LINE 
		| T_RETURN T_IDENT T_COL_LEFT T_INT T_CHA_RIGHT T_END_LINE %prec T_RET
		| T_RETURN operacao
		;

identificadores: identificador_inteiro
				| identificador_float
				| identificador_bool
				| identificador_string
				;

identificador_inteiro: novo_inteiro T_END_LINE																					
					| novo_inteiro T_EQUAL T_INT T_END_LINE										{atribuiInteiro($1,$3);}
					| novo_inteiro T_EQUAL operacao_inteira T_END_LINE							{atribuiPilha($1);}
					| novo_inteiro T_EQUAL chamada_funcao T_END_LINE							{chamaFuncaoAtribuindo($1,$3);}
					| novo_inteiro T_EQUAL T_MINUS T_INT T_END_LINE												
					| novo_inteiro T_COL_LEFT T_INT T_COL_RIGHT T_END_LINE									
					| novo_inteiro T_COL_LEFT T_INT T_COL_RIGHT T_DOIS_PONTOS valores_vetor_int T_END_LINE	
					| T_IDENT T_EQUAL T_INT T_END_LINE		
					| T_IDENT T_EQUAL chamada_funcao T_END_LINE	 								{chamaFuncaoAtribuindo($1,$3);}									
					| T_IDENT T_EQUAL operacao_inteira T_END_LINE								{atribuicaoSoma($1);}
					| T_IDENT T_COL_LEFT T_INT T_COL_RIGHT T_EQUAL T_INT T_END_LINE
					| T_IDENT T_COL_LEFT T_IDENT T_COL_RIGHT T_EQUAL T_INT T_END_LINE
					| T_IDENT T_COL_LEFT T_IDENT T_COL_RIGHT T_EQUAL chamada_funcao T_END_LINE
					;

novo_inteiro: T_INT_TIPO T_IDENT {novoInteiroSemInicializacao($2); $$ = $2;}
			;

valores_vetor_int: T_INT
				 | T_INT valores_vetor_int
				 ;

identificador_float: T_REAL_TIPO T_IDENT T_END_LINE
					| T_REAL_TIPO T_IDENT T_EQUAL T_REAL T_END_LINE
					| T_REAL_TIPO T_IDENT T_EQUAL T_MINUS T_REAL T_END_LINE
					| T_REAL_TIPO T_IDENT T_COL_LEFT T_INT T_COL_RIGHT T_END_LINE
					| T_REAL_TIPO T_IDENT T_COL_LEFT T_INT T_COL_RIGHT T_DOIS_PONTOS valores_vetor_float T_END_LINE
					| T_IDENT T_EQUAL T_REAL T_END_LINE
					;

valores_vetor_float: T_REAL
				   | T_REAL valores_vetor_float
					;

identificador_string: T_STRING_TIPO T_IDENT T_END_LINE
					| T_STRING_TIPO T_IDENT T_EQUAL T_LITERAL T_END_LINE
					| T_STRING_TIPO T_IDENT T_EQUAL T_STR T_END_LINE
					| T_STRING_TIPO T_IDENT T_COL_LEFT T_INT T_COL_RIGHT T_END_LINE
					| T_IDENT T_EQUAL operacao_string T_END_LINE
					| T_STRING_TIPO T_IDENT T_COL_LEFT T_INT T_COL_RIGHT T_DOIS_PONTOS valores_vetor_string T_END_LINE
					| T_IDENT T_EQUAL string T_END_LINE
					;

valores_vetor_string: string
					| T_STR valores_vetor_string
					;

string: T_LITERAL 				{$$ = $1;}
	//   | T_IDENT 				{$$ = $1;}
	  ;

identificador_bool: T_BOOL_TIPO T_IDENT T_END_LINE
					| T_BOOL_TIPO T_IDENT T_EQUAL booleano T_END_LINE
					| T_BOOL_TIPO T_IDENT T_COL_LEFT T_INT T_COL_RIGHT T_END_LINE
					| T_BOOL_TIPO T_IDENT T_COL_LEFT T_INT T_COL_RIGHT T_DOIS_PONTOS valores_vetor_bool T_END_LINE
					| T_IDENT T_EQUAL T_INT
					;

valores_vetor_bool: booleano valores_vetor_float
				;

booleano: T_INT
		| T_FALSE
		| T_TRUE
		;

repeticao_uma_linha:  while_init T_PAR_LEFT operacao_logica_label T_PAR_RIGHT T_DOIS_PONTOS comando_unico
				   | T_FOR T_PAR_LEFT tipo repeticao_label T_VIRGULA T_INT T_VIRGULA T_INT T_PAR_RIGHT T_DOIS_PONTOS comando_unico
				   | T_FOR T_PAR_LEFT repeticao_label T_VIRGULA T_INT T_VIRGULA T_INT T_PAR_RIGHT T_DOIS_PONTOS comando_unico
				   ;

repeticao_varias_linhas: while_init T_PAR_LEFT operacao_logica_label T_PAR_RIGHT T_DOIS_PONTOS T_CHA_LEFT escopo T_CHA_RIGHT		{finalizaWhile();}
				   | T_FOR T_PAR_LEFT tipo repeticao_label T_VIRGULA T_INT T_VIRGULA T_INT T_PAR_RIGHT T_DOIS_PONTOS T_CHA_LEFT escopo T_CHA_RIGHT
				   | T_FOR T_PAR_LEFT repeticao_label T_VIRGULA T_INT T_VIRGULA T_INT T_PAR_RIGHT T_DOIS_PONTOS T_CHA_LEFT escopo T_CHA_RIGHT		{finalizaFor($3,$5,$7);}		
				   ;

repeticao_label: T_IDENT T_DOIS_PONTOS T_INT {$$=invocaFor($1,$3);}
				;

while_init: {invocaWhile();} T_WHILE
			;

selecao_uma_linha: T_IF T_PAR_LEFT operacao_logica_label T_PAR_RIGHT T_DOIS_PONTOS comando_unico %prec T_THEN1								
				| T_IF T_PAR_LEFT operacao_logica_label T_PAR_RIGHT T_DOIS_PONTOS comando_unico else										
				;

selecao_varias_linhas: T_IF T_PAR_LEFT operacao_logica_label T_PAR_RIGHT T_DOIS_PONTOS T_CHA_LEFT escopo T_CHA_RIGHT %prec T_THEN2			{volta();}
				| T_IF T_PAR_LEFT operacao_logica_label T_PAR_RIGHT T_DOIS_PONTOS T_CHA_LEFT escopo T_CHA_RIGHT  else						
				;

else: T_ELSE T_DOIS_PONTOS comando_unico
	| T_ELSE T_DOIS_PONTOS {desvioElse();} T_CHA_LEFT escopo T_CHA_RIGHT {volta();}
	;

operacao_logica_label: operacao_logica {}
					;

io: entrada
	| saida
	;

entrada: T_READ T_IDENT T_COL_LEFT T_INT T_COL_RIGHT T_END_LINE 
		| T_READ T_IDENT T_END_LINE														{leValor($2);}
		;

saida: T_PRINT {imprimeBefore();} argumentos_print {imprimeAfter();} T_END_LINE							
	| T_PRINT T_IDENT T_COL_LEFT T_INT T_COL_RIGHT T_END_LINE 
	| T_PRINT T_IDENT T_END_LINE														{imprimeValor($2);}
	;

argumentos_print: string								{empilhaPrint($1);}
				| string argumentos_print				{empilhaPrint($1);}
				| T_VIRGULA string						{empilhaPrint($2);}
				;

operacao: operacao_inteira T_END_LINE
		| T_INT T_END_LINE
		| operacao_logica T_END_LINE
		| operacao_real T_END_LINE
		| operacao_string T_END_LINE
		| T_LITERAL T_END_LINE
		;

operacao_inteira: T_IDENT T_PLUS T_IDENT								{somaVarVar($1,$3);}
				| T_INT T_PLUS T_INT									{somaInteiroInteiro($1,$3);}
				| T_INT T_PLUS T_IDENT 									{somaIdentValor($3,$1);}
				| T_IDENT T_PLUS T_INT									{somaIdentValor($1,$3);}	
				| operacao_inteira T_MINUS operacao_inteira
				| operacao_inteira T_MINUS T_IDENT
				| T_IDENT T_MINUS operacao_inteira
				| T_IDENT T_MINUS T_IDENT
				| operacao_inteira T_MULTIPLY operacao_inteira
				| operacao_inteira T_MULTIPLY T_IDENT
				| T_IDENT T_MULTIPLY operacao_inteira
				| T_IDENT T_MULTIPLY T_IDENT
				| T_PAR_LEFT operacao_inteira T_PAR_RIGHT
				;

operacao_real: T_REAL
			| operacao_real T_PLUS operacao_real
			| operacao_real T_MINUS operacao_real
			| operacao_real T_MULTIPLY operacao_real
			| operacao_real T_DIVIDE operacao_real
			| operacao_inteira T_PLUS operacao_real
			| operacao_inteira T_LESS operacao_real
			| operacao_inteira T_MULTIPLY operacao_real
			| operacao_inteira T_DIVIDE operacao_real
			| operacao_real T_PLUS operacao_inteira
			| operacao_real T_MINUS operacao_inteira
			| operacao_real T_MULTIPLY operacao_inteira
			| operacao_real T_DIVIDE operacao_inteira
			| T_PAR_LEFT operacao_real T_PAR_RIGHT
			| operacao_inteira T_DIVIDE operacao_inteira
			;

operacao_logica:  T_TRUE
				| T_FALSE
				| operacao_logica T_OR operacao_logica
				| T_IDENT T_OR operacao_logica
				| operacao_logica T_AND operacao_logica
				| operacao_logica T_MORE operacao_logica
				| T_IDENT T_MORE operacao_logica
				| T_IDENT T_MORE T_INT
				| operacao_logica T_LESS operacao_logica
				| T_IDENT T_LESS operacao_logica
				| T_IDENT T_LESS T_INT									{ifIdentMenorInteiro($1,$3);}
				| operacao_logica T_EQQ operacao_logica
				| T_IDENT T_EQQ operacao_logica
				| T_IDENT T_EQQ T_INT									{ifIdentIgualInteiro($1,$3);}

operacao_string: T_IDENT T_APPEND T_LITERAL // a append "..."
				| T_LITERAL T_APPEND T_IDENT // "..." append a
				| T_LITERAL T_APPEND T_LITERAL
				;

%%

int main(int argc, char *argv[])
{
    ++argv, --argc;
	char ch;
	if ( argc > 0 ){
		yyin = fopen(argv[0], "r" );
	}
	else{
		yyin = stdin;
	}

	yyout = fopen("out.j","w");
	FILE *model = fopen("jasmin/model.j","r");
	
	if (yyout == NULL || model == NULL ){
		printf("Falha durante a compilação");
	}

	while ((ch = fgetc(model)) != EOF)
      fputc(ch, yyout);

	variaveis = list_create(sizeof(char) * 20);
	tipos = list_create(sizeof(int));

	parametros = list_create(sizeof(int));

	do {
		yyparse();
	} while(!feof(yyin));

	list_destroy(variaveis);
	list_destroy(tipos);

	list_destroy(parametros);

	fclose(model);
	fclose(yyout);

	printf("Compilado com sucesso!\n");

	return 0;
}


void imprimeFimMain(){
	writeOutput("\n\treturn");
    writeOutput("\n.end method\n");
	list_destroy(variaveis);
	variaveis = list_create(sizeof(char) * 20);
}

void imprimeBefore(){
	writeOutput("\n\tgetstatic java/lang/System/out Ljava/io/PrintStream;");
}

void read(){
	writeOutput("\n\tgetstatic java/lang/System/in Ljava/io/InputStream;");
	writeOutput("\n\tinvokevirtual java/io/InputStream/read()I");
}

void imprimeAfter(){
	writeOutput("\n\tinvokevirtual java/io/PrintStream/println(Ljava/lang/String;)V");
}

int idIdentificador(char *identificador){
	int ret = -1;
	for(int i=0;i<variaveis->tam;i++){
		if( strcmp((char*)(elementAt(variaveis,i)),identificador)== 0){
			ret = i;
		}
	}
	if(inFunc == 0){
		ret++;
	}
	return ret;
}

void imprimeValor(char *identificador){
	writeOutput("\n\tiload ");
	int id = idIdentificador(identificador);
	if(id != 0){
		writeOutput(itoa(id));
	}else{
		writeOutput("0");
	}
	writeOutput("\n\tgetstatic java/lang/System/out Ljava/io/PrintStream;\n\tswap");
	writeOutput("\n\tinvokevirtual java/io/PrintStream/println(I)V\n");
}


void empilhaPrint(char *c){
	writeOutput("\n\tldc \"");
	writeOutput(c);
	writeOutput("\"");
}

void writeOutput(char *s){
	fprintf(yyout,"%s", s);
}

void writeSelecoes(char *s){
	fprintf(selecoes,"%s", s);
}

void yyerror(const char* s) {
	fprintf(stderr, "Erro de análise (sintática): %s\n", s);
	exit(1);
}

void novoInteiroSemInicializacao(char *identificador){
	push(variaveis,identificador,variaveis->tam);
	writeOutput("\n\tldc 0\n\tistore ");
	int id = variaveis->tam;
	if(id>0){
		writeOutput(itoa(id));
	}else{
		writeOutput("0");
	}
}

void atribuiPilha(char *nome){
	writeOutput("\n\tistore ");
	int id = variaveis->tam;
	if(id>0){
		writeOutput(itoa(id));
	}else{
		writeOutput("0");
	}
}

void atribuiInteiro(char *nome, int valor){
	writeOutput("\n\tldc ");
	if(valor!=0){
		writeOutput(itoa(valor));
	}else{
		writeOutput("0");
	}
	
	writeOutput("\n\tistore ");
	int id = variaveis->tam;
	if(id>0){
		writeOutput(itoa(id));
	}else{
		writeOutput("0");
	}
	writeOutput("\n");
	
}

char* itoa(int val){
	static char buf[32] = {0};
	if(val==0) return &buf[0];
	int i = 30;
	for(; val && i ; --i, val /= 10)
		buf[i] = "0123456789abcdef"[val % 10];
	return &buf[i+1];
}

void somaIdentValor(char *ident, int valor){
	int id = idIdentificador(ident);
	writeOutput("\n\tiload ");
	if(id!=0){
		writeOutput(itoa(id));
	}else{
		writeOutput("0");
	}
	writeOutput("\n\tldc ");
	writeOutput(itoa(valor));
	writeOutput("\n\tiadd");
}

void somaInteiroInteiro(int a, int b){
	writeOutput("\n\tldc ");
	writeOutput(itoa(a));
	writeOutput("\n\tldc ");
	writeOutput(itoa(b));
	writeOutput("\n\tiadd");
}


void leValor(char *identificador){
	int id = idIdentificador(identificador);
	writeOutput("\n\tinvokestatic Output.read()I");
	writeOutput("\n\tistore ");
	if(id>0){
		writeOutput(itoa(id));
	}else{
		writeOutput("0");
	}
	
}

void somaVarVar(char *identificador1, char *identificador2){
	int id1 = idIdentificador(identificador1);
	int id2 = idIdentificador(identificador2);
	writeOutput("\n\tiload ");
	if(id1 !=0){
		writeOutput(itoa(id1));
	}else{
		writeOutput("0");
	}
	writeOutput("\n\tiload ");
	if(id2!=0){
		writeOutput(itoa(id2));
	}else{
		writeOutput("0");
	}
	writeOutput("\n\tiadd");
}

void atribuicaoSoma(char *identificador){
	int id = idIdentificador(identificador);
	writeOutput("\n\tistore ");
	if(id>0){
		writeOutput(itoa(id));
	}else{
		writeOutput("0");
	}
}

void ifIdentIgualInteiro(char *identificador, int valor){
	int id = idIdentificador(identificador);
	writeOutput("\n\tiload ");
	if(id!=0){
		writeOutput(itoa(id));
	}else{
		writeOutput("0");
	}
	writeOutput("\n\tldc ");
	writeOutput(itoa(valor));
	writeOutput("\n\tisub");
	writeOutput("\n\tifne Label");
	writeOutput(itoa(labels));
}

void ifIdentMenorInteiro(char *identificador, int valor){
	int id = idIdentificador(identificador);
	writeOutput("\n\tiload ");
	if(id!=0){
		writeOutput(itoa(id));
	}else{
		writeOutput("0");
	}
	writeOutput("\n\tldc ");
	writeOutput(itoa(valor));
	writeOutput("\n\tisub");
	writeOutput("\n\tifge Label");
	writeOutput(itoa(labels));
}


void volta(){
	writeOutput("\nLabel");
	writeOutput(itoa(labels));
	writeOutput(":");
	labels++;
}

void desvioElse(){
	writeOutput("\n\tgoto Label");
	writeOutput(itoa(labels+1));
	writeOutput("\nLabel");
	writeOutput(itoa(labels));
	writeOutput(":");
	labels++;
}

int invocaFor(char *identificador, int inicial){
	novoInteiroSemInicializacao(identificador);
	atribuiInteiro(identificador, inicial);
	int id = idIdentificador(identificador);
	writeOutput("\nFor");
	writeOutput(itoa(fors));
	writeOutput(":");
	return id;
}

void invocaWhile(){
	whileAtivo = 1;
	labels++;
	writeOutput("\nWhile");
	writeOutput(itoa(whiles));
	writeOutput(":");
}

void finalizaFor(int idIdentificador, int limitante, int passo){
	writeOutput("\n\tiinc ");
	if(idIdentificador!=0){
		writeOutput(itoa(idIdentificador));
	}else{
		writeOutput(itoa(idIdentificador));
	}
	writeOutput(" ");
	writeOutput(itoa(passo));
	writeOutput("\n\tldc ");
	writeOutput(itoa(limitante));
	writeOutput("\n\tiload ");
	if(idIdentificador!=0){
		writeOutput(itoa(idIdentificador));
	}else{
		writeOutput("0");
	}
	writeOutput("\n\tisub");
	writeOutput("\n\tifle Fim");
	writeOutput(itoa(fors+1));
	writeOutput("\n\tgoto For");
	writeOutput(itoa(fors));
	writeOutput("\nFim");
	writeOutput(itoa(fors+1));
	writeOutput(":");
	fors++;
}

void finalizaWhile(){
	writeOutput("\n\tgoto While");
	writeOutput(itoa(whiles));
	writeOutput("\nLabel");
	writeOutput(itoa(labels));
	writeOutput(":");
	labels++;
	whileAtivo = 0;
}

void criaFuncao(int tipo, char *nome){
	inFunc = 1;
	writeOutput(".method public static ");
	writeOutput(nome);
	writeOutput("(");
	for(int i=0;i<quantidadeParametros;i++){
		writeOutput("I");
	}
	writeOutput(")");
	writeOutput("I");
	writeOutput("\n\t.limit stack 5");
	writeOutput("\n\t.limit locals 5");
}

void finalizaFuncao(int tipo){
	inFunc = 0;
	writeOutput("\n\tireturn");
	writeOutput("\n.end method");
}

void adicionaParametro(int tipo , char *nome){
	push(parametros,(void*)(&tipo),parametros->tam);
	push(variaveis,nome,variaveis->tam);
}

void preparaParaChamarFuncao(char *nome){
	int id = idIdentificador(nome);
	writeOutput("\n\tiload ");
	if(id!=0){
		writeOutput(itoa(id));
	}else{
		writeOutput("0");
	}
	quantidadeParametros++;
}

void preparaParaChamarFuncao2(int valor){
	writeOutput("\n\tldc ");
	if(valor!=0){
		writeOutput(itoa(valor));
	}else{
		writeOutput("0");
	}
	quantidadeParametros++;
}

void chamaFuncaoAtribuindo(char *identificador, char *nome){
	writeOutput("\n\tinvokestatic Output/");
	writeOutput(nome);
	writeOutput("(");
	for(int i=0;i<quantidadeParametros;i++){
		writeOutput("I");
	}
	writeOutput(")");
	writeOutput("I\n\tistore ");
	int id = idIdentificador(identificador);
	if(id>0){
		writeOutput(itoa(id));
	}else{
		writeOutput("0");
	}
}