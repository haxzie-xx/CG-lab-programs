#include<GL/glut.h>

void init(void)
{
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0.0, 240.0, 0.0, 240.0);
}

void lineSegment(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	//BAT WING LEFT
	glBegin(GL_POLYGON);
		glColor3f(0.5, 0.5, 0.5);
		glVertex2f(40, 130);
		glVertex2f(90, 120);
		glVertex2f(120, 100);
		glVertex2f(120, 80);
		glVertex2f(90, 90);
		glVertex2f(70, 100);
	glEnd();
	//BAT STRIPES LEFT
	glBegin(GL_LINES);
		glColor3f(0.7, 0.7, 0.7);
		glVertex2i(70, 100);
		glVertex2i(90,120);
	glEnd();
	glBegin(GL_LINES);
		glColor3f(0.7, 0.7, 0.7);
		glVertex2i(90, 120);
		glVertex2i(90,90);
	glEnd();
	glBegin(GL_LINES);
		glColor3f(0.7, 0.7, 0.7);
		glVertex2i(90, 120);
		glVertex2i(120,80);
	glEnd();
	//BAT WING RIGHT
	glBegin(GL_POLYGON);
		glColor3f(0.5, 0.5, 0.5);
		glVertex2f(200, 130);
		glVertex2f(150, 120);
		glVertex2f(120, 100);
		glVertex2f(120, 80);
		glVertex2f(150, 90);
		glVertex2f(170, 100);
	glEnd();
	//BAT STRIPES RIGHT
	glBegin(GL_LINES);
		glColor3f(0.7, 0.7, 0.7);
		glVertex2i(170, 100);
		glVertex2i(150,120);
	glEnd();
	glBegin(GL_LINES);
		glColor3f(0.7, 0.7, 0.7);
		glVertex2i(150, 120);
		glVertex2i(150,90);
	glEnd();
	glBegin(GL_LINES);
		glColor3f(0.7, 0.7, 0.7);
		glVertex2i(150, 120);
		glVertex2i(120,80);
	glEnd();
	//BAT EAR LEFT
	glBegin(GL_POLYGON);
		glColor3f(0.8, 0.8, 0.8);
		glVertex2f(105, 120);
		glVertex2f(110, 130);
		glVertex2f(115, 120);
	glEnd();
	//BAT EAR RIGHT
	glBegin(GL_POLYGON);
		glColor3f(0.8, 0.8, 0.8);
		glVertex2f(125, 120);
		glVertex2f(130, 130);
		glVertex2f(135, 120);
	glEnd();
	//BAT TAIL
	glBegin(GL_POLYGON);
		glColor3f(0.8, 0.8, 0.8);
		glVertex2f(105, 80);
		glVertex2f(120, 60);
		glVertex2f(135, 80);
	glEnd();
	//BAT BODY
	glBegin(GL_POLYGON);
		glColor3f(0.7, 0.7, 0.7);
		glVertex2f(105, 80);
		glVertex2f(120, 120);
		glVertex2f(135, 80);
	glEnd();
	//BAT FACE
	glBegin(GL_POLYGON);
		glColor3f(0.7, 0.7, 0.7);
		glVertex2f(105, 120);
		glVertex2f(110, 100);
		glVertex2f(120, 95);
		glVertex2f(130, 100);
		glVertex2f(135, 120);
		glVertex2f(120, 122);
	glEnd();
	//BAT LEFT EYE
	glBegin(GL_POLYGON);
		glColor3f(1.0, 0.4, 0.0);
		glVertex2f(110, 115);
		glVertex2f(115, 110);
		glVertex2f(110, 110);
	glEnd();
	//BAT RIGHT EYE
	glBegin(GL_POLYGON);
		glColor3f(1.0, 0.4, 0.0);
		glVertex2f(130, 115);
		glVertex2f(125, 110);
		glVertex2f(130, 110);
	glEnd();
	
		
	glFlush();
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowPosition(50, 100);
	glutInitWindowSize(700, 700);
	glutCreateWindow("BatMan");
	init();
	glutDisplayFunc(lineSegment);
	glutMainLoop();
}

