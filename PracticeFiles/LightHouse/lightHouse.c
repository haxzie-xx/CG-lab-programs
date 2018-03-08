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
	
	//background_sand
	glColor3f(0.9,0.5,0);
	glBegin(GL_POLYGON);
		glVertex2f(0, 0);
		glVertex2f(0, 150);
		glColor3f(0.9,0.0,0.4);
		glVertex2f(500, 300);
		glVertex2f(500,0);
	glEnd();
	
	//Lighthouse_body
	glColor3f(1.0, 0.2, 0.3);
	glBegin(GL_POLYGON);
		glVertex2f(200, 100);
		glVertex2f(220, 96);
		glVertex2f(230, 93);
		glVertex2f(250, 90);
		glVertex2f(270, 93);
		glVertex2f(280, 96);
		glVertex2f(300, 100);
		glCOlor2f(0.7,0.1,0.4);
		glVertex2f(270, 400);
		glVertex2f(230, 400);
		
	glEnd();
	
	//Lighthouse door
	glColor3f(0.3, 0.3, 0.3);
	glBegin(GL_POLYGON);
		glVertex2f(220, 96);
		glVertex2f(230, 93);
		glVertex2f(250, 90);
		glVertex2f(245, 145);
		glVertex2f(233, 152);
		glVertex2f(223 ,150);
	glEnd();
	
	glColor3f(0.9,0.5,0);
	glBegin(GL_POLYGON);
		glVertex2f
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
