#include "ChavePrivada.hpp"
#include <iostream>

void ChavePrivada::gerarPQ()
{
    p = gerarPrimo();
    q = gerarPrimo();
}

void ChavePrivada::incrementaD()
{
    d++;
}