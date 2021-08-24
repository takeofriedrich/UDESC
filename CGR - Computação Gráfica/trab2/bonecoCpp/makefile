projeto=main
compilacao=-lglut -lGLU -lGL -lm -lSDL2 -lGLEW

$(projeto): $(projeto).cpp Boneco.o Tela.o
	g++ $(projeto).cpp Boneco.o Tela.o -o $(projeto) $(compilacao)


Boneco.o: Boneco.hpp Boneco.cpp 
	g++ -c Boneco.hpp Boneco.cpp  $(compilacao)

Tela.o: Tela.hpp Tela.cpp 
	g++ -c Tela.hpp Tela.cpp  $(compilacao)

clean:
	rm $(projeto) *.o *.gch

run:
	./$(projeto)