#include <GL/glut.h> // Header File For The GLUT Library
#include <GL/gl.h>   // Header File For The OpenGL32 Library
#include <GL/glu.h>  // Header File For The GLu32 Library
#include <SDL/SDL.h>
#include <math.h>
#include <unistd.h>

static GLfloat zPos = -60.0f;
GLfloat yRot = 0.0f;

#define TEXTURE_COLUNA 0
#define TEXTURE_CAPA_TRASEIRA 1
#define TEXTURE_CAPA 2
#define TEXTURE_COUNT 3
GLuint textures[TEXTURE_COUNT];
const char *szTextureFiles[TEXTURE_COUNT] = {"meio.bmp", "contra.bmp", "capa.bmp"};

///////////////////////////////////////////////////////////////////////////////
// Change texture filter for each texture object
void ProcessMenu(int value)
{
    GLint iLoop;

    for (iLoop = 0; iLoop < TEXTURE_COUNT; iLoop++)
    {
        glBindTexture(GL_TEXTURE_2D, textures[iLoop]);

        switch (value)
        {
        case 0:
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
            break;

        case 1:
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
            break;

        case 2:
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST_MIPMAP_NEAREST);
            break;

        case 3:
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST_MIPMAP_LINEAR);
            break;

        case 4:
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_NEAREST);
            break;

        case 5:
        default:
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
            break;
        }
    }

    // Trigger Redraw
    glutPostRedisplay();
}

//////////////////////////////////////////////////////////////////
// This function does any needed initialization on the rendering
// context.  Here it sets up and initializes the texture objects.
void SetupRC()
{
    GLint iLoop;

    // Black background
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

    // Textures applied as decals, no lighting or coloring effects
    glEnable(GL_TEXTURE_2D);
    glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);

    // Load textures
    glGenTextures(TEXTURE_COUNT, textures);
    SDL_Surface *TextureImage;
    for (iLoop = 0; iLoop < TEXTURE_COUNT; iLoop++)
    {
        // Bind to next texture object
        glBindTexture(GL_TEXTURE_2D, textures[iLoop]);

        // Load texture, set filter and wrap modes
        TextureImage = SDL_LoadBMP(szTextureFiles[iLoop]);

        // Load texture, set filter and wrap modes
        gluBuild2DMipmaps(GL_TEXTURE_2D, 3, TextureImage->w, TextureImage->h, GL_BGR, GL_UNSIGNED_BYTE, TextureImage->pixels);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

        // Don't need original texture data any more
        SDL_FreeSurface(TextureImage);
    }
}

///////////////////////////////////////////////////
// Shutdown the rendering context. Just deletes the
// texture objects
void ShutdownRC(void)
{
    glDeleteTextures(TEXTURE_COUNT, textures);
}

///////////////////////////////////////////////////
// Respond to arrow keys, move the viewpoint back
// and forth
void SpecialKeys(unsigned char key, int x, int y)
{
    if (key == 'w')
    {
        printf("W\n");
        zPos += 1.0f;
    }

    if (key == 's')
    {
        printf("S\n");
        zPos -= 1.0f;
    }

    if (key == 'q')
    {
        printf("Q\n");
        yRot += 1.0f;
    }

    if (key == 'e')
    {
        printf("E\n");
        yRot -= 1.0f;
    }

    printf("%f\n", yRot);

    glutPostRedisplay();
}

/////////////////////////////////////////////////////////////////////
// Change viewing volume and viewport.  Called when window is resized
void ChangeSize(int w, int h)
{
    GLfloat fAspect;

    // Prevent a divide by zero
    if (h == 0)
        h = 1;

    glViewport(0, 0, w, h);

    fAspect = (GLfloat)w / (GLfloat)h;

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluPerspective(90.0f, fAspect, 1, 120);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void capa(GLfloat z)
{
    // Save the matrix state and do the rotations
    glPushMatrix();
    // Move object back and do in place rotation
    glTranslatef(0.0f, 0.0f, -60);
    glRotatef(90, 0, 1, 0);
    glRotatef(180, 1, 0, 0);

    // Capa
    glBindTexture(GL_TEXTURE_2D, textures[TEXTURE_CAPA_TRASEIRA]);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-10.0f, -10.0f, z);

    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(-10.0f, -10.0f, z - 10.0f);

    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(-10.0f, 10.0f, z - 10.0f);

    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-10.0f, 10.0f, z);
    glEnd();

    // Restore the matrix state
    glPopMatrix();
}

///////////////////////////////////////////////////////
// Called to draw scene
void RenderScene(void)
{

    // Clear the window with current clearing color
    glClear(GL_COLOR_BUFFER_BIT);

    glRotatef(yRot, 0.0f, 1, 0.0f);
    GLfloat z;

    capa(z);

    // Buffer swap
    glutSwapBuffers();
}

//////////////////////////////////////////////////////
// Program entry point
int main(int argc, char *argv[])
{
    // Standard initialization stuff
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Tunnel");
    glutReshapeFunc(ChangeSize);
    glutKeyboardFunc(SpecialKeys);
    glutDisplayFunc(RenderScene);

    // Add menu entries to change filter
    glutCreateMenu(ProcessMenu);
    glutAddMenuEntry("GL_NEAREST", 0);
    glutAddMenuEntry("GL_LINEAR", 1);
    glutAddMenuEntry("GL_NEAREST_MIPMAP_NEAREST", 2);
    glutAddMenuEntry("GL_NEAREST_MIPMAP_LINEAR", 3);
    glutAddMenuEntry("GL_LINEAR_MIPMAP_NEAREST", 4);
    glutAddMenuEntry("GL_LINEAR_MIPMAP_LINEAR", 5);
    glutAttachMenu(GLUT_RIGHT_BUTTON);

    // Startup, loop, shutdown
    SetupRC();
    glutMainLoop();
    ShutdownRC();

    return 0;
}
