#include <stdio.h>
#include <iostream>
#include <GL/glut.h>
#include <math.h>

using namespace std;



double x1,y1,x2,y2,x3,y3,x4,y4;



void myDisplay(void)
{
glClear (GL_COLOR_BUFFER_BIT);
glColor3f (0.0, 0.0, 1.0);
glPointSize(4.0);
glBegin(GL_QUADS);
glVertex2i(x1,y1);
glVertex2i(x2, y2);
glVertex2i(x3, y3);
glVertex2i(x4,y4);
glEnd();
glFlush ();


}


void myInit (void)
{
glClearColor(1.0, 1.0, 1.0, 0.0);
glColor3f(0.0f, 0.0f, 0.0f);
glPointSize(4.0);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(0.0, 640.0, 0.0, 360.0);
}

void Scale(){

	int scale;
	double x,y;



	cout<<" scaling amount on X-axis and Y-Axis"<<endl;
	cin>>x;
	cin>>y;

glClear (GL_COLOR_BUFFER_BIT);
glColor3f (0.0, 0.0, 1.0);
glPointSize(4.0);
glBegin(GL_QUADS);
glVertex2i(x1,y1);
glVertex2i(x2, y2);
glVertex2i(x3, y3);
glVertex2i(x4,y4);
glEnd();
glFlush ();

glBegin(GL_QUADS);
glVertex2i(x1*x,y1*y);
glVertex2i(x2*x, y2*y);
glVertex2i(x3*x, y3*y);
glVertex2i(x4*x,y4*y);
glEnd();
glFlush ();

}


void Translate(){

	double x,y;

	//for translate

	cout<<"Enter translate value: "<<endl;
	cin>>x;
	cin>>y;
glClear (GL_COLOR_BUFFER_BIT);
glColor3f (0.0, 0.0, 1.0);
glPointSize(4.0);
glBegin(GL_QUADS);
glVertex2i(x1,y1);
glVertex2i(x2, y2);
glVertex2i(x3, y3);
glVertex2i(x4,y4);
glEnd();
glFlush ();

glBegin(GL_QUADS);
glVertex2i(x1+x,y1+y);
glVertex2i(x2+x, y2+y);
glVertex2i(x3+x, y3+y);
glVertex2i(x4+x,y4+y);
glEnd();
glFlush ();



}


void Rotate(){

	double x;

	cout<<"Enter angle of rotation: "<<endl;
	cin>>x;

glClear (GL_COLOR_BUFFER_BIT);
glColor3f (0.0, 0.0, 1.0);
glPointSize(4.0);
glBegin(GL_QUADS);
glVertex2i(x1,y1);
glVertex2i(x2, y2);
glVertex2i(x3, y3);
glVertex2i(x4,y4);
glEnd();
glFlush ();

glBegin(GL_QUADS);
glVertex2i(x1*cos(x)-y1*sin(x), x1*sin(x)+y1*sin(x));
glVertex2i(x2*cos(x)-y2*sin(x), x2*sin(x)+y2*sin(x));
glVertex2i(x3*cos(x)-y3*sin(x), x3*sin(x)+y3*sin(x));
glVertex2i(x4*cos(x)-y4*sin(x),x4*sin(x)+y4*sin(x));
glEnd();
glFlush ();

}


void Mirror(){

	char choice;

	cout<<"Enter Choice of mirror axis: "<<endl;
	cin>>choice;

	if(choice=='x')
    {
glClear (GL_COLOR_BUFFER_BIT);
glColor3f (0.0, 0.0, 1.0);
glPointSize(4.0);
glBegin(GL_QUADS);
glVertex2i(x1,y1);
glVertex2i(x2, y2);
glVertex2i(x3, y3);
glVertex2i(x4,y4);
glEnd();
glFlush ();

glBegin(GL_QUADS);
glVertex2i(x1,-y1);
glVertex2i(x2,- y2);
glVertex2i(x3,- y3);
glVertex2i(x4,-y4);
glEnd();
glFlush ();

	}

	 if (choice=='y'){
glClear (GL_COLOR_BUFFER_BIT);
glColor3f (0.0, 0.0, 1.0);
glPointSize(4.0);
glBegin(GL_QUADS);
glVertex2i(x1,y1);
glVertex2i(x2, y2);
glVertex2i(x3, y3);
glVertex2i(x4,y4);
glEnd();
glFlush ();

glBegin(GL_QUADS);
glVertex2i(-x1,y1);
glVertex2i(-x2,y2);
glVertex2i(-x3,y3);
glVertex2i(-x4,y4);
glEnd();
glFlush ();

	}




}

void condition()
{
    cout<<"Enter Your Choice: "<<endl;
	cout<<"1.Scale\n2.Translate\n3.Rotate\n4.Mirror\n"<<endl;
	int s;
	cin >> s;
	switch (s)
	{
	case 1: glutDisplayFunc(Scale);
		break;
	case 2:glutDisplayFunc(Translate);
		break;
	case 3:glutDisplayFunc(Rotate);
		break;
	case 4:glutDisplayFunc(Mirror);
		break;
	}

}


void main(int argc, char** argv)
{


	cout<<"Enter coordinates"<<endl;

	cin>>x1;
	cin>>y1;
	cin>>x2;
	cin>>y2;
	cin>>x3;
	cin>>y3;
	cin>>x4;
	cin>>y4;


glutInit(&argc, argv);
glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
glutInitWindowSize (1280, 720);
glutInitWindowPosition (100, 150);
glutCreateWindow ("transformation");
condition();
myInit ();
glutMainLoop();
}

