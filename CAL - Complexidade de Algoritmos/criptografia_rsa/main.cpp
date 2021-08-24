#include <iostream>
#include "Chave.hpp"
#include <boost/multiprecision/cpp_int.hpp>
#include <boost/random.hpp>
#include "Encriptador.hpp"
#include "Leitor.hpp"

int main()
{
    setlocale(LC_ALL, "PT-BR");
    //Encriptador enc;
    //ChavePublica publica;
    //publica.setN(12345);
    //publica.setE(67890);
    //enc.encriptarArquivo("entrada.txt", "saida.txt", publica);

    // ChavePrivada p;
    // p.gerarPQ();
    // std::cout << p.getP() << std::endl;
    // std::cout << p.getQ() << std::endl;
    // std::cout << "TERMINEI" << std::endl;

    Encriptador enc;
    enc.gerarChaves();

    // std::cout << "D: " << enc.chavePrivada.getD() << std::endl;
    // std::cout << "E: " << enc.chavePublica.getE() << std::endl;
    // std::cout << "N: " << enc.chavePublica.getN() << std::endl;

    enc.encriptarArquivo("entrada.txt", "encriptado.txt", enc.getChavePublica());

    enc.desencriptarArquivo("encriptado.txt", "desencriptado.txt", enc.getChavePrivada(), enc.getChavePublica());

    //enc.forcaBruta(enc.chavePublica.getN(),enc.chavePublica.getE());

    return 0;
}