all: prog

prog: main.o
	gcc main.o lista.h lista.c -o prog -lm

t1:
	./prog < input.txt

t2:
	./prog

clean:
	rm prog *.o *.gch