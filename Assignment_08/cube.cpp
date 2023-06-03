#include<GL/freeglut.h>
#include<GL/gl.h>
#include<math.h>

GLfloat T=0;


void spin()
{
 T=T+0.25;
 if(T>360)
 {
  T=0;
  glutPostRedisplay();
  
 }
}

void Face(GLfloat A[], GLfloat B[], GLfloat C[], GLfloat D[])
{
  glBegin(GL_POLYGON);
  glVertex3fv(A);
  glVertex3fv(B);
  glVertex3fv(C);
  glVertex3fv(D);
  glEnd();
}

void Cube(GLfloat v0[], GLfloat v1[], GLfloat v2[], GLfloat v3[], GLfloat v4[], GLfloat v5[], GLfloat v6[], GLfloat v7[] )
{
  glColor3f(1,0,0);
  Face(v0,v1,v2,v3);
  
  glColor3f(0,1,0);
  Face(v4,v5,v6,v7);
  
  //glColor3f(0,0,1);
  //Face(v0,v4,v7,v3);
  
  //glColor3f(1,1,0);
  //Face(v1,v5,v6,v2);
  
  //glColor3f(0,1,1);
  //Face(v0,v1,v5,v4);
  
  //glColor3f(1,0,1);
  //Face(v3,v2,v6,v7);
  
  
  
}

void vishal()
{
 GLfloat V[8][3]={ 
                 {-0.5,0.5,0.5},
                 {0.5,0.5,0.5},
                 {0.5,-0.5,0.5},
                 {-0.5,-0.5,0.5},
                 
                 {-0.5,0.5,-0.5},
                 {0.5,0.5,-0.5},
                 {0.5,-0.5,-0.5},
                 {-0.5,-0.5,-0.5},        
 };
 
 glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
 GLfloat rV[8][3],r;
    int i;
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    r = T*3.14/180;
    
       for(i=0;i<8;i++)
        {
            rV[i][0] = V[i][2]*sin(r)+V[i][0]*cos(r);
            rV[i][1] = V[i][1];
            rV[i][2] = V[i][2]*cos(r)-V[i][0]*sin(r);
        }

 //glLoadIdentity();
 //glRotatef(T,0,1,0);
 Cube(rV[0],rV[1],rV[2],rV[3],rV[4],rV[5],rV[6],rV[7]);
 glutSwapBuffers();
 
 glFlush();
 
}

int main(int argc, char ** argv)
{
 glutInit(&argc,argv);
 glutInitWindowSize(500,500);
 glutInitWindowPosition(400,150);
 glutInitDisplayMode(GLUT_RGB|GLUT_DOUBLE|GLUT_DEPTH);
 glutCreateWindow("3D Cube");
 glClearColor(0,0,0,1);
 glEnable(GL_DEPTH_TEST);
 glutDisplayFunc(vishal);
 glutIdleFunc(spin);
 glutMainLoop();
 
 
return 0;
}
