#include<GL/glut.h>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

// Prototypes
void myInit();
void myDisplay();
void draw(int, int, int, int);
void drawX(int, int, int, int);
void drawY(int, int, int, int);
void plot(int, int);

// Global vars
int x00, y00, x11, y11;

//main starts
int main(int argc, char** argv)
{
	printf("Enter the starting point\n");
	scanf("%d%d", &x00, &y00);
	printf("Enter the ending point\n");
	scanf("%d%d", &x11, &y11);
	
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100,200);
	glutCreateWindow("Bresenham's Line Drawing Algo");
	myInit();
	glutDisplayFunc(myDisplay);
	glutMainLoop();
}

//Initializing the window
void myInit()
{
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glColor3f(0.0, 0.0, 0.0);
	gluOrtho2D(0.0, 500.0, 0, 500.0);
}

// Function to display
void myDisplay()
{
	glClear(GL_COLOR_BUFFER_BIT);
	draw(x00, y00, x11, y11);
	glEnd();
	glFlush();
}

// Function to Draw
void draw(int x0, int y0, int x1, int y1)
{
	if (abs(y1 - y0) < abs(x1 - x0))
		if(x0 > x1)
			drawY(x1, y1, x0, y0);
		else
			drawY(x0, y0, x1, y1);
	else
		if(y0 > y1)
			drawX(x1, y1, x0, y0);
		else
			drawX(x0, y0, x1, y1);
}

// Function draw X inc.
void drawX(int x0, int y0, int x1, int y1)
{
	int delX, delY, xi, i, x, y, p0;
	delX = x1 - x0;
	delY = y1 - y0;
		
	xi = 1;
	
	if (delX < 0)
	{
		xi = -1;
		delX = -delX;
	}
	
	p0 = 2*delX - delY;
	for ( i = y0, x = x0; i <= y1; i++)
	{
		y = i;
		plot(x, y);
		
		if (p0 > 0)
		{
			x+=xi;
			p0 = p0 - 2*delY;
		}
		p0 = p0 + 2*delX;
	}
	
}

// Function draw Y inc.
void drawY(int x0, int y0, int x1, int y1)
{
	int delX, delY, yi, i, x, y, p0;
	delX = x1 - x0;
	delY = y1 - y0;
		
	yi = 1;
	if (delY < 0)
	{
		yi = -1;
		delY = -delY;
	}
	
	p0 = 2*delY - delX;

	for ( i = x0, y = y0; i <= x1; i++)
	{
		x = i;
		plot(x, y);
		
		if (p0 > 0)
		{
			y+=yi;
			p0 = p0 - 2*delX;
		}
		p0 = p0 + 2*delY;
	}
	
}


//function to plot
void plot( int x, int y )
{
	glBegin(GL_POINTS);
		glColor3f(0.0, 0.0, 0.0);
		glVertex2f(x, y);
	glEnd();
} 




























