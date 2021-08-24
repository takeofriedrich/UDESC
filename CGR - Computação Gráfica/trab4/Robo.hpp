#ifndef ROBO_HPP
#define ROBO_HP

#include <GL/glut.h>

class Robo
{
public:
    void virtual desenha();
    void setObjeto(GLUquadricObj *objeto);
    void mexerBracos();
    void olharParaEsquerda();
    void olharParaDireita();
    Robo();

private:
    GLUquadricObj *objeto;
    void cabeca();
    void braco();
    void perna();
    void tronco();
    void cilindro(float xT, float yT, float zT, float rotacao, int eixo, float tamanho, float espessura);
    void rotacao(float rotacao, int eixo);
    float rotacaoBracoEsquerdo = 45.0f;
    float rotacaoBracoDireito = 135.0f;
    float olhoEsquerdoY = 0.4f;
    float olhoDireitoY = -0.4f;
    bool subindoBracos = true;
};

#endif
