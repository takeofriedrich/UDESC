#ifndef TELA_HPP
#define TELA_HPP

#include <GL/glut.h>
#include <string>
#include "Boneco.hpp"

class Tela
{
public:
    Tela();
    void create_screen(int argc, char *argv[]);
    static GLfloat yRot;
    void setBoneco(Boneco *boneco);

private:
    int altura = 600;
    int largura = 800;
    std::string nome = "Boneco de Neve - Autor: Vinicius Takeo Friedrich Kuwaki";
    static void change_size(int w, int h);
    static void setup_rc();
    static void special_keys(int key, int x, int y);
    static void render_scene(void);
    static GLUquadricObj *objeto;
    static Boneco *boneco;
};

#endif