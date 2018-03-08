#include<GL/glut.h>
#include<stdio.h>
#include<math.h>

void init()
{
	glCLearColor(1.0, 1.0, 1.0, 1.0);
	glColor3f(0.0, 0.0, 0.0);
	gluOrtho2D()0.0, 500.0, 0.0, 500.0);
}


