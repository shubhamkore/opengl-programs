#include<GL/gl.h>
#include<GL/glu.h>
#include<GL/glut.h>
void display();
void reshape(int,int);
void init()
{
    glClearColor(0.0,0.0,0.0,0.0);
}
int main(int argc,char**argv)
{
    glutInit(&argc,argv);

    glutInitDisplayMode(GLUT_RGB|GLUT_RGBA);

    glutInitWindowPosition(100,100);

    glutInitWindowSize(500,500);

    glutCreateWindow("window 1");


    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    init();
    glutMainLoop();


}


void display()
{
    glClear(GL_COLOR_BUFFER_BIT);//for clear the frame buffer
    glLoadIdentity();//it resets the matrix/reset coordinate function/..

    glBegin(GL_POLYGON);
    glColor3f(1.0,0.0,1.0);
    glVertex2f(3.0,-3.0);
    glColor3f(1.0,0.0,0.4);
    glVertex2f(-3.0,-3.0);
    glColor3f(0.6,0.0,1.0);
    glVertex2f(-5.0,0.0);
    glColor3f(1.0,0.8,1.0);
    glVertex2f(-3.0,3.0);
    glColor3f(1.0,0.2,1.0);
    glVertex2f(3.0,3.0);
    glColor3f(0.5,0.0,1.0);
    glVertex2f(5.0,0.0);

    glEnd();
    glFlush();//to display frame buffer on the screen
}


void reshape(int w,int h)
{
    glViewport(0,0,(GLsizei)w,(GLsizei)h);
    glMatrixMode(GL_PROJECTION);//to change matrix mode
        glLoadIdentity();//resets the parameters of projection matrix
        gluOrtho2D(-10,10,-10,10);
        glMatrixMode(GL_MODELVIEW);
}
