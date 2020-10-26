all: prog

prog: main.o lista.o matriz.o params.o
	gcc main.o lista.o matriz.o params.o -o prog -pthread

main.o:
	gcc -c main.c

lista.o: lista.c lista.h
	gcc -c lista.c lista.h

matriz.o: matriz.c matriz.h
	gcc -c matriz.c matriz.h

params.o: params.c params.h
	gcc -c params.c params.h

t1:
	./prog 10 10

t2:
	bash -c "for i in {0..5}; do ./prog 5 5; done"

clean:
	rm prog *.o
