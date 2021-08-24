#ifndef ROBO_HPP
#define ROBO_HP

#include <GL/glut.h>

class Robo
{
public:
    void virtual desenha();
    void setObjeto(GLUquadricObj *objeto);

private:
    GLUquadricObj *objeto;
    void cabeca();
    void braco();
    void perna();
    void tronco();
    void cilindro(float xT, float yT, float zT, float rotacao, int eixo, float tamanho, float espessura);
    void rotacao(float rotacao, int eixo);
};

#endif
