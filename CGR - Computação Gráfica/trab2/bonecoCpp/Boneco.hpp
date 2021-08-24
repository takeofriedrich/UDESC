#ifndef BONECO_HPP
#define BONECO_HP

#include <GL/glut.h>

class Boneco
{
public:
    void virtual desenha();
    void setObjeto(GLUquadricObj *objeto);

private:
    void chapeu();
    void cabeca();
    void olhoEsquerdo();
    void olhoDireito();
    void nariz();
    void boca();
    void corpo();
    GLUquadricObj *objeto;
};

#endif
