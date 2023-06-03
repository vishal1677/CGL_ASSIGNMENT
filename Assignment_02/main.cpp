#include<GL/freeglut.h>
#include<GL/gl.h>
#include<iostream>
#include<math.h>

void primitiveline(int x1, int y1 , int x2, int y2)
{
 glColor3f(1.0,1.0,1.0);
 glBegin(GL_LINES);
 glVertex2i(x1,y1);
 glVertex2i(x2,y2);
 glEnd();
 
}

void plotpixel(int x1, int y1)
{
 glColor3f(1.0,1.0,1.0);
 glBegin(GL_POINTS);
 glVertex2i(x1,y1);
 glEnd();
 
}
void ddaline(int x1, int y1, int x2, int y2)
{
 int dx=x2-x1;
 int dy=y2-y1;
 int steps;
 
 if(abs(dx) > abs(dy))
 {
  steps=dx;
 }
 else
 {
   steps=dy;
 }
 
 int xin=dx/steps;
 int yin=dy/steps;
 int x=x1;
 int y=y1;
 
 for(int i=0; i<=steps; i++)
 {
   plotpixel(x,y);
   x=x+xin;
   y=y+yin;
 }
 
}

void bresehnmsline(int x1, int y1, int x2, int y2)
{
 int dx=x2-x1;
 int dy=y2-y1;
 int xin=1;
 int yin=1;
 
 if(x1>x2)
 {
  xin=-1;
 }
 
 if(y1>y2)
 {
  yin=-1;
 }
 
 int x=x1;
 int y=y1;
 
 plotpixel(x,y);
 
 if(dx == 0)
 {
   for(int i=0; i<dy; i++)
   {
     plotpixel(x,y);
     y=y+yin;
   }
   
  return;  
 }
 
 if(dy == 0)
 {
   for(int i=0; i<dx; i++)
   {
     plotpixel(x,y);
     x=x+xin;
   }
   
  return; 
 }
 

 if(dx>dy)
 {
   int p=2*dy-dx;
   for(int i=0; i<dx; i++)
   { 
     if(p>0)
     {
       p=p+2*(dy-dx);
       y=y+yin;
     }
     else
     {
      p=p+2*dy;
     }
     x=x+xin;
     plotpixel(x,y);
    
   }
 }
 else
 {
  int p=2*dx-dy;
  for(int i=0; i<dy; i++)
  {
    if(p>0)
    {
      p=p+2*(dx-dy);
      x=x+xin;
    }
    else
    {
      p=p+2*dx;
    }
    
    y=y+yin;
    plotpixel(x,y);
  }
 }
 
}

void renderfunction()
{
 glClear(GL_COLOR_BUFFER_BIT);
 bresehnmsline(0,0,200,200);
 glFlush();
 
}

int main(int argc, char **argv)
{
 glutInit(&argc,argv);
 glutInitWindowSize(500,500);
 glutInitWindowPosition(400,150);
 glutInitDisplayMode(GLUT_SINGLE);
 glutCreateWindow("Line drawing algorithm");
 gluOrtho2D(0,500,0,500);
 glClearColor(0,0,0,1);
 glMatrixMode(GL_PROJECTION);
 glutDisplayFunc(renderfunction);
 glutMainLoop();
 

return 0;
}
