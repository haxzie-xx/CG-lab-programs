#include<GL/glut.h>
#include<stdio.h>
#include<math.h>

float angle = 0.0;
int repeat = 0;


float v[3][2] = { {250, 100}, {250, 250}, {350, 200} };

void init()
{
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glColor3f(0.0, 0.0, 0.0);
	gluOrtho2D(0.0, 500.0, 0.0, 500.0);
}

void triangle(){
	glBegin(GL_TRIANGLES);
		glColor3f(1.0, 0.5, 0.0);
		glVertex2fv(v[0]);
		glColor3f(.2, 0.7, 0.4);
		glVertex2fv(v[1]);
		glColor3f(0.0, 0.2, 0.4);
		glVertex2fv(v[2]);
	glEnd();
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	triangle();
	int i;
	for(i =0; i < repeat; i++)
	{
		glPushMatrix();
		glTranslatef(v[1][0],v[1][1],0.0);
		glRotatef(angle,0.0,0.0,1.0);
		glTranslatef(-v[1][0],-v[1][1],0.0);
		triangle();
	}
	
	glPopMatrix();
	glFlush();
}

int main(int argc, char **argv)
{

	printf("\nEnter the degree to rotate and repeat count\n");
	scanf("%f%d", &angle, &repeat);

	
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(700, 700);
	glutInitWindowPosition(10, 10);
	glutCreateWindow("Rotation");
	init();
	glutDisplayFunc(display);
	glutMainLoop();
	
}
