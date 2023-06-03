

#include <iostream>
#include <GL/glut.h>
#include <GL/freeglut.h>
#include <math.h>
using namespace std;

#define RADIAN (3.14/180)
#define XMAX 1400
#define YMAX 900

void Initialize();
void draw();
void draw_koch(float,float,float,float,int);

void Initialize()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(0.0,0.0,0.0,0.0);
	glColor3f(1.0,1.0,1.0);
	gluOrtho2D(0.0,XMAX,0.0,YMAX);
}

void draw(int n)
{	

	glBegin(GL_LINES);
	draw_koch(600,100,800,400,n);
	draw_koch(800,400,400,400,n);
	draw_koch(400,400,600,100,n);
	glEnd();
	glFlush();
}

void draw_koch(float xa,float ya,float xb,float yb,int n)
{
	float xc,xd,yc,yd,midx,midy;
	
	xc = (2*xa+xb)/3;
	yc = (2*ya+yb)/3;
	xd = (2*xb+xa)/3;
	yd = (2*yb+ya)/3;
		
	midx = xc + ((xd-xc)*cos(60*RADIAN)) + ((yd-yc)*sin(60*RADIAN));
	midy = yc - ((xd-xc)*sin(60*RADIAN)) + ((yd-yc)*cos(60*RADIAN));
	
	if(n>0)
	{
		draw_koch(xa,ya,xc,yc,n-1);
		draw_koch(xc,yc,midx,midy,n-1);
		draw_koch(midx,midy,xd,yd,n-1);
		draw_koch(xd,yd,xb,yb,n-1);
	}
	
	else
	{
		glVertex2f(xa,ya);
		glVertex2f(xc,yc);
		
		glVertex2f(xc,yc);
		glVertex2f(midx,midy);
		
		glVertex2f(midx,midy);
		glVertex2f(xd,yd);
		
		glVertex2f(xd,yd);
		glVertex2f(xb,yb);
	}	
}
	

int main(int argc , char ** argv)
{
	int n;
	cout<<"\n Enter For How Many Iterations You Want to Draw ?::";
	cin>>n;
	glutInit( &argc , argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(XMAX,YMAX);
	glutInitWindowPosition(0,0);
	glutCreateWindow("KOCH CURVE");
	
	Initialize();
	draw(n);
	glutMainLoop();
	return 0;
}
