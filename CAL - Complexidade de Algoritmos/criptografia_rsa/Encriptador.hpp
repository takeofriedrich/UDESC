#ifndef ENCRIPTADOR_HPP
#define ENCRIPTADOR_HPP

#include "ChavePrivada.hpp"
#include "ChavePublica.hpp"
#include "Leitor.hpp"
#include "Gerador.hpp"
#include <string>
#include <chrono>

class Encriptador
{
private:
    Leitor leitor;

public:
    Encriptador();
    void gerarChaves();

    ChavePublica chavePublica;
    ChavePrivada chavePrivada;

    boost::multiprecision::cpp_int calculaPhi(boost::multiprecision::cpp_int p, boost::multiprecision::cpp_int q);
    boost::multiprecision::cpp_int gerarE(boost::multiprecision::cpp_int n);
    static boost::multiprecision::cpp_int powMod(boost::multiprecision::cpp_int a, boost::multiprecision::cpp_int x, boost::multiprecision::cpp_int n); // a^x mod n
    void gerarD();

    void encriptarArquivo(std::string caminhoEntrada, std::string caminhoSaida, ChavePublica chave);
    void desencriptarArquivo(std::string caminhoEntrada, std::string caminhoSaida, ChavePrivada chave, ChavePublica publica);

    boost::multiprecision::cpp_int mdcExtendido(boost::multiprecision::cpp_int a, boost::multiprecision::cpp_int b, boost::multiprecision::cpp_int *x, boost::multiprecision::cpp_int *y);
    void forcaBruta(boost::multiprecision::cpp_int n, boost::multiprecision::cpp_int e);

    ChavePrivada inline getChavePrivada()
    {
        return chavePrivada;
    };

    ChavePublica inline getChavePublica()
    {
        return chavePublica;
    };
};

#endif