#include <GL/freeglut.h>
#include <GL/gl.h>
#include <iostream>
using namespace std;

struct Color//declare color stucture
{
        float r,g,b;
};

Color getPixelcolor(float x,float y)//get pixelcolor
{
        Color c;
        glReadPixels(x,y,1,1,GL_RGB,GL_FLOAT,&c);//get color in 'c'
        return c;//return c
}//end

void setPixelcolor(float x,float y)
{
        glBegin(GL_POINTS);//draw point
                glColor3f(1.0,0.0,0.0);//set point color to red
                glVertex2f(x,y);
        glEnd();
}//end

void floodfill(float x,float y)
{
        Color c = getPixelcolor(x,y);//gets color of current pixel
        Color old = {1.0,1.0,1.0};
        
        if(c.r == old.r && c.g == old.g && c.b == old.b)//if color of current pixel if white
        {
                setPixelcolor(x,y);//set pixel color to red 
                floodfill(x+1,y);//call floodfill recursively for four-connected points
                floodfill(x,y+1);
                floodfill(x-1,y);
                floodfill(x,y-1);              
        }
        return;
}//end

void render()
{
        glClearColor(1.0,1.0,1.0,0.0);//clear color to white
        glClear(GL_COLOR_BUFFER_BIT);//set color
        glMatrixMode(GL_PROJECTION);//set matrix mode
        glLoadIdentity();//load identity matrix
        gluOrtho2D(0,400,0,400);//sets axis length
        glFlush();//flush buffer and execute all command
}//end



void draw()//draw '+' Diagram
{
        glBegin(GL_LINES);
                glColor3f(0.0,0.0,0.0);//sets black color
                glVertex2d(100,150);
                glVertex2d(100,200);
                
                glVertex2d(100,200);
                glVertex2d(50,200);
                
                glVertex2d(50,200);
                glVertex2d(50,220);
                
                glVertex2d(50,220);
                glVertex2d(100,220);
                
                glVertex2d(100,220);
                glVertex2d(100,270);
                
                glVertex2d(100,270);
                glVertex2d(120,270);
                
                glVertex2d(120,270);
                glVertex2d(120,220);
                
                glVertex2d(120,220);
                glVertex2d(170,220);
                
                glVertex2d(170,220);
                glVertex2d(170,200);
                
                glVertex2d(170,200);
                glVertex2d(120,200);
                
                glVertex2d(120,200);
                glVertex2d(120,150);
                
                glVertex2d(120,150);
                glVertex2d(100,150);
        
        glEnd();//end
        floodfill(110,210);//fill '+' Diagram
        glFlush();//flush buffer and execute all command
}//end

void rotate()//draw '+' Diagram
{
        float y_tra = 210 - (320/1.41);//y-translation to have same level
        glBegin(GL_LINES);
                glColor3f(0.0,0.0,0.0);//sets black color
                glVertex2d(400+(-50/1.41),250/1.41 + y_tra);
                glVertex2d(400+(-100/1.41),300/1.41 + y_tra);
                
                glVertex2d(400+(-100/1.41),300/1.41 + y_tra);
                glVertex2d(400+(-150/1.41),(250/1.41) + y_tra);
                
                glVertex2d(400+(-150/1.41),(250/1.41) + y_tra);
                glVertex2d(400+(-170/1.41),270/1.41 + y_tra);
                
                glVertex2d(400+(-170/1.41),270/1.41 + y_tra);
                glVertex2d(400 + (-120/1.41),320/1.41 + y_tra);
                
                glVertex2d(400 + (-120/1.41),320/1.41 + y_tra);
                glVertex2d(400 +(-170/1.41),370/1.41 + y_tra);
                
                glVertex2d(400 +(-170/1.41),370/1.41 + y_tra);
                glVertex2d(400+(-150/1.41),390/1.41 + y_tra);
                
                glVertex2d(400+(-150/1.41),390/1.41 + y_tra);
                glVertex2d(400+(-100/1.41),340/1.41 + y_tra);
                
                glVertex2d(400+(-100/1.41),340/1.41 + y_tra);
                glVertex2d(400+(-50/1.41),390/1.41 + y_tra);
                
                glVertex2d(400+(-50/1.41),390/1.41 + y_tra);
                glVertex2d(400+(-30/1.41),370/1.41 + y_tra);
                
                glVertex2d(400+(-30/1.41),370/1.41 + y_tra);
                glVertex2d(400+(-80/1.41),320/1.41 + y_tra);
                
                glVertex2d(400+(-80/1.41),320/1.41 + y_tra);
                glVertex2d(400+(-30/1.41),270/1.41 + y_tra);
                
                glVertex2d(400+(-30/1.41),270/1.41 + y_tra);
                glVertex2d(400+(-50/1.41),250/1.41 + y_tra);
        
        glEnd();//end
        floodfill(400+(-100/1.41),320/1.41 + y_tra);//fill rotated Diagram
        glFlush();//flush buffer and execute all command
}//end

void mouse(int button,int state,int x,int y)//On only when menu is commented
{
        if(button == GLUT_LEFT_BUTTON && state == GLUT_UP)//if left button and up
        {
                render();//draw '+' diagram
                draw();
        }
        else if(button == GLUT_RIGHT_BUTTON && state == GLUT_UP)//if right button and up
        {
                render();//draw '+' and rotated diagram
                draw();
                rotate();
        }       
}//end

int main(int argc,char **argv)//taking command line orguments
{
        int e;
        glutInit(&argc,argv);//initialise glut with libraries
        glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);//initalise mode 
        glutInitWindowPosition(1000,200);//sets position of window
        glutInitWindowSize(400,400);//sets size of window
        glutCreateWindow("Practical");//create window
        glutMouseFunc(mouse);//activate mouse function(activated only when menu is commented)
        render();//call to function
        do
        {
                cout<<"*Menu = \n1 : Given Diagram\n2 : Rotated Diagram\n3 : Exit\n";//create menu
                cout<<"Enter Your Choice = ";
                cin>>e;
                switch(e)
                {
                        case 1://Draw '+' Diagram
                                render();//clear screen
                                draw();
                                break;
                                
                        case 2://Draw rotated '+' Diagram
                                rotate();
                                break;
                                
                        case 3://exit from program
                                exit(1);
                }
        }while(e);
        
        glutMainLoop();//infinite loop untill user closes window
return 0;
}//end of program
