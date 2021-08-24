projeto=main
compilacao=-lSDL -lGL -lGLU -lglut

$(projeto): $(projeto).o
	g++ $(projeto).o -o $(projeto) $(compilacao)

$(projeto).o: $(projeto).cpp
	g++ -c $(projeto).cpp $(compilacao)

clean:
	rm $(projeto) $(projeto).o

run:
	./$(projeto)