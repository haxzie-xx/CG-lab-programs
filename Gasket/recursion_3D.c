#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void init() 
{
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
}

void drawTriangle(GLfloat *a, GLfloat *b, GLfloat *c)
{
	glVertex3fv(a);
	glVertex3fv(b);
	glVertex3fv(c);
}

void drawTetra(GLfloat *a, GLfloat *b, GLfloat *c, GLfloat *d)
{
	//back
	glColor3f(0.0, 0.0, 0.0);
	drawTriangle(a, b, c);
	//bottom
	glColor3f(0.7,0.1,0.4);
	drawTriangle(a, b, d);
	//left
	glColor3f(0.9,0.5,0);
	drawTriangle(a, d, c);
	//right
	glColor3f(0.7,0.7,0);
	drawTriangle(d, b, c);
}

void divideTetra(GLfloat *a, GLfloat *b, GLfloat *c, GLfloat *d, int divisions)
{
	int i;
	int k = divisions;
	GLfloat ab[3], bc[3], ac[3], ad[3], bd[3], cd[3];
	
	if (divisions > 0) 
	{
		for( i= 0; i < 3; i++)
		{
			ab[i] = (a[i] + b[i])/2;
			bc[i] = (b[i] + c[i])/2;
			ac[i] = (a[i] + c[i])/2;
			ad[i] = (a[i] + d[i])/2;
			bd[i] = (b[i] + d[i])/2;
			cd[i] = (c[i] + d[i])/2;
		}
		
		divideTetra(a, ab, ac, ad, k-1);
		divideTetra(ab, b, bc, bd, k-1);
		divideTetra(ac, bc, c, cd, k-1);
		divideTetra(ad, bd, cd, d, k-1);
		
	}
	else
	{
		drawTetra(a, b, c, d);
	}
}

void display()
{
	GLfloat a[3] = {-1, -1, -1};
	GLfloat b[3] = {1, -1, -1};
	GLfloat c[3] = {0, 1, -1};
	GLfloat d[3] = {0, 0, 1};
	
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glBegin(GL_TRIANGLES);
		divideTetra(a, b, c, d, 2);
	glEnd();
	glFlush();
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB|GLUT_SINGLE|GLUT_DEPTH);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(20, 30);
	glutCreateWindow("3D Sierpinski's Gasket");
	glEnable(GL_DEPTH_TEST);
	glutDisplayFunc(display);
	init();
	glutMainLoop();
	return 0;
}






