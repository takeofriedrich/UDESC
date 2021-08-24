#include "Chave.hpp"
#include "Encriptador.hpp"
#include "iostream"

unsigned char Chave::GAMBS = 0;

// bool Chave::isPrimo(boost::multiprecision::cpp_int numero)
// {
//     boost::multiprecision::cpp_int i = boost::multiprecision::sqrt(numero);
//     if (numero % 2 == 0)
//     {
//         return false;
//     }
//     else
//     {
//         if (i % 2 == 0)
//             i--;
//         for (; i > 1; i -= 2)
//         {
//             if (numero % i == 0)
//             {
//                 return false;
//             }
//         }
//         return true;
//     }
// }

boost::multiprecision::cpp_int Chave::pow(boost::multiprecision::cpp_int base, boost::multiprecision::cpp_int exp)
{
    boost::multiprecision::cpp_int i = 0;
    boost::multiprecision::cpp_int resultado;
    for (; i < exp; i++)
    {
        resultado = resultado * base;
    }
    return resultado;
}

boost::multiprecision::cpp_int Chave::acharPrimoCandidato()
{
    int primeiros_primos[70] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293, 307, 311, 313, 317, 331, 337, 347, 349};
    boost::multiprecision::cpp_int candidato;
    int teste = 0;

    while (true)
    {

        candidato = Gerador::gerarNumero() + 1;
        for (int i = 0; i < 70; i++)
        {
            if (candidato % primeiros_primos[i] == 0 && primeiros_primos[i] * primeiros_primos[i] <= candidato)
            {
                teste++;
                break;
            }
        }
        if (teste == 0)
        {
            return candidato;
        }
        teste = 0;
    }
}

bool Chave::composite(boost::multiprecision::cpp_int tester, boost::multiprecision::cpp_int ec, boost::multiprecision::cpp_int numero, int maxDivPorDois)
{
    if (Encriptador::powMod(tester, ec, numero) == 1)
    {
        return false;
    }
    for (int i = 0; i < maxDivPorDois; i++)
    {
        if (Encriptador::powMod(tester, pow(2, i) * ec, numero) == numero - 1)
        {
            return false;
        }
    }
    return true;
}

bool Chave::isPrimo(boost::multiprecision::cpp_int numero)
{ //Miller-Rabin Test

    boost::multiprecision::cpp_int tester = Gerador::gerarNumero();

    int maxDivPorDois = 0;
    boost::multiprecision::cpp_int ec = numero - 1;
    while (ec % 2 == 0)
    {
        ec >>= 1;
        maxDivPorDois++;
    }
    //assert(pow(2,maxDivPorDois * ec) == numero-1);

    //Aqui setamos as tentativas
    int tentativas = 20;
    for (int i = 0; i < tentativas; i++)
    {
        while (tester < 2 && tester > numero)
        {

            tester = Gerador::gerarNumero();
        }
        if (composite(tester, ec, numero, maxDivPorDois))
        {
            return false;
        }
    }
    return true;
}

boost::multiprecision::cpp_int Chave::gerarPrimo()
{
    boost::multiprecision::cpp_int primo;
    while (true)
    {
        primo = acharPrimoCandidato();
        // std::cout << "Primo Candidato = " << primo << std::endl;
        if (isPrimo(primo))
        {
            break;
        }
    }
    return primo;
}

// boost::multiprecision::cpp_int Chave::gerarPrimo()
// {
//     typedef boost::random::independent_bits_engine<boost::random::mt19937, 8, boost::multiprecision::cpp_int> generator_type;
//     generator_type gerador;
//     gerador.seed(time(0) + Chave::GAMBS);
//     Chave::GAMBS++;
//     boost::multiprecision::cpp_int value = gerador();
//     if (isPrimo(value))
//         return value;
//     else
//     {
//         if (value % 2 == 0)
//         {
//             value = value + 1;
//         }
//         while (!isPrimo(value))
//         {
//             std::cout << value << std::endl;
//             value = value + 2;
//         }
//         return value;
//     }
// }
