projeto=takeo

all: $(projeto)

$(projeto): compiladoBizon compiladoFlex lista.o
	gcc $(projeto).tab.c lex.yy.c lista.o -o $(projeto) -lm

compiladoBizon:
	bison -d $(projeto).y --verbose

compiladoFlex:
	flex $(projeto).lex

lista.o:
	gcc -c lista.h lista.c

graphViz:
	dot -Tpdf $(projeto).dot -o $(projeto)3.pdf -v

compiladoC:
	gcc lex.yy.c -o $(projeto) -lfl

clean:
	rm lex.yy.c $(projeto) $(projeto).tab.c $(projeto).tab.h

hello:
	./$(projeto) casos/helloworld.txt

entrada:
	./$(projeto) casos/entrada.txt

soma:
	./$(projeto) casos/soma.txt

if:
	./$(projeto) casos/if.txt

contador:
	./$(projeto) casos/contador.txt

while:
	./$(projeto) casos/while.txt

funcao:
	./$(projeto) casos/funcao.txt

run:
	java -jar jasmin/jasmin.jar out.j
	java Output
