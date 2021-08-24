#include "Gerador.hpp"

unsigned char Gerador::gambsTime{0};

boost::multiprecision::cpp_int Gerador::gerarNumero()
{
    typedef boost::random::independent_bits_engine<boost::random::mt19937, 16, boost::multiprecision::cpp_int> generator_type;
    generator_type gerador;
    gerador.seed(time(0) + getGambsTime());
    return gerador();
}