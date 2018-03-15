#include<stdio.h>
#include<GL/glut.h>

GLfloat vertex[8][3] = { 	{-30.0, 30.0, 30.0},
				{30.0, 30.0, 30.0 },
				{30.0, -30.0, 30.0},
				{-30.0, -30.0, 30.0},
				{-30.0, 30.0, -30.0},
				{30.0, 30.0, -30.0},
				{30.0, -30.0, -30.0},
				{-30.0, -30.0, -30.0}};

GLfloat colors[6][3] = { 
				{0.6, 0.2, 0.2},
				{0.5, 0.4, 0.1},
				{0.5, 0.4, 0.4},
				{0.2, 0.5, 0.1},
				{0.1, 0.4, 0.4},
				{0.0, 0.4, 0.3}
			};
GLfloat angle = 88.0;

void init()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-100.0, 100.0, -100.0, 100.0, -100.0, 100.0);
	glMatrixMode(GL_MODELVIEW);
	glClearColor(0.2, 0.1, 0.3, 1.0);
	
	
}

void drawFace(GLfloat* A, GLfloat* B, GLfloat* C, GLfloat* D, GLfloat* color)
{
		glColor3fv(color);	
	glBegin(GL_POLYGON);
		glVertex3fv(A);
		glVertex3fv(B);
		glVertex3fv(C);
		glVertex3fv(D);
	glEnd();	
}

void drawCube()
{

	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	glRotatef(angle, 1.0, 1.0, 1.0);

	
	//raw all the faces
	drawFace(vertex[0], vertex[1], vertex[2], vertex[3], colors[0]);
	drawFace(vertex[1], vertex[5], vertex[6], vertex[2], colors[1]);
	drawFace(vertex[0], vertex[4], vertex[7], vertex[3], colors[2]);
	drawFace(vertex[3], vertex[7], vertex[6], vertex[2], colors[3]);
	drawFace(vertex[0], vertex[4], vertex[5], vertex[1], colors[4]);
	drawFace(vertex[4], vertex[5], vertex[6], vertex[7], colors[5]);
	glFlush();
	glutSwapBuffers();
}

void spinCube()
{
	if ( angle < 360.0)
		angle += 0.5;
	else
		angle = 0;
	
	glutPostRedisplay();
}
int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB|GLUT_DOUBLE|GLUT_DEPTH);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(20, 30);
	glutCreateWindow("3D CUBE");
	glEnable(GL_DEPTH_TEST);
	//glutIdleFunc(spinCube);
	glutMouseFunc(spinCube);
	init();
	glutDisplayFunc(drawCube);
	glutMainLoop();
	return 0;
}























