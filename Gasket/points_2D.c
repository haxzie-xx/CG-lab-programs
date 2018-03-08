#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <GL/glut.h>

int v[3][2] = {{100, 100}, {250, 450}, {400, 100}};
int p[2] = {150, 150};
int i;

void init()
{
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0.0, 500.0, 0.0, 500.0);
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	
	for( i=0; i<100000; i++)
	{
		int j = rand() % 3;
		glBegin(GL_POINTS);
			switch (j){
				case 0:
					glColor3f(0.7, 0.3, 0.2);
					break;
				case 1:
					glColor3f(0.4, 0.2, 0.8);
					break;
				default:
					glColor3f(0.4, 0.8, 0.0);
					break;
			}
			p[0] = (p[0] + v[j][0]) /2;
			p[1] = (p[1] + v[j][1]) /2;
			glVertex2iv(p);
		glEnd();
	}
	
	glFlush();
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(20, 30);
	glutCreateWindow("2D Sierpenski's Gasket using Points");
	init();
	glutDisplayFunc(display);
	glutMainLoop();
	
}
