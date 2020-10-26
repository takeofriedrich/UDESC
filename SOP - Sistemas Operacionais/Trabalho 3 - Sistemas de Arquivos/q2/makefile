all: prog

prog: main.o
	gcc main.o -o prog -lm

t1:
	./prog lista-arqs

t2:
	./prog lista-arqs > out

clean:
	rm prog *.o *.gch