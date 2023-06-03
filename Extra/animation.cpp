/*Problem Statement : Write a Program in OpenGL on Linux platform to animate a scene.*/


#include<GL/glut.h>
#include<math.h>
#include<iostream>
using namespace std;

#define pi 3.14

int framenumber=0;

void drawdisk(double rad)					//draws disk
{
	int i;
	glBegin(GL_POLYGON);
	for(i=0;i<32;++i)
	{
		GLdouble angle= 2*pi*i/32;
		glVertex2d(rad*cos(angle),rad*sin(angle));
	}
	glEnd();		
}
void drawbase()								//draws the base in black
{
	glColor3f(0.0,0.0,0.0);
	glBegin(GL_POLYGON);
	glVertex2d(1,-1);						//vertices of the base
	glVertex2d(1,0);
	glVertex2d(6,0);
	glVertex2d(6,-1);
	glEnd();
	glFlush();	
}

void drawflag()								//draws the flag with orange, white and green bands
{
	glColor3f(0.0,1.0,0.0);					//green band
	glBegin(GL_POLYGON);
	glVertex2d(0,0);						//vertices of the green band
	glVertex2d(1.5,0);
	glVertex2d(1.5,0.5);
	glVertex2d(0,0.5);
	glEnd();
	
	glColor3f(1.0,1.0,1.0);					//white band
	glBegin(GL_POLYGON);
	glVertex2d(0,0.5);						//vertices of the white band
	glVertex2d(1.5,0.5);
	glVertex2d(1.5,1.0);
	glVertex2d(0,1.0);
	glEnd();
	
	glColor3f(1.0,0.5,0.5);					//orange band
	glBegin(GL_POLYGON);
	glVertex2d(0,1);						//vertices of orange band
	glVertex2d(1.5,1);
	glVertex2d(1.5,1.5);
	glVertex2d(0,1.5);
	glEnd();
	glFlush();
}
void drawchakra()							//draws the ashoka chakra
{
	int i;
	glColor3f(0.0,0.0,1.0);
	drawdisk(0.5);
	glColor3f(1.0,1.0,1.0);
	drawdisk(0.4);
	glColor3f(0.0,0.0,1.0);
	for(i=0;i<24;++i)						//draws spokes of radius 0.5
	{
		glRotatef(360/24,0,0,1);
		glBegin(GL_LINES);
		glVertex2d(0,0);					
		glVertex2d(0.5,0);
		glEnd();
		
	}
}

void drawsun()								//draws sun of radius 1
{
	int i;
	glColor3f(1.0,1.0,0.0);
	drawdisk(1);
	for(i=0;i<15;++i)
	{
		glRotatef(360/15,0,0,1);
		glBegin(GL_LINES);
		glVertex2f(0,0);
		glVertex2f(1.5,0);
		glEnd();
		
	}	
}
void draw()								//main draw function
{
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();
	
	drawbase();
	
	glColor3f(0.0,0.0,0.0);				//draws the pole for the flag
	glLineWidth(50);
	glBegin(GL_LINES);
	glVertex2d(3,0);
	glVertex2d(3,3.5);
	glEnd();
	glLineWidth(1);
	
	glPushMatrix();								//translates the flag
	glTranslated(3.02f,2.1f*(framenumber%300)/300,0);
	drawflag();
	glPopMatrix();

	glPushMatrix();								//translates the chakra
	glTranslated(3.77f,0.75+2.1f*(framenumber%300)/300,0);
	glScaled(0.5,0.5,0);
	drawchakra();
	glPopMatrix();
	
	glPushMatrix();								//translates and rotates the sun 
	glTranslated(6,3,0);
	glRotated(framenumber*0.7f,0,0,1);
	glScaled(0.5,0.5,1);
	drawsun();
	glPopMatrix();
	
	glutSwapBuffers();
}

void doframe(int v)
{
	framenumber++;
	glutPostRedisplay();
	glutTimerFunc(10,doframe,0);	
}
void Init()
{
	glClearColor(0.5f,0.5f,0.8f,0.0f);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0,7,-1,4,-1,1);
	glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv)				//main function
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE);
    glutInitWindowSize(1366,768);
    glutInitWindowPosition(0,0);
    glutCreateWindow("FLAG HOISTING");
    Init();
    glutDisplayFunc(draw);
    glutTimerFunc(100,doframe,0);
    glutMainLoop();    
    return 0;
}											//end of program
