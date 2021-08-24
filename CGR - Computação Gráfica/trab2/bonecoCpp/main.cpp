#include "Tela.hpp"

int main(int argc, char *argv[])
{
    Tela tela = Tela{};
    Boneco *boneco = new Boneco{};
    tela.setBoneco(boneco);
    tela.create_screen(argc, argv);

    return 0;
}
