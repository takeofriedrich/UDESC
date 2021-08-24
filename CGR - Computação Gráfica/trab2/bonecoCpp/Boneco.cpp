#include "Boneco.hpp"

void Boneco::desenha()
{
    chapeu();
    cabeca();
    corpo();
}

void Boneco::setObjeto(GLUquadricObj *objeto)
{
    this->objeto = objeto;
}

void Boneco::chapeu()
{
    glColor3f(1.0f, 0.0f, 1.0f);
    glPushMatrix();
    glTranslatef(0.0f, 1.2f, 0.0f);
    glRotatef(-90.0f, 3.8f, 1.0f, 1.0f);
    gluCylinder(objeto, 0.25f, 0.0f, 0.7f, 26, 13);
    glPopMatrix();
}
void Boneco::cabeca()
{
    glPushMatrix();
    glColor3f(1.0f, 1.0f, 1.0f);
    glTranslatef(0.0f, 1.0f, 0.0f);
    gluSphere(objeto, 0.24f, 26, 13);
    glPopMatrix();

    olhoEsquerdo();
    olhoDireito();
    nariz();
    boca();
}

void Boneco::olhoEsquerdo()
{
    glColor3f(0.0f, 0.0f, 0.0f);
    glPushMatrix();
    glTranslatef(0.06f, 1.1f, 0.2f);
    gluSphere(objeto, 0.035f, 26, 13);
    glPopMatrix();

    glColor3f(1.0f, 1.0f, 1.0f);
    glPushMatrix();
    glTranslatef(0.06f, 1.1f, 0.22f);
    gluSphere(objeto, 0.018f, 26, 13);
    glPopMatrix();
}

void Boneco::olhoDireito()
{
    glColor3f(0.0f, 0.0f, 0.0f);
    glPushMatrix();
    glTranslatef(-0.06f, 1.1f, 0.2f);
    gluSphere(objeto, 0.035f, 26, 13);
    glPopMatrix();

    glColor3f(1.0f, 1.0f, 1.0f);
    glPushMatrix();
    glTranslatef(-0.06f, 1.1f, 0.22f);
    gluSphere(objeto, 0.018f, 26, 13);
    glPopMatrix();
}
void Boneco::nariz()
{
    glColor3f(1.0f, 0.4f, 0.51f);
    glPushMatrix();
    glTranslatef(0.0f, 1.0f, 0.2f);
    gluCylinder(objeto, 0.04f, 0.0f, 0.3f, 26, 13);
    glPopMatrix();
}
void Boneco::boca()
{
    glColor3f(1.0f, 0.0f, 0.0f);
    glPushMatrix();
    glTranslatef(0.0f, 0.9f, 0.1f);
    glRotatef(90.0f, 3.5f, -0.3f, 0.0f);
    gluCylinder(objeto, 0.15f, 0.0f, 0.06f, 22, 13);
    glPopMatrix();
}

void Boneco::corpo()
{
    glColor3f(1.0f, 1.0f, 1.0f);

    // Bola de baixo
    gluSphere(objeto, .40f, 26, 13); // Bottom

    glColor3f(1.0f, 1.0f, 0.7f);
    gluSphere(objeto, .401f, 26, 13); // Bottom

    // Bola de cima
    glPushMatrix();
    glTranslatef(0.0f, 0.55f, 0.0f);
    gluSphere(objeto, .3f, 26, 13);
    glPopMatrix();
}