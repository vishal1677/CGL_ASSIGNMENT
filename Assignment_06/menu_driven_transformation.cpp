#include<GL/freeglut.h>
#include<GL/gl.h>
#include<math.h>
#include<iostream>
using namespace std;

double mat[3][3]={ {250,250,1},{300,300,1},{350,250,1} };

int ch=-1;

void drawMatrix(double V[3][3], bool isscale)
{
 glBegin(GL_LINE_LOOP);
 for(int i=0; i<3; i++)
 {
   if(isscale){
   glVertex2i(V[i][0]+250,V[i][1]+250);
   }
   else
   {
    glVertex2i(V[i][0],V[i][1]);
   }
   
 }
 glEnd();
   
}

void multiply(double vmat[3][3],double mMat[3][3], bool isscale)
{
  double temp[3][3];
  
  for(int i=0; i<3; i++)
  {
     for(int j=0; j<3; j++)
     {
       double sum=0;
       
       for(int k=0; k<3; k++)
       {
         sum=sum+vmat[i][k]*mMat[k][j];
       }
       temp[i][j]=sum;
     }
  }
  
  drawMatrix(temp, isscale);
  
}

void translate(float tx, float ty)
{
 double tMat[3][3]={ {1,0,0},{0,1,0},{tx,ty,1}};
 
 multiply(mat,tMat,0);
 
}



void rotate(float t)
{
 double r=t*3.14/180;
 float x=250;
 float y=250;
 float r1=x-x*cos(r)+y*sin(r);
 float r2=y-x*sin(r)-y*cos(r);
 
 double rMat[3][3]={{cos(r),sin(r),0 },{-sin(r),cos(r),0},{r1,r2,1}};
 multiply(mat,rMat,0);
 
}

void scale(float sx, float sy)
{
   double sMat[3][3]={{sx,0,0},{0,sy,0},{0,0,1}};
   
   double tmat[3][3];
   
   tmat[0][0]=mat[0][0]-250;
   tmat[0][1]=mat[0][1]-250;
   tmat[0][2]=1;
   
   tmat[1][0]=mat[1][0]-250;
   tmat[1][1]=mat[1][1]-250;
   tmat[1][2]=1;
   
   tmat[2][0]=mat[2][0]-250;
   tmat[2][1]=mat[2][1]-250;
   tmat[2][2]=1;
   
   multiply(tmat,sMat,1);
   
}

void vishal()
{
 glClear(GL_COLOR_BUFFER_BIT);
 glColor3f(1,1,1);
 glBegin(GL_LINES);
 glVertex2i(0,250);
 glVertex2i(500,250);
 glVertex2i(250,0);
 glVertex2i(250,500);
 glEnd();
 drawMatrix(mat,0);
 
 while(true)
 {
 cout<<"Chooce an option\n";
 cout<<"1) Translation\n";
 cout<<"2) Rotate\n";
 cout<<"3) Scale\n";
 cin>>ch;
 
 if(ch == -1)
 {
  cout<<"Please chooce an option\n";
 }
 else if(ch == 1)
 {
   float x=5,y=5;
   cout<<"Enter x translation factor\n";
   cin>>x;
   cout<<"Enter y translation factor\n";
   cin>>y;
   glutPostRedisplay();
   translate(x,y);
   break;
   
  
 }
 else if(ch == 2)
 { 
  float t=0;
  cout<<"Enter angle of rotation\n";
  cin>>t;
  glutPostRedisplay();
  rotate(t);
  break;
 
 }
 else if(ch == 3)
 {
  float x,y;
  cout<<"Enter x scaling factor\n";
  cin>>x;
  cout<<"Enter y scaling factor\n";
  cin>>y;
  glutPostRedisplay();
  scale(x,y);
  break; 
 }
 
}
 
 

 glFlush();
 
}

int main(int argc, char **argv)
{
 glutInit(&argc,argv);
 glutInitWindowSize(500,500);
 glutInitWindowPosition(400,150);
 glutInitDisplayMode(GLUT_SINGLE);
 glutCreateWindow("2D Transformation");
 glClearColor(0,0,0,1);
 gluOrtho2D(0,500,0,500);
 glMatrixMode(GL_PROJECTION);
 glutDisplayFunc(vishal);
 glutMainLoop();
 
return 0;
}
