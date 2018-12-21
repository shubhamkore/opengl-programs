#include<GL/gl.h>
#include<GL/glu.h>
#include<GL/glut.h>
void display();
void reshape(int,int);
void timer(int);
void init()
{
    glClearColor(0.0,0.0,0.0,0.0);
}
int main(int argc,char**argv)
{
    glutInit(&argc,argv);

    glutInitDisplayMode(GLUT_RGB|GLUT_DOUBLE);

    glutInitWindowPosition(100,100);

    glutInitWindowSize(500,500);

    glutCreateWindow("window 1");


    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutTimerFunc(0,timer,0);
    init();
    glutMainLoop();


}

float x_position=0.0;
int state=1;


void display()
{
    glClear(GL_COLOR_BUFFER_BIT);//for clear the frame buffer
    glLoadIdentity();//it resets the matrix/reset coordinate function/..
     glTranslatef(x_position,0.0,0.0);
    //draw
    // glPointSize(10.0);
    glBegin(GL_POLYGON);
    glColor3f(1.0,0.0,0.0);
    glVertex2f(-1.0,1.0);
    glColor3f(0.0,1.0,0.0);

    glVertex2f(-1.0,-1.0);
    glColor3f(1.0,0.0,1.0);
    glVertex2f(1.0,-1.0);
    glColor3f(1.0,1.0,.0);

    glVertex2f(1.0,1.0);
    glEnd();
    glutSwapBuffers();
   // glFlush();//to display frame buffer on the screen
}


void reshape(int w,int h)
{
    glViewport(0,0,(GLsizei)w,(GLsizei)h);
    glMatrixMode(GL_PROJECTION);//to change matrix mode
        glLoadIdentity();//resets the parameters of projection matrix
        gluOrtho2D(-10,10,-10,10);
        glMatrixMode(GL_MODELVIEW);


}

void timer(int)
{
    glutPostRedisplay();
    glutTimerFunc(1000/60,timer,0);
    switch(state)
    {
 case 1:
     if(x_position<9)
    x_position+=0.15;
    else
        state=-1;
    break;
 case -1:
    if(x_position>-9)
    x_position-=0.15;
    else
        state=1;
    break;

    }


}
