#include "Leitor.hpp"
#include <iostream>
#include <fstream>

std::vector<int> Leitor::lerArquivoChar(std::string caminho)
{
    std::vector<int> bytes;
    char byte = 0;

    std::ifstream input_file(caminho);

    while (input_file.get(byte))
    {
        bytes.push_back(byte);
    }
    return bytes;
}

std::vector<std::string> Leitor::lerArquivoLinha(std::string caminho)
{
    std::vector<std::string> bytes;
    std::string linha;

    std::ifstream input_file(caminho);

    while (getline(input_file, linha))
    {
        bytes.push_back(linha);
    }
    return bytes;
}

void Leitor::escreverArquivoBig(std::vector<boost::multiprecision::cpp_int> letras, std::string caminho)
{
    std::ofstream output_file(caminho);

    std::vector<boost::multiprecision::cpp_int>::iterator it;

    for (it = letras.begin(); it != letras.end(); it++)
    {
        std::string number = (*it).str();
        std::string::iterator it2;

        for (it2 = number.begin(); it2 != number.end(); it2++)
        {
            output_file.put((*it2));
        }
        output_file.put('\n');
    }
}

void Leitor::escreverArquivo(std::vector<boost::multiprecision::cpp_int> letras, std::string caminho)
{
    std::ofstream output_file(caminho);

    std::vector<boost::multiprecision::cpp_int>::iterator it;

    for (it = letras.begin(); it != letras.end(); it++)
    {
        output_file.put((*it).convert_to<char>());
    }
}