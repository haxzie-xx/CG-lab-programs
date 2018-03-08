#include <stdio.h>
#include <GL/glut.h>

void init()
{
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glColor3f(0.0, 0.0, 0.0);
	gluOrtho2D(0.0, 500.0, 0.0, 500.0);
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_TRIANGLE_FAN);
		glColor3f(0.5, 0.5, 0.5);
		glVertex2f(100, 250);
		glColor3f(0.2, 0.4, 0.7);
		glVertex2f(250, 400);
		glColor3f(0.5, 0.5, 0.9);
		glVertex2f(350, 350);
		glColor3f(0.6, 0.1, 0.3);
		glVertex2f(400, 250);
		glColor3f(0.9, 0.8, 0.3);
		glVertex2f(350, 150);
		glColor3f(0.1, 0.8, 0.5);
		glVertex2f(250, 100);
	glEnd();
	glFlush();
	

	// glBegin(GL_TRIANGLE_STRIP);	
	// glVertex3f( 0.0f, 1.0f, 0.0f ); //vertex 1
	// glVertex3f( 0.0f, 0.0f, 0.0f ); //vertex 2
	// glVertex3f( 1.0f, 1.0f, 0.0f ); //vertex 3
	// glVertex3f( 1.5f, 0.0f, 0.0f ); //vertex 4
	// glEnd();
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(500,500);
	glutInitWindowPosition(20, 30);
	glutCreateWindow("2D Serpenski's Gasket Traingle");
	init();
	glutDisplayFunc(display);
	glutMainLoop();
}
