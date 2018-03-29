#include<stdio.h>
#include<GL/glut.h>
#include<math.h>
#include<memory.h>


//GLfloat imagemat[3][3]={{100,100,1},{300,100,1},{200,300,1}};
//GLfloat imagemat[3][3]={{10,300,1},{80,200,1},{50,400,1}}; //used for reflect(3) and reflect(4)
GLfloat imagemat[4][3]={{0,0,1},{50,0,1},{50,50,1},{0,50,1}}; //used to test rotation and scaling
GLfloat resultmat[3][3]={{0},{0},{0}};
GLfloat pivotpt[3]={100,100,1};
GLfloat identitymat[3][3]={{1,0,0},{0,1,0},{0,0,1}};

GLfloat newimage[3][3];
//GLfloat newimage[4][3]; //used to test rotation and scaling
GLfloat theta;

void arraycopy(GLfloat srcmat[][3], GLfloat dstmat[][3])
{
	int i, j;
	for(i=0;i<sizeof(srcmat[0]) / sizeof(srcmat);i++)
		for(j=0;j<sizeof(srcmat[0]) / sizeof(srcmat);j++)
			dstmat[i][j]=srcmat[i][j];
}


void drawimage(GLfloat imgmat[3][3])
{
	int i;
	
	glBegin(GL_LINE_LOOP);
	for(i=0;i<3;i++) // i<no of sides
		glVertex3fv(imgmat[i]);
	glEnd();

}

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

void translatemat(GLfloat tx, GLfloat ty)
{
	GLfloat transmat[3][3];
	GLfloat temp1[3][1]={{0},{0},{0}};
	memcpy(transmat, identitymat, sizeof(transmat));
	transmat[0][2]=tx;
	transmat[1][2]=ty;
	GLfloat temp[3][1];

	int i = 0;
	for (i=0; i<3; i++)
	{
		memcpy(temp, imagemat[i], sizeof(temp));
		multiplyMatrices1(transmat,temp,temp1,3,3,3,1);
		newimage[i][0]=temp1[0][0];
		newimage[i][1]=temp1[1][0];
	    newimage[i][2]=temp1[2][0];
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
	}
	

 
}
void rotate_scale(GLfloat theta, float sx, float sy) //rotate and scale
{
	GLfloat rot_sclmat[3][3];
	GLfloat temp1[3][1]={{0},{0},{0}};
	GLfloat temp2[3][1]={{0},{0},{0}};
	GLfloat temp3[3][1]={{0},{0},{0}};
	GLfloat temp4[3][1]={{0},{0},{0}};
	rot_sclmat[0][0]=sx*cos(theta)*cos(theta)+sy*sin(theta)*sin(theta);
	rot_sclmat[0][1]=(sy-sx)*(cos(theta)*sin(theta));
	rot_sclmat[0][2]=0;
	rot_sclmat[1][0]=(sy-sx)*(cos(theta)*sin(theta));
	rot_sclmat[1][1]=sx*sin(theta)*sin(theta)+sy*cos(theta)*cos(theta);
	rot_sclmat[1][2]=0;
	rot_sclmat[2][0]=0;
	rot_sclmat[2][1]=0;
	rot_sclmat[2][2]=1;
	GLfloat temp[3][1];

	memcpy(temp, imagemat[0], sizeof(temp));

	multiplyMatrices1(rot_sclmat,temp,temp1,3,3,3,1);
	memcpy(temp, imagemat[1], sizeof(temp));
	multiplyMatrices1(rot_sclmat,temp,temp2,3,3,3,1);
	memcpy(temp, imagemat[2], sizeof(temp));
	multiplyMatrices1(rot_sclmat,temp,temp3,3,3,3,1);
	memcpy(temp, imagemat[3], sizeof(temp));
	multiplyMatrices1(rot_sclmat,temp,temp4,3,3,3,1);
	
	int i = 0;
	for (i=0; i<3; i++)
	{
		newimage[0][i]=temp1[i][0];
		newimage[1][i]=temp2[i][0];
		newimage[2][i]=temp3[i][0];
		newimage[3][i]=temp4[i][0];
	}

 
}

void reflect(int d) //reflect
{
		GLfloat temp1[3][1]={{0},{0},{0}};
	GLfloat temp2[3][1]={{0},{0},{0}};
	GLfloat temp3[3][1]={{0},{0},{0}};
	GLfloat temp4[3][1]={{0},{0},{0}};  //reflection with four side polygon
	GLfloat idymat[3][3]={{1,0,0},{0,1,0},{0,0,1}};
	GLfloat temp[3][1];
	if (d==0) //x dir
	{
		idymat[1][1]=-1;
	}
	if (d==1) //y dir
	{
		idymat[0][0]=-1;
	}
	if (d==2) //xy dir
	{
		idymat[0][0]=-1;
		idymat[1][1]=-1;
	}
	if (d==3) //y dir diagonal 45 y=x
	{
		idymat[0][0]=0;
		idymat[1][1]=0;
		idymat[1][0]=1;
		idymat[0][1]=1;
	}
	if (d==4) //y dir diagonal 45 y=-x
	{
		idymat[0][0]=0;
		idymat[1][1]=0;
		idymat[1][0]=-1;
		idymat[0][1]=-1;
	}
	
	memcpy(temp, imagemat[0], sizeof(temp));

	multiplyMatrices1(idymat,temp,temp1,3,3,3,1);
	memcpy(temp, imagemat[1], sizeof(temp));
	multiplyMatrices1(idymat,temp,temp2,3,3,3,1);
	memcpy(temp, imagemat[2], sizeof(temp));
	multiplyMatrices1(idymat,temp,temp3,3,3,3,1);
	//memcpy(temp, imagemat[3], sizeof(temp));   //reflection with four side polygon
	//multiplyMatrices1(idymat,temp,temp4,3,3,3,1);
	
	int i = 0;
	for (i=0; i<3; i++)
	{
	newimage[0][i]=temp1[i][0];
	newimage[1][i]=temp2[i][0];
	newimage[2][i]=temp3[i][0];
	newimage[3][i]=temp4[i][0];   //reflection with four side polygon
	}
}

void renderBitmapString(float x, float y, const char *string){
    const char *c;
    glRasterPos2f(x, y);
    for (c=string; *c != '\0'; c++) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_10, *c);
    }
} 

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	renderBitmapString(150,150,"Sahyadri"); //Display the string at given position
	 //Rotation using OpenGL matrix
	glColor3f(0,0,1);
	drawimage(imagemat);
	
	rotate_pt(0, 0, theta); //rotation w.r.t origin
	drawimage(newimage);
	rotate_pt(100, 100, theta); //rotation w.r.t fixed point
	drawimage(newimage);

    	translatemat(0,20); //translation
	rotate_scale(45,1,2); //rotate and scale  
	reflect(3); //reflection
	glColor3f(0,1,0);
	drawimage(newimage);
	glFlush();
}

void myinit()
{
	glClearColor(1,1,1,1);
	glColor3f(1,0,0);
	glPointSize(1);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-200, 200,-200,200);
}

int main(int argc, char *argv[])
{
	
	theta=theta*(3.14/180);
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(500,500);
	glutInitWindowPosition(0,0);
	glutCreateWindow("2D Transformation");
	myinit();
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}




