#ifndef CHAVE_HPP
#define CHAVE_HPP

#include <boost/multiprecision/cpp_int.hpp>
#include <boost/random.hpp>
#include <iostream>
#include "Gerador.hpp"

class Chave
{
public:
    // Chave(const std::size_t numero_bits);
    static boost::multiprecision::cpp_int pow(boost::multiprecision::cpp_int base, boost::multiprecision::cpp_int exp);
    static bool composite(boost::multiprecision::cpp_int tester, boost::multiprecision::cpp_int ec, boost::multiprecision::cpp_int numero, int maxDivPorDois);
    static boost::multiprecision::cpp_int acharPrimoCandidato();
    static bool isPrimo(boost::multiprecision::cpp_int numero);
    boost::multiprecision::cpp_int gerarPrimo();
    static unsigned char GAMBS;

private:
    // static const std::size_t numero_bits;
};

#endif