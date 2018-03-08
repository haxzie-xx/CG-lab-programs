#include <stdio.h>
#include <GL/glut.h>

void init()
{
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glColor3f(0.0, 0.0, 0.0);
	gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	
	glBegin(GL_TRIANGLE_FAN);
		glColor4f(0.7,0.1,0.4, 0.3);
		glVertex2f(0.0, 0.8);
		glColor4f(0.5,0.2,0.5, 0.3);
		glVertex2f(0.6, 0.6);
		glColor4f(0.4,0.1,0.3, 0.3);
		glVertex2f(0.8, 0.0);
		glColor4f(0.3,0.3,0.2, 0.3);
		glVertex2f(0.6, -0.6);
		glColor4f(0.2,0.4,0.4, 0.3);
		glVertex2f(0.0, -0.8);
		glColor4f(0.3,0.5,0.7, 0.3);
		glVertex2f(-0.6, -0.6);
		glColor4f(0.4,0.6,0.3, 0.3);
		glVertex2f(-0.8, 0.0);
		glColor4f(0.5,0.7,0.1, 0.3);
		glVertex2f(-0.6, 0.6);
	glEnd();
	
	glBegin(GL_TRIANGLE_FAN);
		glColor4f(0.7,0.1,0.4, 0.3);
		glVertex2f(0.0, 0.4);
		glColor4f(0.5,0.2,0.5, 0.3);
		glVertex2f(0.3, 0.3);
		glColor4f(0.4,0.1,0.3, 0.3);
		glVertex2f(0.4, 0.0);
		glColor4f(0.3,0.3,0.2, 0.3);
		glVertex2f(0.3, -0.3);
		glColor4f(0.2,0.4,0.4, 0.3);
		glVertex2f(0.0, -0.4);
		glColor4f(0.3,0.5,0.7, 0.3);
		glVertex2f(-0.3, -0.3);
		glColor4f(0.4,0.6,0.3, 0.3);
		glVertex2f(-0.4, 0.0);
		glColor4f(0.5,0.7,0.1, 0.3);
		glVertex2f(-0.3, 0.3);
	glEnd();
	/*
	glBegin(GL_TRIANGLE_FAN);
		glColor4f(0.7,0.1,0.4, 0.3);
		glVertex2f(0.3, 0.8);
		glVertex2f(0.6, 0.6);
		glVertex2f(0.8, 0.0);
		glVertex2f(0.6, -0.6);
		glVertex2f(0.0, -0.8);
		glVertex2f(-0.6, 0.6);
		glVertex2f(-0.8, 0.0);
		glVertex2f(-0.6, -0.6);
	glEnd();
	*/
	glFlush();
	
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(500,500);
	glutInitWindowPosition(20, 30);
	glutCreateWindow("FLower");
	init();
	glutDisplayFunc(display);
	glutMainLoop();
}
