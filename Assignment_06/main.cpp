/*
 Apply 2D trnasformation on euilateral traingle 
 1-Translation
 2-Rotation
 3-Scaling
 4-Shear
 
*/
#include<GL/freeglut.h>
#include<GL/gl.h>
#include<math.h>
#include<cstdio>

double mat[3][3]={0};

void plotmatrix(double mat[3][3])
{
 glColor3f(1,1,1);
 glBegin(GL_LINE_LOOP);
 for(int i=0; i<3; i++)
 {
  glVertex2i(mat[i][0],mat[i][1]);
 }
 glEnd();
 

 
}

void mulMatrix(double mat1[3][3], double mat2[3][3])
{
  double temp[3][3];
  // multiply both matrix
 for(int i=0; i<3; i++)
 {
   for(int j=0; j<3; j++)
   {
     double sum=0;
     for(int k=0; k<3; k++)
     {
      sum=sum+mat1[i][k]*mat2[k][j];
     }
     temp[i][j]=sum;
   }
 }
 
 plotmatrix(temp);
 
}

void translate(double mat[3][3])
{
 double temp[3][3];
 double Tmat[3][3]={0};
 
 Tmat[0][0]=1;
 Tmat[1][1]=1;
 Tmat[2][2]=1;
 Tmat[2][0]=100;
 Tmat[2][1]=100;
 mulMatrix(mat,Tmat);
}

void rotate(double mat[3][3])
{
 // rotate matrix about point rx,ry with angle theta
 
 double theta,rx,ry;
 double Rmat[3][3]={0};
 theta=-45*(3.142/180);
 rx=250;
 ry=250;
 
 Rmat[0][0]=cos(theta);
 Rmat[0][1]=sin(theta);
 Rmat[1][0]=-sin(theta);
 Rmat[1][1]=cos(theta);
 Rmat[2][2]=1;
 
 Rmat[2][0]=-rx*cos(theta)+ry*sin(theta)+rx;
 Rmat[2][1]=-rx*sin(theta)-ry*cos(theta)+ry;
 
 mulMatrix(mat,Rmat);
 
}

void scaleMatrix(double mat[3][3])
{
 double Smat[3][3]={0};
 Smat[0][0]=2;
 Smat[1][1]=2;
 Smat[2][2]=1;
 mulMatrix(mat,Smat);
 
 
}

void drawtriangle()
{
 mat[0][0]=0;
 mat[0][1]=0;
 mat[0][2]=1;
 mat[1][0]=100;
 mat[1][1]=100;
 mat[1][2]=1;
 mat[2][0]=150;
 mat[2][1]=0;
 mat[2][2]=1;
 plotmatrix(mat);
 scaleMatrix(mat);
  
}

void myfunc()
{
 glClear(GL_COLOR_BUFFER_BIT);
 glColor3f(1,1,1);
 glBegin(GL_LINES);
 glVertex2i(0,250);
 glVertex2i(500,250);
 glVertex2i(250,0);
 glVertex2i(250,500);
 glEnd();
 drawtriangle();

 
 glFlush();
 
}

int main(int argc, char **argv)
{
 glutInit(&argc,argv);
 glutInitWindowSize(500,500);
 glutInitWindowPosition(400,150);
 glutInitDisplayMode(GLUT_SINGLE);
 glutCreateWindow("2D tranformation");
  gluOrtho2D(0,500,0,500);
  glClearColor(0,0,0,0);
  glMatrixMode(GL_PROJECTION);
 glutDisplayFunc(myfunc);
 glutMainLoop();
 

return 0;

}

