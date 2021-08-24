#ifndef GERADOR_HPP
#define GERADOR_HPP

#include <boost/multiprecision/cpp_int.hpp>
#include <boost/random.hpp>

class Gerador
{
private:
    static unsigned char gambsTime;

    static unsigned char inline getGambsTime()
    {
        gambsTime++;
        return gambsTime;
    }

public:
    static boost::multiprecision::cpp_int gerarNumero();
    static unsigned char tamanhoChave;
};

#endif