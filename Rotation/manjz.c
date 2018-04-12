#include<GL/glut.h>
#include<stdio.h>
float a;
void display();
void display1();
void init();
void triangle();
void triangle1();
int main(int argc,char ** argv)
{
	printf("enter the angle\n");
	scanf("%f",&a);
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(700,700);
	glutCreateWindow("Trinagle Rotation");
	init();
	glutDisplayFunc(display);
	//glutDisplayFunc(display1);
	glutMainLoop();

}
void init()
{
	glClearColor(1.0,1.0,1.0,0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0,130,0,130);
	glMatrixMode(GL_MODELVIEW);
}
void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();

	
	triangle();
	glPushMatrix();
	glRotatef(a,0,0,1);
	triangle();
	glPopMatrix();
	glFlush(); 

	
	
	triangle();
	glTranslatef(50,60,0);
	glRotatef(a,0,0,1);
	glTranslatef(-30,-30,0);
	triangle();
	glFlush();
	 
	
	

}

void display1()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();
	triangle();
	glTranslatef(30,30,0);
	glRotatef(a,0,0,1);
	glTranslatef(-30,-30,0);
	triangle();
	glFlush();

}

void triangle()
{
	glColor3f(1.0,0.0,1.0);
	glBegin(GL_POLYGON);
	glVertex2f(30,30);
	glColor3f(0.45,0.0,1.0);
	glVertex2f(70,30);
	glColor3f(0.0,0.36,1.0);
	glVertex2f(50,60);
	glEnd();
}

void triangle1()
{
	glColor3f(1.0,0.0,1.0);
	glBegin(GL_POLYGON);
	glVertex2f(30,30);
	glColor3f(0.45,0.0,1.0);
	glVertex2f(70,30);
	glColor3f(0.0,0.36,1.0);
	glVertex2f(50,60);
	glEnd();
}