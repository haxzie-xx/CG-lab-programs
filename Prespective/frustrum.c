#include<stdio.h>
#include<GL/glut.h>

void init()
{
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-2.0,2.0,-2.0,2.0,2.0,20.0);
    gluPerspective(45, 1.333, 0, 100);
    glMatrixMode(GL_MODELVIEW);
    gluLookAt(0,0,0,0,0,0,0,1,0);
    glLoadIdentity();
}

void display()
{
 
    // GLfloat mat_specular[] = {1.0, 1.0, 1.0, 1.0}; /* bright white */
    // GLfloat mat_diffuse[] = {1.0, 0.5, 0.0, 1.0}; /* orange color */
    // GLfloat mat_ambient[] = {1.0, 0.5, 0.0, 1.0}; /* same as diffuse */
    // GLfloat mat_shininess = 5.0;

    // glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    // GLfloat lightIntensity1[]={0.5f,0.5f,0.5f,1.0f};
    // GLfloat light_position1[]={25.0f,50.0f,50.0f,1.0f};
    // glLightfv(GL_LIGHT0, GL_POSITION,light_position1);
    // glLightfv(GL_LIGHT0,GL_DIFFUSE,lightIntensity1);

    // glutSolidCube(1.0);

    glColor3f(0.5, 0.2, 0.7);
    glBegin(GL_POLYGON);
        glVertex3f(-1.0, -1.0, 1.0);
        glVertex3f(1.0, -1.0, 1.0);
        glVertex3f(1.0, 1.0, 1.0);
        glVertex3f(-1.0, 1.0, 1.0);
    glEnd();
    glFlush();
    glutSwapBuffers();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB|GLUT_DOUBLE|GLUT_DEPTH);
    glutInitWindowSize(600, 600);
    glutInitWindowPosition(20, 30);
    glutCreateWindow("Prespective Cube");
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}