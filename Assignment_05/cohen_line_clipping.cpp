
#include<GL/freeglut.h>
 
 
// TBRL

int left = 1,right = 2, top = 8, bottom = 4;
int xmin = 100, xmax = 400, ymin = 100, ymax = 400;
int line_co_ordinate[4],i;
float x1=200, y1=250, x2=450,y2=450;
int c1,c2;
int flag = 1,clip_flag=0;
 
 
void myInit()
{
    glClearColor(1.0, 1.0, 1.0, 0);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0, 0.0, 1.0);
    gluOrtho2D(0, 500,0, 500);
    glFlush();
    
}

 
int getCode(int x, int y)
{
    int code = 0;
 
    if(x < xmin)
    {
        code = code | left;
    }
     
    if(x > xmax)
    {
        code = code | right;
    }
     
    if(y < ymin)
    {
        code = code | bottom;
    }
     
    if(y > ymax)
    {
        code = code | top;
    }
 
    return code;
}
 
 
void clip()
{
    int c;
    float x,y;
    float m = (y2-y1)/(x2-x1);
    if(c1)
    {
        c = c1;
    }
    else
    {
        c = c2;
    }
 
    if( c & left)
    {
        x = xmin;
        y = y1 + m*(xmin - x1) ;
    }
 
    if( c & right)
    {
        x = xmax;
        y = m*(xmax - x1) + y1; 
    }
     
    if( c & top)
    {
        y = ymax;
        x = ((ymax - y1)/m) + x1;
    }
     
    if( c & bottom)
    {
        y = ymin;
        x = ((ymin - y1)/m) + x1;
    }    
 
    if(c == c1)
    {
        x1 = x;
        y1 = y;
    }
    else
    {
        x2 = x;
        y2 = y;
    }
     
}
 
void display()
{
 
    glClear(GL_COLOR_BUFFER_BIT); //clearing buffer
    glColor3f(1.0, 0.0, 0.0);     //assigning color
    glPointSize(4);
    glBegin(GL_LINE_LOOP);
        glVertex2f(xmin,ymin);
        glVertex2f(xmax,ymin);
        glVertex2f(xmax,ymax);
        glVertex2f(xmin,ymax);
    glEnd();    
     
    if(flag == 1)
    {
        glBegin(GL_LINES);
        glVertex2f(x1,y1);
        glVertex2f(x2,y2);
        glEnd();
    }   
     
    while(1 & clip_flag == 1) 
   {
        c1 = getCode(x1,y1);
         
        c2 = getCode(x2,y2);
 
        // Line both point inside
        if((c1 | c2)==0)
        break;
 
        // Line both point outside
        else if((c1&c2) != 0)       
        {
            flag = 0;
        break;
        }
        
        else
        {
        clip();
        }
         
         
    }
    glFlush();
}  
 
 
// Keyboard Func
void Key(unsigned char ch,int x,int y)
{
       cout<<ch<<"\n";
       
        if(ch=='c')
        {
            clip_flag = 1;
         
             glutPostRedisplay();
    }
}
 
// Mouse Func
void mouse_input(int button,int state,int x,int y)
{
    if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && i < 4)
    {
        line_co_ordinate[i] = x;
        i=i+1;
        line_co_ordinate[i] = 500-y;
        i++;
    }
    
    if(i==4)
    {
        i=0;
        x1 = line_co_ordinate[0];
        y1 = line_co_ordinate[1];
        x2 = line_co_ordinate[2];
        y2 = line_co_ordinate[3];   
         
        display();
    }
}
 
 
int main(int argc,char **argv)
{
    glutInit(&argc,argv);
    glutInitWindowPosition(100,100);
    glutInitWindowSize(500,500);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutCreateWindow("Cohen Suderland");
    myInit();
    glutDisplayFunc(display);
    glutKeyboardFunc(Key);
    glutMouseFunc(mouse_input);
    glutMainLoop();
    return 0;
}
