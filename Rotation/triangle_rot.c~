#include<GL/glut.h>
#include<stdio.h>
#include<math.h>

float angle = 0.0;
int repeat = 0;


float v[3][2] = { {150, 100}, {250, 350}, {350, 100} };

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
	glBegin(GL_LINES);
		glColor3f(0.0, 0.0, 0.0);
		glLineWidth(10);
		glVertex2fv(v[0]);
		glVertex2fv(v[1]);
		glVertex2fv(v[2]);
		glVertex2fv(v[0]);
		glColor3f(0.0, 0.0, 0.0);
	glEnd();
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	triangle();

/*
	glPushMatrix();
	glTranslatef(v[1][0],v[1][1],0.0);
	glRotatef(angle,0.0,0.0,1.0);
	glTranslatef(-v[1][0],-v[1][1],0.0);
	triangle();
	glPopMatrix();
	
	glPushMatrix();
	glTranslatef(250,250,0.0);
	glRotatef(angle,0.0,0.0,1.0);
	glTranslatef(-250,-250,0.0);
	triangle();
	glPopMatrix();
*/
	glFlush();
}

int main(int argc, char **argv)
{

	printf("\nEnter the rotation angele\n");
	scanf("%f", &angle);
	
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(700, 700);
	glutInitWindowPosition(10, 10);
	glutCreateWindow("Rotation");
	init();
	glutDisplayFunc(display);
	glutMainLoop();
	
}
