#ifndef TELA_HPP
#define TELA_HPP

#include <GL/glut.h>
#include <string>
#include <cmath>
#include "Robo.hpp"

class Tela
{
public:
    Tela();
    void create_screen(int argc, char *argv[]);
    static GLfloat yRot;
    static GLfloat xRot;
    static GLfloat angle;
    static GLfloat lx;
    static GLfloat lz;
    static GLfloat x;
    static GLfloat z;
    void setRobo(Robo *robo);

private:
    int altura = 600;
    int largura = 800;
    std::string nome = "Castelo - Autor: Vinicius Takeo Friedrich Kuwaki";
    static void change_size(int w, int h);
    static void setup_rc();
    static void special_keys(unsigned char key, int x, int y);
    static void render_scene(void);
    static GLUquadricObj *objeto;
    static Robo *robo;
};

#endif