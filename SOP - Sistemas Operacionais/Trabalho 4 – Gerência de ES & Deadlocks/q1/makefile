all: prog

prog:
	gcc q1.c lista.h lista.c -o prog -lm

t1:
	./prog < input.txt > matriz.csv

t2:
	gcc q1Ordenar.c lista.h lista.c -o prog2 -lm

t3:
	./prog2 < input.txt > matriz2.csv
	
clean:
	rm prog *.o *.gch