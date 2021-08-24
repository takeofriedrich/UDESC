#include "Robo.hpp"

void Robo::desenha()
{
    tronco();
    cabeca();
    braco();
    perna();
}

void Robo::setObjeto(GLUquadricObj *objeto)
{
    this->objeto = objeto;
}

void Robo::cabeca()
{
    float xT = 0.0f;
    float yT = 2.0f;
    float zT = 1.0f;

    glPushMatrix();
    glTranslatef(xT, yT, zT);
    gluSphere(objeto, 1.1f, 26, 13);
    glPopMatrix();
}

void Robo::braco()
{
    glColor3f(1.0f, 1.0f, 1.0f);

    float rot = 45.0f;

    float xT = 0.0f;
    float yT = 1.0f;
    float zT = 2.0f;

    float espessura = 0.5f;
    float tamCil = 2.5f;

    glPushMatrix();
    rotacao(rot, 1);
    glTranslatef(xT, yT, zT);
    gluSphere(objeto, espessura, 26, 13);
    glPopMatrix();

    glPushMatrix();
    rotacao(rot, 1);
    glTranslatef(xT, yT, zT);
    gluCylinder(objeto, espessura, espessura, tamCil, 26, 13);
    glPopMatrix();

    glPushMatrix();
    rotacao(rot, 1);
    glTranslatef(xT, yT, zT + tamCil);
    gluSphere(objeto, espessura, 26, 13);
    glPopMatrix();

    rot = 135.0f;

    xT = 0.0f; // para frente ou tras do boneco
    yT = 0.5f;
    zT = 0.5f;

    glPushMatrix();
    rotacao(rot, 1);
    glTranslatef(xT, yT, zT);
    gluSphere(objeto, espessura, 26, 13);
    glPopMatrix();

    glPushMatrix();
    rotacao(rot, 1);
    glTranslatef(xT, yT, zT);
    gluCylinder(objeto, espessura, espessura, tamCil, 26, 13);
    glPopMatrix();

    glPushMatrix();
    rotacao(rot, 1);
    glTranslatef(xT, yT, zT + tamCil);
    gluSphere(objeto, espessura, 26, 13);
    glPopMatrix();
}

void Robo::perna()
{
    glColor3f(1.0f, 1.0f, 1.0f);

    float rot = 60.0f;

    float xT = 0.0f;
    float yT = -1.0f;
    float zT = 5.5f;

    float espessura = 0.5f;
    float tamCil = 2.5f;

    glPushMatrix();
    rotacao(rot, 1);
    glTranslatef(xT, yT, zT);
    gluSphere(objeto, espessura, 26, 13);
    glPopMatrix();

    glPushMatrix();
    rotacao(rot, 1);
    glTranslatef(xT, yT, zT);
    gluCylinder(objeto, espessura, espessura, tamCil, 26, 13);
    glPopMatrix();

    glPushMatrix();
    rotacao(rot, 1);
    glTranslatef(xT, yT, zT + tamCil);
    gluSphere(objeto, espessura, 26, 13);
    glPopMatrix();

    glColor3f(1.0f, 1.0f, 1.0f);

    rot = 125.0f;

    xT = 0.0f;
    yT = 3.2f;
    zT = 4.5f;

    glPushMatrix();
    rotacao(rot, 1);
    glTranslatef(xT, yT, zT);
    gluSphere(objeto, espessura, 26, 13);
    glPopMatrix();

    glPushMatrix();
    rotacao(rot, 1);
    glTranslatef(xT, yT, zT);
    gluCylinder(objeto, espessura, espessura, tamCil, 26, 13);
    glPopMatrix();

    glPushMatrix();
    rotacao(rot, 1);
    glTranslatef(xT, yT, zT + tamCil);
    gluSphere(objeto, espessura, 26, 13);
    glPopMatrix();
}

void Robo::tronco()
{
    glColor3f(1.0f, 1.0f, 1.0f);

    float rot = 90.0f;
    float xT = 0.0f;
    float yT = 1.0f;
    float zT = 0.0f;
    float espessura = 1.0f;
    float tamCil = 5.0f;

    glPushMatrix();
    rotacao(rot, 1);
    glTranslatef(xT, yT, zT);
    gluSphere(objeto, espessura, 26, 13);
    glPopMatrix();

    glPushMatrix();
    rotacao(rot, 1);
    glTranslatef(0.0f, 1.0f, 0.0f);
    gluCylinder(objeto, espessura, espessura, tamCil, 26, 13);
    glPopMatrix();

    glPushMatrix();
    rotacao(rot, 1);
    glTranslatef(xT, yT, zT + tamCil);
    gluSphere(objeto, espessura, 26, 13);
    glPopMatrix();
}

void Robo::rotacao(float rotacao, int eixo)
{
    switch (eixo)
    {
    case 1:
        glRotatef(rotacao, 1, 0, 0);
        break;

    case 2:
        glRotatef(rotacao, 0, 1, 0);
        break;

    case 3:
        glRotatef(rotacao, 0, 0, 1);
        break;
    }
}
