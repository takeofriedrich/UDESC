#ifndef CHAVE_PUBLICA_HPP
#define CHAVE_PUBLICA_HPP

#include "Chave.hpp"
#include <boost/multiprecision/cpp_int.hpp>

class ChavePublica : private Chave
{
private:
    boost::multiprecision::cpp_int n;
    boost::multiprecision::cpp_int e;
    boost::multiprecision::cpp_int phi;

public:
    boost::multiprecision::cpp_int inline getN()
    {
        return n;
    }
    void inline setN(boost::multiprecision::cpp_int value)
    {
        n = value;
    }
    boost::multiprecision::cpp_int inline getE()
    {
        return e;
    }
    void inline setE(boost::multiprecision::cpp_int value)
    {
        e = value;
    }
    boost::multiprecision::cpp_int inline getPhi()
    {
        return phi;
    }
    void inline setPhi(boost::multiprecision::cpp_int value)
    {
        phi = value;
    }
};
#endif