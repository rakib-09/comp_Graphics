#include <stdio.h>
#include <GL/glut.h>
void myInit(void)
{	glClearColor(1.0, 1.0, 1.0, 0.0);
	glColor3f(0.0f, 0.0f, 0.0f);
	glPointSize(4.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 500.0, 0.0, 500.0);
	}

void myDisplay(void)
{   glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0, 0.0, 0.0);
	glPointSize(4.0);


	int x=0,y=0;
	for(int i=0;i<=7;i++)
    {
        for(int j=0;j<=7;j++)
        {
        if(i%2!=0&&j%2!=0)
        {
        glBegin(GL_QUADS);
        glVertex2i(x+50,y+ 50);
        glVertex2i(x+50,y+ 100);
        glVertex2i(x+100,y+100);
        glVertex2i(x+100,y+50);
        glEnd();
        glFlush();
        }
        else if(i%2!=0&&j%2==0)
        {
        glBegin(GL_LINE_LOOP);
        glVertex2i(x+50,y+ 50);
        glVertex2i(x+50,y+100);
        glVertex2i(x+100,y+100);
        glVertex2i(x+100,y+50);
        glEnd();
        glFlush();
        }
        else if(i%2==0&&j%2!=0)
        {
        glBegin(GL_LINE_LOOP);
        glVertex2i(x+50,y+ 50);
        glVertex2i(x+50,y+100);
        glVertex2i(x+100,y+100);
        glVertex2i(x+100,y+50);
        glEnd();
        glFlush();
        }
        else if(i%2==0&&j%2==0)
        {
        glBegin(GL_QUADS);
        glVertex2i(x+50,y+ 50);
        glVertex2i(x+50,y+100);
        glVertex2i(x+100,y+100);
        glVertex2i(x+100,y+50);
        glEnd();
        glFlush();
        }
        x=x+50;
        }
    x=0;
    y=y+50;
    }

}
int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(600, 600);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Chess Board");
	glutDisplayFunc(myDisplay);
	myInit();
	glutMainLoop();
}
