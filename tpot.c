#include<GL/glut.h>
#include<stdio.h>

float colspec[3] = { 0,0.5,0.2};//pot
float coltab[3]= { 0.2,0,0};//table
float colspec1[3] = { 0,0.5,0.2};
float coltab1[3]={ 0.2,0,0};


float pos[4]= {30,25,10,0};

void init()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-50,50,-50,50,-50,50);
	glMatrixMode(GL_MODELVIEW);
	glClearColor(0,1,1,0);
}
void display()
{
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	
	glLightfv(GL_LIGHT0,GL_AMBIENT,pos);

	glLightfv(GL_LIGHT0,GL_AMBIENT,colspec);
	glLightfv(GL_LIGHT0,GL_DIFFUSE,colspec);
	glLightfv(GL_LIGHT0,GL_SPECULAR,colspec);
	glMaterialfv(GL_FRONT_AND_BACK,GL_AMBIENT,colspec1);
	glMaterialfv(GL_FRONT_AND_BACK,GL_DIFFUSE,colspec1);
	glMaterialfv(GL_FRONT_AND_BACK,GL_SPECULAR,colspec1);
	
	glutSolidTeapot(20);	

	
	
	                                                //table
	glPushMatrix();
	glLightfv(GL_LIGHT0,GL_AMBIENT,pos);
	glLightfv(GL_LIGHT0,GL_AMBIENT,coltab);    
	glLightfv(GL_LIGHT0,GL_DIFFUSE,coltab);
	glLightfv(GL_LIGHT0,GL_SPECULAR,coltab);
	glMaterialfv(GL_FRONT_AND_BACK,GL_AMBIENT,coltab1);
	glMaterialfv(GL_FRONT_AND_BACK,GL_DIFFUSE,coltab1);
	glMaterialfv(GL_FRONT_AND_BACK,GL_SPECULAR,coltab1);
	glTranslatef(0,-10,0);
	glRotatef(20,1,1,0);
	glScalef(1.5,0.1,1.5);
	glutSolidCube(40);
	glPopMatrix();
	glFlush();
	
	glPushMatrix();

	glLightfv(GL_LIGHT0,GL_AMBIENT,pos);

	glLightfv(GL_LIGHT0,GL_AMBIENT,coltab);     //leg1
	glLightfv(GL_LIGHT0,GL_DIFFUSE,coltab);
	glLightfv(GL_LIGHT0,GL_SPECULAR,coltab);
	glMaterialfv(GL_FRONT_AND_BACK,GL_AMBIENT,coltab1);
	glMaterialfv(GL_FRONT_AND_BACK,GL_DIFFUSE,coltab1);
	glMaterialfv(GL_FRONT_AND_BACK,GL_SPECULAR,coltab1);

	glTranslatef(-22,-22,8);
	glRotatef(20,1,1,0);
	glScalef(0.6,4.5,0.6);
	glutSolidCube(5);
	glPopMatrix();
	
	glPushMatrix();

glLightfv(GL_LIGHT0,GL_AMBIENT,pos);

	glLightfv(GL_LIGHT0,GL_AMBIENT,coltab);     //leg2
	glLightfv(GL_LIGHT0,GL_DIFFUSE,coltab);
	glLightfv(GL_LIGHT0,GL_SPECULAR,coltab);
glMaterialfv(GL_FRONT_AND_BACK,GL_AMBIENT,coltab1);
	glMaterialfv(GL_FRONT_AND_BACK,GL_DIFFUSE,coltab1);
	glMaterialfv(GL_FRONT_AND_BACK,GL_SPECULAR,coltab1);

	glTranslatef(-35,-15.5,-25);
	glRotatef(20,1,1,0);
	glScalef(0.6,4.5,0.6);
	glutSolidCube(5);
	glPopMatrix();
	
	
	
	glPushMatrix();
glLightfv(GL_LIGHT0,GL_AMBIENT,pos);


	glLightfv(GL_LIGHT0,GL_AMBIENT,coltab);     //leg3
	glLightfv(GL_LIGHT0,GL_DIFFUSE,coltab);
	glLightfv(GL_LIGHT0,GL_SPECULAR,coltab);
        glMaterialfv(GL_FRONT_AND_BACK,GL_AMBIENT,coltab1);
	glMaterialfv(GL_FRONT_AND_BACK,GL_DIFFUSE,coltab1);
	glMaterialfv(GL_FRONT_AND_BACK,GL_SPECULAR,coltab1);

	glTranslatef(22,-20.5,-15);
	glRotatef(20,1,1,0);
	glScalef(0.6,4,0.6);
	glutSolidCube(5);
	glPopMatrix();
	
	glPushMatrix();

glLightfv(GL_LIGHT0,GL_AMBIENT,pos);

	glLightfv(GL_LIGHT0,GL_AMBIENT,coltab);    //leg4
	glLightfv(GL_LIGHT0,GL_DIFFUSE,coltab);
	glLightfv(GL_LIGHT0,GL_SPECULAR,coltab);
        glMaterialfv(GL_FRONT_AND_BACK,GL_AMBIENT,coltab1);
	glMaterialfv(GL_FRONT_AND_BACK,GL_DIFFUSE,coltab1);
	glMaterialfv(GL_FRONT_AND_BACK,GL_SPECULAR,coltab1);

	glTranslatef(28,-20.5,2);
	glRotatef(20,1,1,0);
	glScalef(0.6,4,0.6);
	glutSolidCube(50);
	glPopMatrix();
	
	
	
	
	glFlush();
}

int main(int argc,char **argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_DEPTH);
	glutCreateWindow("TeaPot");
	init();
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glShadeModel(GL_FLAT);
	glutDisplayFunc(display);
	
	glutMainLoop();
}
