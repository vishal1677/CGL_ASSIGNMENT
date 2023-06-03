#include<GL/freeglut.h>
#include<GL/gl.h>

int framenumber=0;

void drawwindmill()
{ 
  
 glTranslatef(0,-1,0);
 glColor3f(1.0,1.0,0);
 glBegin(GL_POLYGON);
 glVertex2f(-0.05f,0);
 glVertex2f(-0.05f,2);
 glVertex2f(0.05f,2);
 glVertex2f(0.05f,0);
 glEnd();
 
 glTranslatef(0,2,0);
 glColor3f(1.0,0.0,0.0);
 glRotated(framenumber*(180/45),0,0,1);
 
 for(int i=0; i<4; i++)
 {
   glRotated(90,0,0,1);
   glBegin(GL_POLYGON);
   glVertex2f(0,0);
   glVertex2f(1,0.2);
   glVertex2f(1,-0.2);
   glEnd();  
 }
 
 
}


void vishal()
{
 glClear(GL_COLOR_BUFFER_BIT);
 glLoadIdentity();
 glPushMatrix();
 glScaled(0.5,0.5,1);
 drawwindmill();
 glPopMatrix();
 
 glutSwapBuffers();
 
 glFlush();
 
 

}

void mframe(int v)
{
  framenumber++;
  glutPostRedisplay();
  glutTimerFunc(10,mframe,0);
}

int main(int argc, char ** argv)
{
 glutInit(&argc,argv);
 glutInitWindowSize(500,500);
 glutInitWindowPosition(400,150);
 glutInitDisplayMode(GLUT_DOUBLE);
 glutCreateWindow("Windmill animation");
 glOrtho(0,10,-1,5,-1,1);
 glClearColor(0,0,0,0);
 glMatrixMode(GL_PROJECTION);
 glLoadIdentity();
 glMatrixMode(GL_MODELVIEW);
 glutDisplayFunc(vishal);
 glutTimerFunc(200,mframe,0);
 glutMainLoop();
 
 
return 0;
}
