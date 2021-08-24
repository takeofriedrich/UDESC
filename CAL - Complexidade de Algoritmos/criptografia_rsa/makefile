projeto=main
compilacao=-Wall -lgmpxx -lgmp#-Wshadow
compilacaoMac=-std=c++11 -stdlib=libc++ -W

$(projeto): $(projeto).cpp Encriptador.o Chave.o ChavePrivada.o ChavePublica.o Leitor.o Gerador.o
	g++ $(projeto).cpp Encriptador.o Chave.o ChavePrivada.o ChavePublica.o Leitor.o Gerador.o -o $(projeto) $(compilacao)

comp: $(projeto).cpp EncriptadorMAC.o ChaveMAC.o ChavePrivadaMAC.o ChavePublicaMAC.o LeitorMAC.o
	g++ $(compilacaoMac)#pragma-messages $(projeto).cpp Encriptador.o Chave.o ChavePrivada.o ChavePublica.o Leitor.o -o $(projeto) 

Encriptador.o: Encriptador.hpp Encriptador.cpp 
	g++ -c Encriptador.hpp Encriptador.cpp  $(compilacao)

Chave.o: Chave.hpp Chave.cpp 
	g++ -c Chave.hpp Chave.cpp  $(compilacao)

ChavePrivada.o: ChavePrivada.hpp Chave.cpp 
	g++ -c ChavePrivada.hpp ChavePrivada.cpp  $(compilacao)

ChavePublica.o: ChavePublica.hpp Chave.cpp 
	g++ -c ChavePublica.hpp ChavePublica.cpp  $(compilacao)

Leitor.o: Leitor.hpp Leitor.cpp 
	g++ -c Leitor.hpp Leitor.cpp  $(compilacao)

Gerador.o: Gerador.hpp Gerador.cpp 
	g++ -c Gerador.hpp Gerador.cpp  $(compilacao)

clean:
	rm $(projeto) *.o *.gch *.tmp

run:
	./$(projeto)

runF:
	./$(projeto) < entrada.txt

runO:
	./$(projeto) > out.txt

runFO:
	./$(projeto) < entrada.txt > out.txt


#######################################################################################

EncriptadorMAC.o: Encriptador.hpp Encriptador.cpp 
	clang++ $(compilacaoMac)#pragma-messages -c Encriptador.hpp Encriptador.cpp

ChaveMAC.o: Chave.hpp Chave.cpp 
	clang++ $(compilacaoMac)#pragma-messages -c Chave.hpp Chave.cpp

ChavePrivadaMAC.o: ChavePrivada.hpp Chave.cpp 
	clang++ $(compilacaoMac)#pragma-messages -c ChavePrivada.hpp ChavePrivada.cpp

ChavePublicaMAC.o: ChavePublica.hpp Chave.cpp 
	clang++ $(compilacaoMac)#pragma-messages -c ChavePublica.hpp ChavePublica.cpp

LeitorMAC.o: Leitor.hpp Leitor.cpp 
	clang++ $(compilacaoMac)#pragma-messages -c Leitor.hpp Leitor.cpp