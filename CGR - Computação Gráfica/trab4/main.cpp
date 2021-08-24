#include "Tela.hpp"
#include <iostream>

int main(int argc, char *argv[])
{

    Tela tela = Tela{};
    Robo *robo = new Robo{};
    tela.setRobo(robo);
    tela.create_screen(argc, argv);

    return 0;
}
