all: prog

prog: main.o lista.o fifo.o mru.o
	gcc main.o lista.o fifo.o mru.o -o prog -pthread

main.o:
	gcc -c main.c

lista.o: lista.c lista.h
	gcc -c lista.c lista.h

fifo.o: fifo.c fifo.h
	gcc -c fifo.c fifo.h

mru.o: mru.c mru.h
	gcc -c mru.c mru.h

t1:
	./prog 3 < in.txt

t2:
	./prog 3 < in2.txt

t3:
	./prog 0 < in3.txt

clean:
	rm prog *.o *.gch