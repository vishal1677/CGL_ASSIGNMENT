//#include<windows.h>
#include<GL/freeglut.h>
#include<GL/gl.h>
#include<stdio.h>
#include<math.h>

GLfloat d = 0;
int a=0;

void MyInit()
{
    glClearColor(0,0,0,1);
    glEnable(GL_DEPTH_TEST);
}

void Spin()
{
    d = d + 0.25;
    if(d > 360)
        d = 0;
    glutPostRedisplay();
}

void Face(GLfloat A[],GLfloat B[],GLfloat C[],GLfloat D[])
{
    glBegin(GL_POLYGON);
        glVertex3fv(A);
        glVertex3fv(B);
        glVertex3fv(C);
        glVertex3fv(D);
    glEnd();
}

void Cube(GLfloat V0[],GLfloat V1[],GLfloat V2[],GLfloat V3[],GLfloat V4[],GLfloat V5[],GLfloat V6[],GLfloat V7[])
{
    glColor3f(1,0,0);
    Face(V0,V1,V2,V3); //Front
    glColor3f(0,1,0);
    Face(V4,V5,V6,V7); //Back
    glColor3f(0,0,1);
    Face(V0,V4,V7,V3); //Left
    glColor3f(1,1,0);
    Face(V1,V5,V6,V2); //Right
    glColor3f(1,0,1);
    Face(V2,V3,V7,V6); //Bot
    glColor3f(0,1,1);
    Face(V0,V1,V5,V4); //Top
}

void Draw()
{
    GLfloat V[8][3] =   {
                            {-0.5, 0.5, 0.5},
                            { 0.5, 0.5, 0.5},
                            { 0.5,-0.5, 0.5},
                            {-0.5,-0.5, 0.5},
                            {-0.5, 0.5,-0.5},
                            { 0.5, 0.5,-0.5},
                            { 0.5,-0.5,-0.5},
                            {-0.5,-0.5,-0.5},
                        };
    GLfloat rV[8][3],r;
    int i;
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    r = d*3.14/180;

    if(a == 1)
    {
        for(i=0;i<8;i++)
        {
            rV[i][0] = V[i][0];
            rV[i][1] = V[i][1]*cos(r)-V[i][2]*sin(r);
            rV[i][2] = V[i][1]*sin(r)+V[i][2]*cos(r);
        }
    }

    if(a == 2)
    {
        for(i=0;i<8;i++)
        {
            rV[i][0] = V[i][2]*sin(r)+V[i][0]*cos(r);
            rV[i][1] = V[i][1];
            rV[i][2] = V[i][2]*cos(r)-V[i][0]*sin(r);
        }
    }

    if(a == 3)
    {
        for(i=0;i<8;i++)
        {
            rV[i][0] = V[i][0]*cos(r)-V[i][1]*sin(r);
            rV[i][1] = V[i][0]*sin(r)+V[i][1]*cos(r);
            rV[i][2] = V[i][2];
        }
    }

    Cube(rV[0],rV[1],rV[2],rV[3],rV[4],rV[5],rV[6],rV[7]);

    glutSwapBuffers();
}

int main(int argc, char *argv[])
{
    printf("Enter the Axis of Rotation [ 1->Xaxis | 2->Yaxis | 3->Zaxis ]: ");
    scanf("%d",&a);
    glutInit(&argc,argv);
    glutInitWindowSize(600,600);
    glutInitWindowPosition(50,150);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("Cube Spin with Matrices");
    MyInit();
    glutDisplayFunc(Draw);
    glutIdleFunc(Spin);
    glutMainLoop();
    return 0;
}

