#include "Encriptador.hpp"
#include "iostream"

#include <string>

Encriptador::Encriptador()
{
}

void Encriptador::gerarChaves()
{
    auto start = std::chrono::steady_clock::now();

    chavePrivada.gerarPQ();

    // std::cout << "p=" << chavePrivada.getP() << std::endl;
    // std::cout << "q=" << chavePrivada.getQ() << std::endl;

    chavePublica.setN(chavePrivada.getP() * chavePrivada.getQ());

    // std::cout << "n=" << chavePublica.getN() << std::endl;

    chavePublica.setPhi(calculaPhi(chavePrivada.getP(), chavePrivada.getQ()));

    // std::cout << "phi=" << chavePublica.getPhi() << std::endl;

    boost::multiprecision::cpp_int e = gerarE(chavePublica.getPhi());

    while (chavePublica.getPhi() % e == 0)
    {
        e = gerarE(chavePublica.getPhi());
    }

    // std::cout << "e=" << e << std::endl;
    chavePublica.setE(e);

    gerarD();

    // std::cout << "d=" << chavePrivada.getD() << std::endl;

    auto end = std::chrono::steady_clock::now();
    auto diff = end - start;

    std::cout << std::chrono::duration<double, std::milli>(diff).count() << ",";
}

void Encriptador::gerarD()
{

    boost::multiprecision::cpp_int *aux1 = new boost::multiprecision::cpp_int;
    boost::multiprecision::cpp_int *aux2 = new boost::multiprecision::cpp_int;

    mdcExtendido(chavePublica.getE(), chavePublica.getPhi(), aux1, aux2);

    // std::cout << "aux1: " << *aux1 << std::endl;
    // std::cout << "aux2: " << *aux2 << std::endl;

    if (*aux1 > 0)
    {
        chavePrivada.setD(*aux1);
    }
    else
    {
        chavePrivada.setD(*aux2);
    }

    delete aux1;
    delete aux2;
}

boost::multiprecision::cpp_int Encriptador::calculaPhi(boost::multiprecision::cpp_int p, boost::multiprecision::cpp_int q)
{
    return (q - 1) * (p - 1);
}

boost::multiprecision::cpp_int Encriptador::gerarE(boost::multiprecision::cpp_int phi)
{
    // 1 < E < phi(n)

    boost::multiprecision::cpp_int value = Gerador::gerarNumero();

    while (value >= phi)
    {
        value = Gerador::gerarNumero();
    }

    if (Chave::isPrimo(value))
    {
        return value;
    }
    else
    {
        if (value % 2 == 0)
        {
            value = value - 1;
        }
        while (!Chave::isPrimo(value))
        {
            value = value - 2;
        }
        return value;
    }
}

boost::multiprecision::cpp_int Encriptador::powMod(boost::multiprecision::cpp_int a, boost::multiprecision::cpp_int x, boost::multiprecision::cpp_int n)
{
    boost::multiprecision::cpp_int aux = a;
    boost::multiprecision::cpp_int retorno = 1;

    for (; x; x = x / 2)
    {
        if (x % 2 == 1)
        {
            retorno = (retorno * a) % n;
        }
        a = (a * a) % n;
    }

    return retorno;
}

void Encriptador::encriptarArquivo(std::string caminhoEntrada, std::string caminhoSaida, ChavePublica chave)
{
    auto start = std::chrono::steady_clock::now();
    std::vector<int> texto = leitor.lerArquivoChar(caminhoEntrada);
    std::vector<boost::multiprecision::cpp_int> encriptado;

    std::vector<int>::iterator it;

    for (it = texto.begin(); it != texto.end(); it++)
    {
        boost::multiprecision::cpp_int x = powMod(*it, chave.getE(), chave.getN());
        // std::cout << std::endl
        //           << "Antes: " << *it << std::endl;
        // std::cout << "Depois: " << x << std::endl;
        encriptado.push_back(x);
    }

    leitor.escreverArquivoBig(encriptado, caminhoSaida);
    auto end = std::chrono::steady_clock::now();

    auto diff = end - start;

    std::cout << std::chrono::duration<double, std::milli>(diff).count() << ",";
}

void Encriptador::desencriptarArquivo(std::string caminhoEntrada, std::string caminhoSaida, ChavePrivada chave, ChavePublica publica)
{
    auto start = std::chrono::steady_clock::now();
    std::vector<std::string> cifrado = leitor.lerArquivoLinha(caminhoEntrada);
    std::vector<std::string>::iterator it;

    std::vector<boost::multiprecision::cpp_int> decifrado;

    for (it = cifrado.begin(); it != cifrado.end(); it++)
    {

        boost::multiprecision::cpp_int character = boost::multiprecision::cpp_int((*it));
        boost::multiprecision::cpp_int x = powMod(character, chave.getD(), publica.getN());
        // std::cout << std::endl
        //           << "Antes: " << character << std::endl;
        // std::cout << "Depois: " << x << std::endl;
        decifrado.push_back(x);
    }

    leitor.escreverArquivo(decifrado, caminhoSaida);

    auto end = std::chrono::steady_clock::now();

    auto diff = end - start;

    std::cout << std::chrono::duration<double, std::milli>(diff).count() << std::endl;
}

boost::multiprecision::cpp_int Encriptador::mdcExtendido(boost::multiprecision::cpp_int a, boost::multiprecision::cpp_int b, boost::multiprecision::cpp_int *x, boost::multiprecision::cpp_int *y)
{
    if (a == 0)
    {
        *x = 0;
        *y = 1;
        return b;
    }

    boost::multiprecision::cpp_int *aux1 = new boost::multiprecision::cpp_int;
    boost::multiprecision::cpp_int *aux2 = new boost::multiprecision::cpp_int;

    boost::multiprecision::cpp_int mdc = mdcExtendido(b % a, a, aux1, aux2);

    *x = *aux2 - *aux1 * (b / a);
    *y = *aux1;

    delete aux1;
    delete aux2;

    return mdc;
}

void Encriptador::forcaBruta(boost::multiprecision::cpp_int n, boost::multiprecision::cpp_int e)
{

    int num = 1000000;
    boost::multiprecision::cpp_int aux;

    std::vector<int> primos = leitor.lerArquivoChar("primerMilhao.txt");
    std::vector<int>::iterator it, it2;

    for (it = primos.begin(); it != primos.end(); it++)
    {
        for (it2 = primos.begin(); it2 != primos.end(); it2++)
        {
            aux = (*it) * (*it2);
            if (n == aux)
            {
                std::cout << "p = " << *it << std::endl;
                std::cout << "q = " << *it2 << std::endl;
                break;
            }
        }
    }
}
