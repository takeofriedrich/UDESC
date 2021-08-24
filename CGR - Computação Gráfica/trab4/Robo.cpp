#include "Robo.hpp"
#include <iostream>

Robo::Robo()
{
}

void Robo::olharParaEsquerda()
{
    std::cout << "A" << std::endl;
    if (olhoEsquerdoY > 0.3f)
    {
        olhoEsquerdoY -= 0.025f;
    }
    if (olhoDireitoY > -0.5f)
    {
        olhoDireitoY -= 0.025f;
    }
}
void Robo::olharParaDireita()
{
    if (olhoEsquerdoY < 0.5f)
    {
        olhoEsquerdoY += 0.025f;
    }
    if (olhoDireitoY < -0.3f)
    {
        olhoDireitoY += 0.025f;
    }
}

void Robo::mexerBracos()
{
    if (subindoBracos)
    {
        if (rotacaoBracoEsquerdo == 65)
        {
            subindoBracos = false;
        }
        else
        {
            rotacaoBracoEsquerdo += 2.5f;
            rotacaoBracoDireito += 2.5f;
        }
    }
    else
    {
        if (rotacaoBracoEsquerdo == 25)
        {
            subindoBracos = true;
        }
        else
        {
            rotacaoBracoEsquerdo -= 2.5f;
            rotacaoBracoDireito -= 2.5f;
        }
    }
}

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

    glPushMatrix();
    glColor3f(1, 1, 1);
    glTranslatef(xT - 1.3, yT + 0.4, zT + olhoDireitoY);
    gluSphere(objeto, 0.06f, 26, 26);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0, 0, 0);
    glTranslatef(xT - 1.1, yT + 0.4, zT - 0.4f);
    gluSphere(objeto, 0.20f, 26, 26);
    glPopMatrix();

    glPushMatrix();
    glColor3f(1, 1, 1);
    glTranslatef(xT - 1.3, yT + 0.4, zT + olhoEsquerdoY);
    gluSphere(objeto, 0.06f, 26, 26);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0, 0, 0);
    glTranslatef(xT - 1.1, yT + 0.4, zT + 0.4f);
    gluSphere(objeto, 0.20f, 26, 26);
    glPopMatrix();
}

void Robo::braco()
{
    glColor3f(1.0f, 1.0f, 1.0f);

    // 65
    // 45
    // 25
    float rot = 45.0f;

    float xT = 0.0f;
    float yT = 1.0f;
    float zT = 2.0f;

    float espessura = 0.5f;
    float tamCil = 2.5f;

    glPushMatrix();
    rotacao(rotacaoBracoEsquerdo, 1);
    glTranslatef(xT, yT, zT);
    gluSphere(objeto, espessura, 26, 13);
    glPopMatrix();

    glPushMatrix();
    rotacao(rotacaoBracoEsquerdo, 1);
    glTranslatef(xT, yT, zT);
    gluCylinder(objeto, espessura, espessura, tamCil, 26, 13);
    glPopMatrix();

    glPushMatrix();
    rotacao(rotacaoBracoEsquerdo, 1);
    glTranslatef(xT, yT, zT + tamCil);
    gluSphere(objeto, espessura, 26, 13);
    glPopMatrix();

    // -------------------------------------------

    rot = 135.0f;

    xT = 0.0f; // para frente ou tras do boneco
    yT = 0.5f;
    zT = 0.5f;

    glPushMatrix();
    rotacao(rotacaoBracoDireito, 1);
    glTranslatef(xT, yT, zT);
    gluSphere(objeto, espessura, 26, 13);
    glPopMatrix();

    glPushMatrix();
    rotacao(rotacaoBracoDireito, 1);
    glTranslatef(xT, yT, zT);
    gluCylinder(objeto, espessura, espessura, tamCil, 26, 13);
    glPopMatrix();

    glPushMatrix();
    rotacao(rotacaoBracoDireito, 1);
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

    // ------------------------------------

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
