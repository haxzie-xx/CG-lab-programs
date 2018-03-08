#include <stdio.h>
#include <GL/glut.h>

void init();
void drawTriangle(GLfloat*, GLfloat*, GLfloat*);
void divideTriangle(GLfloat*, GLfloat*, GLfloat*, int);
void display();
int col = 0;	

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

void init()
{
	glClearColor(1.0,1.0,1.0,1.0);
	glColor3f(0.0,0.0,0.0);
	gluOrtho2D(0.0, 500.0, 0.0, 500.0);
}

void drawTriangle(GLfloat *A, GLfloat *B, GLfloat *C)
{
	glVertex2fv(A);
	glVertex2fv(B);
	glVertex2fv(C);
	
}

void divideTriangle(GLfloat *A, GLfloat *B, GLfloat *C, int divisions)
{
	GLfloat m0[2], m1[2], m2[2];
	int j;
	
	if (divisions > 0)
	{
		for ( j = 0; j < 2; j++)
		{
			m0[j] = (A[j]+B[j])/2.0;
			m1[j] = (B[j]+C[j])/2.0;
			m2[j] = (A[j]+C[j])/2.0;
		}
		

		divideTriangle(A, m0, m2, divisions-1);

		divideTriangle(B, m0, m1, divisions-1);

		divideTriangle(C, m1, m2, divisions-1);
	}
	else
	{
		col++;
		switch(col % 3){
			case 0:
				glColor3f(0.5, 1.0, 0.2);
				break;
			case 1:
				glColor3f(0.5, 0.5, 1.0);
				break;
			case 2:
				glColor3f(0.4, 0.6, 0.4);
				break;
			default:
				glColor3f(0.0, 0.0, 0.0);
				break;
		}			

		drawTriangle(A, B, C);
	}
	
}

void display()
{
	GLfloat A[2] = {100.0, 100.0};
	GLfloat B[2] = {250.0, 400.0};
	GLfloat C[2] = {400.0, 100.0};
	
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_TRIANGLES);
		divideTriangle(A, B, C, 3);
	glEnd();
	glFlush();
}










