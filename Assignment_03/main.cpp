/*
Problem Statement:- 

Implement bresehnms circle drawing algorithm

*/
#include<GL/freeglut.h>
#include<GL/gl.h>
#include<math.h>

void plotpixel(int x, int y)
{
 glColor3f(1.0,1.0,1.0);
 glBegin(GL_POINTS);
 glVertex2i(x,y);
 glEnd();

}

void drawcircle(int x,int y, int r)
{
 float theta;
 
 for(int i=0; i<=360; i++)
 {
   theta=(3.142/180)*i;
   plotpixel(250+r*cos(theta),250+r*sin(theta));   
 }
 
}

void eightway(int x, int y, int xc, int yc)
{
  plotpixel(x+xc,y+yc);
  plotpixel(x-xc,y+yc);
  plotpixel(x+xc,y-yc);
  plotpixel(x-xc,y-yc);
  plotpixel(x+yc,y+xc);
  plotpixel(x-yc,y+xc);
  plotpixel(x+yc,y-yc);
  plotpixel(x-yc,y-yc);
}

void bresehnms(int x1, int y1, int r)
{
 int x=0;
 int y=r;
 int p=3-2*r;
 
 while(x<=y)
 {
   eightway(x1,y1,x,y);
   if(p>0)
   {
     y--;
     p=p+4*(x-y)+10;
   }
   else
   {
     p=p+4*x+6;
   }
   
   x++;
 }  
 
}

void renderfun()
{
 glClear(GL_COLOR_BUFFER_BIT);
 drawcircle(0,0,100);
 glFlush();
 
}

int main(int argc, char **argv)
{
 glutInit(&argc,argv);
 glutInitWindowSize(500,500);
 glutInitWindowPosition(400,150);
 glutInitDisplayMode(GLUT_SINGLE);
 glutCreateWindow("Circle drawing");
 glClearColor(0,0,0,1);
 gluOrtho2D(0,500,0,500);
 glMatrixMode(GL_PROJECTION);
 glutDisplayFunc(renderfun);
 glutMainLoop();
 
return 0;

}
