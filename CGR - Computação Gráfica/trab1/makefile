projeto=main
compilacao=-lglut -lGLU -lGL -lm -lSDL2 -lGLEW

$(projeto): $(projeto).c
	gcc $(projeto).c -o $(projeto) $(compilacao)

clean:
	rm $(projeto) *.o *.gch

run:
	./$(projeto)
