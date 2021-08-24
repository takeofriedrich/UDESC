projeto=main
compilacao=-lglut -lGLU -lGL -lm -lSDL2 -lGLEW

$(projeto): $(projeto).cpp Robo.o Tela.o
	g++ $(projeto).cpp Robo.o Tela.o -o $(projeto) $(compilacao)


Robo.o: Robo.hpp Robo.cpp 
	g++ -c Robo.hpp Robo.cpp  $(compilacao)

Tela.o: Tela.hpp Tela.cpp 
	g++ -c Tela.hpp Tela.cpp  $(compilacao)

clean:
	rm $(projeto) *.o *.gch

run:
	./$(projeto)