/*
Implement Cohen Sutherland line clipping using opengl
*/
#include<GL/freeglut.h>
#include<GL/gl.h>
#include<bits/stdc++.h>
#include<stdio.h>
using namespace std;


int  xmin=200;
int  ymin=200;
int xmax=400;
int ymax=400;
int c1,c2;
int lleft=1; int rright=2; int top=8; int bottom=4;
float x1=200;
float yp1=200;
float x2=425;
float y2=425;
int flag=1;
int clip_flag=0;
int i=0;
int linec[4];

int getcode(int x, int y)
{
   int c=0;
   
  if(x<xmin)
  {
    c=c|lleft; 
  }
  
  if(x>xmax)
  {
    c=c|rright;
  }
  
  if(y<ymin)
  {
   c=c|bottom;
  }
  
  if(y>ymax)
  {
   c=c|top;
  }
  
 return c;
}

void clip()
{
 int c;
 float x,y;
 float m=(y2-yp1)/(x2-x1);
 
 
 if(c1)
 {
  c=c1;
 }
 else
 {
  c=c2;
 }
 
 if(c&lleft)
 {
   x=xmin;
   y=yp1+m*(xmin-x1);
 }
 
 if(c&rright)
 {
   x=xmax;
   y=yp1+m*(xmax-x1);
 }
 
 if(c&top)
 {
   y=ymax;
   x=x1+((ymax-yp1)/m);
 }
 
 if(c&bottom)
 {
  y=ymin;
  x=x1+((ymin-yp1)/m);
 }
 
 if(c == c1)
 {
  x1=x;
  yp1=y;
 }
 else
 {
  x2=x;
  y2=y;
 }
 
}



void renderfunc()
{
 glClear(GL_COLOR_BUFFER_BIT);
 glColor3f(1.0,1.0,1.0);
 glPointSize(4);
 glBegin(GL_LINE_LOOP);
 glVertex2i(xmin,ymin);
 glVertex2i(xmax,ymin);
 glVertex2i(xmax,ymax);
 glVertex2i(xmin,ymax);

 glEnd();
 
 if(flag == 1)
 {
  glBegin(GL_LINES);
  glVertex2i(x1,yp1);
  glVertex2i(x2,y2);
  glEnd();
  
 }
 
 while(1 && clip_flag == 1)
 {
   c1=getcode(x1,yp1);
   c2=getcode(x2,y2);
   
   if((c1|c2) == 0)
   {
     break;
   }
   else if( (c1&c2) != 0)
   {
    flag=0;
    break;
   }
   else
   {
    clip();
   }
   
   
   
 }
 
 glFlush();
 
}

void onMouceclick(int button, int state, int x, int y)
{
 if(button == GLUT_LEFT_BUTTON && state==GLUT_DOWN && i<4)
 {
   linec[i]=x;
   i++;
   linec[i]=500-y;
   i++;
 }
 
 if(i == 4)
 {
   i=0;
   x1=linec[0];
   yp1=linec[1];
   x2=linec[2];
   y2=linec[3];
   renderfunc();
   
 }
}

void Key(unsigned char ch, int x, int y)
{
  cout<<ch<<"\n";
  if(ch == 'c')
  {
    clip_flag=1;
    
    glutPostRedisplay();
  }

}

int main(int argc, char ** argv)
{
 glutInit(&argc,argv);
 glutInitWindowSize(500,500);
 glutInitWindowPosition(400,150);
 glutInitDisplayMode(GLUT_SINGLE);
 glutCreateWindow("Cohen line clipping");
 gluOrtho2D(0,500,0,500);
 glClearColor(0,0,0,0);
 glMatrixMode(GL_PROJECTION);
 glutDisplayFunc(renderfunc);
 glutKeyboardFunc(Key);
 glutMouseFunc(onMouceclick);
 glutMainLoop();
 
 
return 0;
}
