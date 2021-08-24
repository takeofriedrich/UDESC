projeto=main

all: $(projeto)

$(projeto): 
	ghc -o $(projeto) $(projeto).hs

cleanL:
	rm *.o *.hi $(projeto)

cleanW:
	del /Q /F rm *.o *.hi *.exe

run:
	./$(projeto)
	
runCaso1W:
	cmd.exe /c ".\$(projeto).exe < .\caso1.txt"

