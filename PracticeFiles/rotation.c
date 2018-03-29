#include<GL/glut.h>
#include<stdio.h>
#include<math.h>
#include<memory.h>

GLfloat angle = 0.0;
int repeat = 0;
GLfloat imagemat[4][3]={{0,0,1},{50,0,1},{50,50,1},{0,50,1}}; //used to test rotation and scaling
GLfloat resultmat[3][3]={{0},{0},{0}};
GLfloat pivotpt[3]={100,100,1};
GLfloat identitymat[3][3]={{1,0,0},{0,1,0},{0,0,1}};

GLfloat newimage[3][3];
GLubyte patt[] = {
			0x01, 0x80, 0x01, 0x80,
			0x02, 0x40, 0x02, 0x40,
			0x8c, 0x61, 0x8c, 0x61,
			0x98, 0x31, 0x98, 0x31,
			0x31, 0x98, 0x31, 0x98,
			0x21, 0x8c, 0x21, 0x8c,
			0x60, 0x06, 0x60, 0x06,
			0x80, 0x81, 0x80, 0x81,
			0x01, 0x80, 0x01, 0x80,
			0x02, 0x40, 0x02, 0x40,
			0x8c, 0x61, 0x8c, 0x61,
			0x98, 0x31, 0x98, 0x31,
			0x31, 0x98, 0x31, 0x98,
			0x21, 0x8c, 0x21, 0x8c,
			0x60, 0x06, 0x60, 0x06,
			0x80, 0x81, 0x80, 0x81,
			0x01, 0x80, 0x01, 0x80,
			0x02, 0x40, 0x02, 0x40,
			0x8c, 0x61, 0x8c, 0x61,
			0x98, 0x31, 0x98, 0x31,
			0x31, 0x98, 0x31, 0x98,
			0x21, 0x8c, 0x21, 0x8c,
			0x60, 0x06, 0x60, 0x06,
			0x80, 0x81, 0x80, 0x81,
			0x01, 0x80, 0x01, 0x80,
			0x02, 0x40, 0x02, 0x40,
			0x8c, 0x61, 0x8c, 0x61,
			0x98, 0x31, 0x98, 0x31,
			0x31, 0x98, 0x31, 0x98,
			0x21, 0x8c, 0x21, 0x8c,
			0x60, 0x06, 0x60, 0x06,
			0x80, 0x81, 0x80, 0x81
			
		};


float v[3][2] = { {250, 100}, {250, 250}, {350, 200} };


void multiplyMatrices(GLfloat firstMatrix[][3], GLfloat secondMatrix[][3], GLfloat mult[][3], int rowFirst, int columnFirst, int rowSecond, int columnSecond)
{
	int i, j, k;

	// Initializing elements of matrix mult to 0.
	for(i = 0; i < rowFirst; ++i)
	{
		for(j = 0; j < columnSecond; ++j)
		{
			mult[i][j] = 0.0;
		}
	}

	// Multiplying matrix firstMatrix and secondMatrix and storing in array mult.
	for(i = 0; i < rowFirst; ++i)
	{
		for(j = 0; j < columnSecond; ++j)
		{
			for(k=0; k<columnFirst; ++k)
			{
				mult[i][j] += firstMatrix[i][k] * secondMatrix[k][j];
			}
		}
	}
}


void multiplyMatrices1(GLfloat firstMatrix[][3], GLfloat secondMatrix[3][1], GLfloat mult[3][1], int rowFirst, int columnFirst, int rowSecond, int columnSecond)
{
	int i, j, k;

	// Initializing elements of matrix mult to 0.
	for(i = 0; i < rowFirst; ++i)
	{
		for(j = 0; j < columnSecond; ++j)
		{
			mult[i][j] = 0.0;
		}
	}

	// Multiplying matrix firstMatrix and secondMatrix and storing in array mult.
	for(i = 0; i < rowFirst; ++i)
	{
		for(j = 0; j < columnSecond; ++j)
		{
			for(k=0; k<columnFirst; ++k)
			{
				mult[i][j] += firstMatrix[i][k] * secondMatrix[k][j];
			}
		}
	}
}


