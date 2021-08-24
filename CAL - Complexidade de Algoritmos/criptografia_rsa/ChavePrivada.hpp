#ifndef CHAVE_PRIVADA_HPP
#define CHAVE_PRIVADA_HPP

#include "Chave.hpp"
#include <boost/multiprecision/cpp_int.hpp>

class ChavePrivada : private Chave
{
private:
    boost::multiprecision::cpp_int p;
    boost::multiprecision::cpp_int q;
    boost::multiprecision::cpp_int d;

public:
    void gerarPQ();
    boost::multiprecision::cpp_int inline getP()
    {
        return p;
    }
    void inline setP(boost::multiprecision::cpp_int value)
    {
        p = value;
    }
    boost::multiprecision::cpp_int inline getQ()
    {
        return q;
    }
    void inline setQ(boost::multiprecision::cpp_int value)
    {
        q = value;
    }

    boost::multiprecision::cpp_int inline getD()
    {
        return d;
    }
    void inline setD(boost::multiprecision::cpp_int value)
    {
        d = value;
    }
    void incrementaD();
};

#endif