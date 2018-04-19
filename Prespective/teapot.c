#include<stdio.h>
#include<GL/glut.h>

GLfloat angle[3] = {45.0, 45.0, 45.0};
GLfloat rX = 0, rY = 0, rZ = 0;
int axis = -1;

void init()
{
    
    glClearColor(1.0, 1.0, 1.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-90.0, 90.0, -90.0, 90.0, -90.0, 90.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void display()
{

    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    GLfloat mat_specular[] = {1.0, 1.0, 5.0, 1.0}; /* bright white */
    GLfloat mat_diffuse[] = {1.0, 0.5, 0.0, 1.0}; /* orange color */
    GLfloat mat_ambient[] = {1.0, 0.5, 0.0, 1.0}; /* same as diffuse */
    GLfloat mat_shininess = 5.0;
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
    glMaterialf(GL_FRONT, GL_SHININESS, mat_shininess);

    GLfloat lightIntensity1[]={0.5f,0.5f,0.5f,1.0f};
    GLfloat light_position1[]={25.0f,50.0f,50.0f,1.0f};
    glLightfv(GL_LIGHT0, GL_POSITION,light_position1);
    glLightfv(GL_LIGHT0,GL_DIFFUSE,lightIntensity1);
    
    glLoadIdentity();
	glRotatef(angle[0], 1, 0, 0);
	glRotatef(angle[1], 0, 1, 0);
	glRotatef(angle[2], 0, 0, 1);

    glColor3f(0.0, 0.7, 5.0);
    glutSolidTeapot(50);
    glFlush();
	glutSwapBuffers();

}

void spinCube()
{
    if( axis == -1)
        return;

	if ( angle[axis] >= 360.0)
		angle[axis] = 0;
	else {
        	angle[axis] += 1.0;
    }
	glutPostRedisplay();
}

void mouseControl(int button, int state, int x, int y)
{
	if(state == GLUT_DOWN)
		switch(button)
		{
			case GLUT_LEFT_BUTTON:
				axis = 0;
				break;
			case GLUT_RIGHT_BUTTON:
				axis = 1;
				break;
			case GLUT_MIDDLE_BUTTON:
				axis = 2;
				break;
				
		}
}

void keyboardControl(unsigned char key,int x, int y)
{
	switch(key)
	{
		case 'x':
			if(axis != 0){
				axis = 0;
			} else {
				axis = -1;
			}
			break;
		case 'y':
			if(axis != 1){
				axis = 1;
			} else {
				axis = -1;
			}
		case 'z':
			if(axis != 2){
				axis = 2;
			} else {
				axis = -1;
			}
			break;
	}
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB|GLUT_DOUBLE|GLUT_DEPTH);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(20, 30);
	glutCreateWindow("3D TEAPOT");
	glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
	//glPolygonStipple(patt);
	glutIdleFunc(spinCube);
	glutMouseFunc(mouseControl);
	glutKeyboardFunc(keyboardControl);

	init();
	glutDisplayFunc(display);
	
	glutMainLoop();
	return 0;
}


