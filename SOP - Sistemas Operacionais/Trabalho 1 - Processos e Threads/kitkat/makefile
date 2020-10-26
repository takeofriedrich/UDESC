projeto=kitkat
procurando='Kit Kat\n'
bibliotecas='-pthread'

all: $(projeto)

$(projeto):
	gcc $(projeto).c -o $(projeto) $(bibliotecas)

once: 
	./$(projeto)

run: 
	bash -c "for i in {0..200}; do ./$(projeto); done"

runF:
	bash -c "for i in {0..200}; do ./$(projeto); done >> $(projeto).txt"

clean:
	rm *.txt $(projeto)

count:
	grep -cw $(procurando) $(projeto).txt


