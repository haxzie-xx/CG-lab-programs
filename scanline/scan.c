#include <stdio.h>
#include <GL/glut.h>

int i,j,n;

typedef struct stEdge{
	float xmin,ymax,invm;
	struct stEdge *next;
}Edge;

typedef struct stpoint{
	float x,y;
}point;

point v[10];

void myinit(void)
{
	glClearColor(1,1,1,1);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0,1000,0,1000);
	glMatrixMode(GL_MODELVIEW);
	v[0].x=500;
	v[0].y=200;

	v[1].x=200;
	v[1].y=600;

	v[2].x=400;
	v[2].y=800;

	v[3].x=600;
	v[3].y=800;
    
	v[4].x=800;
	v[4].y=600;
}

void draw_poly()
{
	int i;
	//glColor3f(0,1,1);
	glBegin(GL_LINE_LOOP);
	for(i=0;i<5;i++)
	    glVertex2f(v[i].x,v[i].y);
	glEnd();
	glFlush();
}

void insertEdge(Edge *active,Edge *edge)
{
	Edge *e,*q=active;
	e=q->next;
	while(e!=NULL){
		if(edge->xmin<e->xmin)
		e=NULL;
		else{
			q=e;
			e=e->next;
		}
	}
	edge->next=q->next;
	q->next=edge;
}
void fillscan(int scan,Edge *active){
	Edge *p1,*p2;
	p1=active->next;
	while(p1){
		p2=p1->next;
		//glColor3f(1,0,0);
		glBegin(GL_POINTS);
		for(i=p1->xmin;i<=p2->xmin;i++){
			glVertex2i((int)i,scan);
		}
		glEnd();
		p1=p2->next;
	}
}
int ynext(int k,int n,point *v)
{
	int j;
	if((k+1)>(n-1)) 
		j=0;
	else
		j=k+1;
	while(v[k].y==v[j].y){
		if((j+1)>(n-1)) 
			j=0;
		else 
			j++;
	}
	return(v[j].y);
}
void updateActiveList(int scan,Edge *active)
{
	Edge *q=active,*ae=active->next,*temp ;
	while(ae){
		if(scan>=ae->ymax){
			ae=ae->next;
			temp=q->next;
			q->next=temp->next;
			free(temp);
		}
		else
		{
			ae->xmin=ae->xmin+ae->invm;
			q=ae;
			ae=ae->next;
		}
	}
}
void resortActiveList(Edge *active){
	Edge *q,*p=active->next;
	active->next=NULL;
	while(p){
		q=p->next;
		insertEdge(active,p);
		p=q;
	}
}
void buildActiveList(int scan,Edge *active,Edge *edges[]){
	Edge *e,*q;
	e=edges[scan]->next;
	while(e){
		q=e->next;
		insertEdge(active,e);
		e=q;
	}	
}
void makeEdgeRec(point lower,point upper,float yprev,Edge *edge,Edge *edges[]){
	edge->invm=(upper.x-lower.x)/(upper.y-lower.y);
	edge->xmin=lower.x;
	if(upper.y<yprev)
		edge->ymax=upper.y-1;
	else
		edge->ymax=upper.y;
	Edge *e,*q=edges[(int)lower.y];
	e=q->next;
	while(e!=NULL){
		if(edge->xmin<e->xmin)
			e=NULL;
		else{
			q=e;
			e=e->next;
			}
	}
	edge->next=q->next;
	q->next=edge;
}
void buildEdgeList(int n,point *v,Edge *edges[])
{
	point v1,v2;
	Edge *edge;
	float yprev;
	yprev=v[n-2].y;
	v1.x=v[n-1].x;
	v1.y=v[n-1].y;
	for(i=0;i<n;i++){
		v2=v[i];
		if(v1.y!=v2.y){
			edge=(Edge *)malloc(sizeof(Edge));
			if(v1.y<v2.y)
			makeEdgeRec(v1,v2,ynext(i,n,v),edge,edges);
			else
			makeEdgeRec(v2,v1,yprev,edge,edges);
		}
		yprev=v1.y;
		v1=v2;
	}
}
void scanfill(int n,point *v)
{
	Edge *edges[1000],*active;
	for(i=0;i<1000;i++){
		edges[i]=(Edge *)malloc(sizeof(Edge));
		edges[i]->next=NULL;
	}
	buildEdgeList(n,v,edges);
	active=(Edge *)malloc(sizeof(Edge));
	active->next=NULL;
	for(j=0;j<1000;j++){
		buildActiveList(j,active,edges);
		if(active->next){
			fillscan(j,active);
			updateActiveList(j,active);
			resortActiveList(active);
		}
	}
}
void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	draw_poly();
	scanfill(5,v);
	glFlush();
    glutSwapBuffers();

}

void menu(int num)
{
	switch(num)
	{
	case 1:glColor3f(1.0,.0,.0);
		display();
		break;
	case 2:glColor3f(0.0,0.0,1.0);
		display();
		break;
	case 3:glColor3f(0.0,1.0,0.0);
		display();
		break;
	default: exit(0);
	}
	glutPostRedisplay();
}

void createmenu(void)
{
	int menu_id;
	menu_id=glutCreateMenu(menu);
	glutAddMenuEntry("RED",1);
	glutAddMenuEntry("BLUE",2);
	glutAddMenuEntry("GREEN",3);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
}

void main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);

	glutInitWindowSize (500, 500);
	glutInitWindowPosition (100, 100);

	glutCreateWindow("ScanLine");
	myinit();
	glutReshapeFunc(myReshape);
	glutDisplayFunc(display);
	glutIdleFunc(Move);
	glutMainLoop();
}