#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <math.h>
#include <unistd.h>

#define ESCAPE 27
#define NUM_PARTICLES 3500
#define GRAVITY 0.0007

struct s_pf
{
  float x, y, veloc_x, veloc_y;
  unsigned lifetime;
} particles[NUM_PARTICLES];

int window;

float gerar(float max)
{
  return ((float)rand() / (float)(RAND_MAX)) * max;
}

void InitParticle(int pause)
{
  int i;

  if (pause)
    usleep(2000 + rand() % 2000);

  unsigned char change = 0;

  for (i = 0; i < NUM_PARTICLES; i++)
  {
    float velocity = (float)(rand() % 110) / 5000.0;
    particles[i].x = -6 + gerar(12);
    particles[i].y = -6 + gerar(12);
    if (change == 0)
    {
      particles[i].veloc_x = -gerar(1) * velocity;
      change = 1;
    }
    else
    {
      particles[i].veloc_x = gerar(1) * velocity;
      change = 0;
    }

    particles[i].veloc_y = velocity * GRAVITY;
    particles[i].lifetime = 50 + rand() % 50;
  }
}

void InitGL(int Width, int Height)
{
  glClearColor(0.176f, 0.224f, 0.230f, 0.0f);
  glClearDepth(1.0);
  glDepthFunc(GL_LESS);
  glEnable(GL_DEPTH_TEST);
  glShadeModel(GL_SMOOTH);

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();

  gluPerspective(45.0f, (GLfloat)Width / (GLfloat)Height, 0.1f, 100.0f);
  glMatrixMode(GL_MODELVIEW);

  InitParticle(0);
}

void ReSizeGLScene(int Width, int Height)
{
  if (Height == 0)
    Height = 1;

  glViewport(0, 0, Width, Height);

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();

  gluPerspective(45.0f, (GLfloat)Width / (GLfloat)Height, 0.1f, 100.0f);
  glMatrixMode(GL_MODELVIEW);
}

void DrawGLScene()
{
  int i, ative_particles = 0;
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glLoadIdentity();

  glTranslatef(0.0f, 0.0f, -8.0f);

  glBegin(GL_POINTS);

  for (i = 0; i < NUM_PARTICLES; i++)
  {
    if (particles[i].lifetime)
    {
      ative_particles++;
      particles[i].veloc_y -= GRAVITY;
      particles[i].x += particles[i].veloc_x;
      particles[i].y += particles[i].veloc_y;
      particles[i].lifetime--;

      glVertex3f(particles[i].x, particles[i].y, 0.0f);
    }
  }
  glEnd();

  glutSwapBuffers();

  if (!ative_particles)
    InitParticle(1);
}

void keyPressed(unsigned char key, int x, int y)
{

  if (key == ESCAPE)
  {
    glutDestroyWindow(window);

    exit(0);
  }
}

int main(int argc, char **argv)
{
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_ALPHA | GLUT_DEPTH);
  glutInitWindowSize(640, 480);
  glutInitWindowPosition(0, 0);
  window = glutCreateWindow("Chuva com um pouco de vento");
  glutDisplayFunc(&DrawGLScene);
  glutFullScreen();
  glutIdleFunc(&DrawGLScene);
  glutReshapeFunc(&ReSizeGLScene);
  glutKeyboardFunc(&keyPressed);
  InitGL(640, 480);
  glutMainLoop();

  return 0;
}
