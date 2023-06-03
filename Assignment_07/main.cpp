#include<GL/freeglut.h>
#include<GL/gl.h>
#include<math.h>



void koch(float x1, float y1, float x2, float y2, int n)
{
  float x3,y3,x4,y4,x,y;
  
  float p=60*3.142/180;
  
  x3=(2*x1+x2)/3;
  y3=(2*y1+y2)/3;
  x4=(x1+2*x2)/3;
  y4=(y1+2*y2)/3;
  
  x=x3+(x4-x3)*cos(p)+(y4-y3)*sin(p);
  y=y3-(x4-x3)*sin(p)+(y4-y3)*cos(p);
  
  if(n>0)
  {
   koch(x1,y1,x3,y3,n-1);
   koch(x3,y3,x,y,n-1);
   koch(x,y,x4,y4,n-1);
   koch(x4,y4,x2,y2,n-1);
  }
  else
  {
   glVertex2i(x1,y1);
   glVertex2i(x3,y3);
   
   glVertex2i(x3,y3);
   glVertex2i(x,y);
   
   glVertex2i(x,y);
   glVertex2i(x4,y4);
   
   glVertex2i(x4,y4);
   glVertex2i(x2,y2);
   
  }
}


void myfunc()
{
 glClear(GL_COLOR_BUFFER_BIT);
 glColor3f(1,1,1);
 glBegin(GL_LINES);
 koch(100,100,200,100,5);
 koch(200,100,150,200,5);
 koch(150,200,100,100,5);
 
 glEnd();
 
 glFlush();
 
}
int main(int argc , char ** argv)
{
 glutInit(&argc,argv);
 glutInitWindowSize(500,500);
 glutInitWindowPosition(400,150);
 glutInitDisplayMode(GLUT_SINGLE);
 glutCreateWindow("KOCH CURVE");
 gluOrtho2D(0,500,0,500);
 glClearColor(0,0,0,0);
 glMatrixMode(GL_PROJECTION);
 glutDisplayFunc(myfunc);
 glutMainLoop();
 
 return 0;
 
}
