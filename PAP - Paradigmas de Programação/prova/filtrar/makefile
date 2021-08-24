projeto=filtrar

all: $(projeto)

$(projeto): 
	ghc -o $(projeto) $(projeto).hs

clean:
	del /Q /F rm *.o *.hi *.exe

run:
	./$(projeto)
	
runF:
	cmd.exe /c ".\$(projeto).exe < .\entrada.txt"