void rotate_pt(GLfloat x, GLfloat y, GLfloat theta)
{
	GLfloat temp1[3][1]={{0},{0},{0}};
	GLfloat temp2[3][1]={{0},{0},{0}};
	GLfloat temp3[3][1]={{0},{0},{0}};

	GLfloat rest[3][3];
	GLfloat rot_mat[3][3];
	GLfloat pivotmat[][3]={{1,0,0},{0,1,0},{0,0,1}}; //pivot matrix
	GLfloat pivotinvmat[3][3]={{1,0,0},{0,1,0},{0,0,1}}; //inverse pivot matrix
    
	pivotmat[0][2]=x;
	pivotmat[1][2]=y;

	pivotinvmat[0][2]=-x;
	pivotinvmat[1][2]=-y;
	rot_mat[0][0] = cos(theta);
	rot_mat[0][1] = -sin(theta);
	rot_mat[1][0] = sin(theta);
	rot_mat[1][1] = cos(theta);
	rot_mat[2][2] = 1;


	multiplyMatrices(pivotmat,rot_mat,resultmat,3,3,3,3); 
	memcpy(rest, resultmat, sizeof(rest)); //copies resultmat to rest
	multiplyMatrices(rest,pivotinvmat,resultmat,3,3,3,3);

	
	GLfloat temp[3][1];

	memcpy(temp, imagemat[0], sizeof(temp)); //copies first point to temp
	memcpy(rest, resultmat, sizeof(rest));

	multiplyMatrices1(rest,temp,temp1,3,3,3,1); //new first point is stored in temp1
	memcpy(temp, imagemat[1], sizeof(temp)); //copies second  point to temp
	multiplyMatrices1(rest,temp,temp2,3,3,3,1); //new second point is stored in temp2
	memcpy(temp, imagemat[2], sizeof(temp)); //copies third point to temp
	multiplyMatrices1(rest,temp,temp3,3,3,3,1); //new third point is stored in temp3
	
	int i = 0;
	for (i=0; i<3; i++) //combines all points to newimage
	{
		newimage[0][i]=temp1[i][0];
		newimage[1][i]=temp2[i][0];
		newimage[2][i]=temp3[i][0];
		
		printf("\n%f", temp1[i][0]);
	
	}
	
	printf("\n%f, %f, %f\n", newimage[0][0], newimage[0][1], newimage[0][2]);
	printf("\n%f, %f, %f\n", newimage[1][0], newimage[1][1], newimage[1][2]);
	printf("\n%f, %f, %f\n", newimage[2][0], newimage[2][1], newimage[2][2]);
}

void triangle(){
	glBegin(GL_TRIANGLES);
		glColor3f(1.0, 0.5, 0.0);
		glVertex2fv(v[1]);
	
		glColor3f(0.2, 0.7, 0.4);
		glVertex2fv(v[1]);
		
		glColor3f(0.0, 0.2, 0.4);
		glVertex2fv(v[2]);

	glEnd();
	glBegin(GL_TRIANGLES);
		glColor3f(1.0, 0.5, 0.0);
		//glVertex2fv(v[1]);
		rotate_pt(v[0][0], v[0][1], angle);
		glVertex2fv(newimage[0]);
		
		glColor3f(0.2, 0.7, 0.4);
		rotate_pt(v[1][0], v[1][1], angle);
		//glVertex2fv(v[1]);
		glVertex2fv(newimage[0]);
		
		glColor3f(0.0, 0.2, 0.4);
		rotate_pt(v[2][0], v[2][1], angle);
		//glVertex2fv(v[2]);
		glVertex2fv(newimage[0]);
	glEnd();
	
	/*
	int i = 0;
	for( i = 0; i < 3; i++)
	{
		glBegin(GL_TRIANGLES);
			glColor3f(1.0, 0.5, 0.0);
			glVertex3fv(newimage[i][0]);
			glColor3f(0.2, 0.7, 0.4);
			glVertex3fv(new);
			glColor3f(0.0, 0.2, 0.4);
			glVertex3fv(v[2]);
		glEnd();
	}
	*/
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	triangle();
	int i;
	for(i =0; i < repeat; i++)
	{
		//glPushMatrix();
		//glTranslatef(v[1][0],v[1][1],0.0);
		//glRotatef(angle,0.0,0.0,1.0);
		//glTranslatef(-v[1][0],-v[1][1],0.0);
		triangle();
	}
	
	
	glPopMatrix();
	glFlush();
}

void init()
{
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glColor3f(0.0, 0.0, 0.0);
	gluOrtho2D(0.0, 500.0, 0.0, 500.0);
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
	//glEnable(GL_POLYGON_STIPPLE);
	//glPolygonStipple(patt);
	init();
	glutDisplayFunc(display);
	glutMainLoop();
	
}
