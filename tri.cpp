/*
Taylor Condrack
Program 1
4230
01/25/16
*/
#include <cstdlib>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include<time.h>

typedef GLfloat vert[2];

double v1x=.25;
double v1y=.25;
double v2x=.75;
double v2y=.25;
double v3x=.5;
double v3y=.75;
static int n=60000;

void tri(vert one, vert two, vert three)
{
    glBegin(GL_POINTS);
        glVertex2fv(one);
        glVertex2fv(two);
        glVertex2fv(three);
    glEnd();
}

void chaos(double,double,double,double,double,double,int p)
{
    srand(time(NULL));
    double cur1=0;
    double cur2=0;
    int inc=1;
        glBegin(GL_POINTS);
            glVertex2d(v1x,v1y);
            glVertex2d(v2x,v2y);
            glVertex2d(v3x,v3y);
            glEnd();

        for(int i=0;i<p;i++)
        {
            if(inc%3==0)
            {
                cur1=(v1x+cur1)/2;
                cur2=(v1y+cur2)/2;
            }
            else if(inc%3==1)
            {
                cur1=(v2x+cur1)/2;
                cur2=(v2y+cur2)/2;
            }
            else
            {
                cur1=(v3x+cur1)/2;
                cur2=(v3y+cur2)/2;
            }
            inc=rand()%3+1;
            inc++;

            glBegin(GL_POINTS);
            glVertex2d(cur1,cur2);
            glEnd();

        }
}

void display(void)
{
    glClear (GL_COLOR_BUFFER_BIT);

    int p=n;
    chaos(v1x,v1y,v2x,v2y,v3x,v3y,p);

    glFlush ();
}
void reshape(int w, int h)
{
    glViewport(0,0,w, h);
}
void reshapecallback()
{
   glClearColor (0.0, 0.0, 0.0, 0.0);

    //glViewport(0,0,(GLsizei) w, (GLsizei) h);
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
    glMatrixMode(GL_MODELVIEW);
    glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);

}
void keyboard(unsigned char key,int x, int y)
{
    switch(key)
    {
        case 27:
            exit(0);
        break;
    }

}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize (500, 500);
    glutInitWindowPosition (100, 100);
    glutCreateWindow ("Chaos Game");
    reshapecallback();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
   return 0;
}

