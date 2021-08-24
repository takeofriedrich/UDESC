#include "Tela.hpp"
#include <iostream>

GLfloat Tela::yRot{0.0f};
GLfloat Tela::xRot{0.0f};
GLfloat Tela::angle{0.0f};
GLfloat Tela::lx{2.0f};
GLfloat Tela::lz{-20.0f};
GLfloat Tela::x{5.0f};
GLfloat Tela::z{25.0f};
GLUquadricObj *Tela::objeto;
Robo *Tela::robo;

Tela::Tela()
{
}

void Tela::setRobo(Robo *robo)
{
    Tela::robo = robo;
}

void Tela::create_screen(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(largura, altura);
    glutCreateWindow(nome.c_str());
    glutReshapeFunc(Tela::change_size);
    glutKeyboardFunc(Tela::special_keys);
    glutDisplayFunc(Tela::render_scene);
    setup_rc();
    glutMainLoop();
}

void Tela::change_size(int w, int h)
{
    GLfloat fAspect;

    // Prevent a divide by zero
    if (h == 0)
        h = 1;

    // Set Viewport to window dimensions
    glViewport(0, 0, w, h);

    fAspect = (GLfloat)w / (GLfloat)h;

    // Reset coordinate system
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    // Produce the perspective projection
    gluPerspective(35.0f, fAspect, 1.0, 40.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

// This function does any needed initialization on the rendering context.  Here it sets up and initializes the lighting for the scene.
void Tela::setup_rc()
{

    // Light values and coordinates
    GLfloat whiteLight[] = {0.05f, 0.05f, 0.05f, 1.0f};
    GLfloat sourceLight[] = {0.25f, 0.25f, 0.25f, 1.0f};
    GLfloat lightPos[] = {-10.f, 5.0f, 5.0f, 1.0f};

    glEnable(GL_DEPTH_TEST); // Hidden surface removal
    glFrontFace(GL_CCW);     // Counter clock-wise polygons face out
    glEnable(GL_CULL_FACE);  // Do not calculate inside

    // Enable lighting
    glEnable(GL_LIGHTING);

    // Setup and enable light 0
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, whiteLight);
    glLightfv(GL_LIGHT0, GL_AMBIENT, sourceLight);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, sourceLight);
    glLightfv(GL_LIGHT0, GL_POSITION, lightPos);
    glEnable(GL_LIGHT0);

    // Enable color tracking
    glEnable(GL_COLOR_MATERIAL);

    // Set Material properties to follow glColor values
    glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);

    // Black blue background
    glClearColor(0.25f, 0.25f, 0.50f, 1.0f);
}

// Respond to arrow keys (rotate snowman)
void Tela::special_keys(unsigned char key, int x, int y)
{
    float fraction = 0.1f;

    switch (key)
    {
    case 'a':
        angle -= 0.01f;
        lx = sin(angle);
        lz = -cos(angle);
        Tela::robo->olharParaEsquerda();
        break;
    case 'd':
        angle += 0.01f;
        lx = sin(angle);
        lz = -cos(angle);
        Tela::robo->olharParaDireita();
        break;
    case 'w':
        Tela::robo->mexerBracos();
        x += lx * fraction;
        z += lz * fraction;

        break;
    case 's':
        x -= lx * fraction;
        z -= lz * fraction;

        break;
    case 'q':
        yRot -= 5.0f;
        break;
    case 'e':
        yRot += 5.0f;
        break;
    }

    // Refresh the Window
    glutPostRedisplay();
}

void Tela::render_scene(void)
{

    // Clear the window with current clearing color
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Save the matrix state and do the rotations
    glPushMatrix();

    // Move object back and do in place rotation
    glTranslatef(0.0f, -1.0f, -5.0f);

    // gluLookAt(Tela::x, 0.0f, Tela::z + 2,
    //           Tela::x + Tela::lx, 1.0f, Tela::z + Tela::lz + 2,
    //           0.0f, 1.0f, 0.0f);

    gluLookAt(-25, -2.75f, 0,
              150, 1, 10,
              0, 1, 0);

    glRotatef(Tela::yRot, 0.0f, 1.0f, 0.0f);

    // Draw something
    Tela::objeto = gluNewQuadric();
    gluQuadricNormals(Tela::objeto, GLU_SMOOTH);

    Tela::robo->setObjeto(Tela::objeto);
    Tela::robo->desenha();

    // white
    glColor3f(1.0f, 1.0f, 1.0f);

    // Hat brim

    // Restore the matrix state
    glPopMatrix();

    // Buffer swap
    glutSwapBuffers();
}
