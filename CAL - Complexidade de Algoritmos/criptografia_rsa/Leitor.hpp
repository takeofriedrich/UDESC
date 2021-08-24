#ifndef LEITOR_HPP
#define LEITOR_HPP

#include <vector>
#include <string>
#include <boost/multiprecision/cpp_int.hpp>

class Leitor
{
public:
    std::vector<int> lerArquivoChar(std::string caminho);
    std::vector<std::string> lerArquivoLinha(std::string caminho);
    void escreverArquivoBig(std::vector<boost::multiprecision::cpp_int> letras, std::string caminho);
    void escreverArquivo(std::vector<boost::multiprecision::cpp_int> letras, std::string caminho);
};

#endif