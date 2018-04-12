#include<stdio.h>
#include<GL/glut.h>


void init()
{
    
    glClearColor(1.0, 1.0, 1.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-90.0, 90.0, -90.0, 90.0, -90.0, 90.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void display()
{

    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    GLfloat mat_specular[] = {1.0, 5.0, 5.0, 1.0}; /* bright white */
    GLfloat mat_diffuse[] = {1.0, 0.5, 0.0, 1.0}; /* orange color */
    GLfloat mat_ambient[] = {1.0, 0.5, 0.0, 1.0}; /* same as diffuse */
    GLfloat mat_shininess = 5.0;
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
    glMaterialf(GL_FRONT, GL_SHININESS, mat_shininess);

    GLfloat lightIntensity1[]={0.5f,0.5f,0.5f,1.0f};
    GLfloat light_position1[]={25.0f,50.0f,50.0f,1.0f};
    glLightfv(GL_LIGHT0, GL_POSITION,light_position1);
    glLightfv(GL_LIGHT0,GL_DIFFUSE,lightIntensity1);

    glColor3f(5.0, 3.0, 5.0);
    glutSolidTeapot(50);
    glFlush();
	glutSwapBuffers();

}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB|GLUT_DOUBLE|GLUT_DEPTH);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(20, 30);
	glutCreateWindow("3D TEAPOT");
	glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
	//glPolygonStipple(patt);
	
	init();
	glutDisplayFunc(display);
	
	glutMainLoop();
	return 0;
}


