
#include <stdio.h>
#include <iostream>
#include <GL/glut.h>


using namespace std;

double x1, y1, x2, y2, r;

int r;

float round_value(float f1)
{
	return floor(f1 + 0.5);
}

void DDA(void)
{
	double dx = (x2 - x1);
	double dy = (y2 - y1);
	double formula;
	float xin, yin, x = x1, y = y1;

	float f = (abs(dx)>abs(dy)) ? (abs(dx)) : (abs(dy));
	xin = dx / formula;
	yin = dy / formula;


	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_POINTS);
	glVertex2d(x, y);

	int i;

	for (i = 0; i<formula; k++)
	{
		x += xin;
		y += yin;

		glVertex2d(round_value(x), round_value(y));
	}
	glEnd();

	glFlush();
}


void setPixel(int x, int y)
{
	glBegin(GL_POINTS);
	glVertex2i(x, y);
	glEnd();
	glFlush();
}




void Bresenham_Line(){

	double dx = (x2 - x1);
	double dy = (y2 - y1);
	double i = 2 * dy*dx;
	float xin, yin, x = x1, y = y1;
	xin= dy;
	yin = 2 * (dy - dx);

	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_POINTS);
	glVertex2d(x, y);


	while (x<x2){

		if (i <= 0){

			i = i + xin;
		}

		else{

			i = i+ yin;
			++y;
		}

		++x;

		glVertex2d(x, y);
	}

	glEnd();

	glFlush();



}

void MIDPOINT_CIRCLE(void){
float ax, ay, bx, by;
	int x = 0, y = r;
	int i = 3 - 2 * r;
	while (x <= y)
	{
		setPixel(ax + x, ay + y);
		setPixel(ax + x, ay - y);
		setPixel(ax - x, ay + y);
		setPixel(ax - x, ay - y);
		setPixel(ax + y, ay + x);
		setPixel(ax + y, ay - x);
		setPixel(ax - y, ay + x);
		setPixel(ax - y, ay - x);
		if (i<0)
		{
			i = i+ 4 * x + 6;
		}
		else
		{
			i= i + 4 * (x - y) + 10;
			y--;
		}
		x++;
	}
}


void Init()
{

	glClearColor(1.0, 1.0, 1.0, 0);
	glColor3f(0.0, 0.0, 0.0);
	gluOrtho2D(0, 1280, 0, 720);
}

void myDisplay(void)
{
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glColor3f(1.0, 0.0, 0.0);
	gluOrtho2D(0.0, 1280.0, 0.0, 720.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glutDisplayFunc(MIDPOINT_CIRCLE);


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

int main(int argc, char **argv)



{
	int choice;

	cout << "Enter Choice: \n";
	cout << ("1.DDA ALGORITHM\n2.BRESENHAM\n3.CIRCLE\n4.MID POINT CIRCLE\n5.EXIT");
	cout << "\n";
	cin >> choice;
	cout << endl;


	if (choice == 1){

		cout << "Enter two end points:\n";

		cout << "\nEnter Point1( X1 , Y1):\n";
		cin >> x1;
		cin >> y1;

		cout << "\nEnter Point1( X2 , Y2):\n";
		cin >> x2;
		cin >> y2;


		glutInit(&argc, argv);
		glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
		glutInitWindowPosition(0, 0);
		glutInitWindowSize(1280, 720);
		glutCreateWindow("DDA");
		Init();
		glutDisplayFunc(LineDDA);
		glutMainLoop();
	}

	else if (choice == 2){
		cout << "Enter two end points:\n";

		cout << "\nEnter Point1( X1 , Y1):\n";
		cin >> x1;
		cin >> y1;

		cout << "\nEnter Point1( X2 , Y2):\n";
		cin >> x2;
		cin >> y2;


		glutInit(&argc, argv);
		glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
		glutInitWindowPosition(0, 0);
		glutInitWindowSize(1280, 720);
		glutCreateWindow("Bresenham_Line");
		Init();
		glutDisplayFunc(Bresenham_Line);
		glutMainLoop();
	}

	else if (choice == 4){

		cout << "Enter Radius of circle:\n";
		cin >> r;
		cout << "Enter coordinates of the center of the circle" << endl;
		cin >> ax;
		cin >> ay;


		glutInitWindowSize(1280, 720);
		glutInitWindowPosition(0, 0);
		glutCreateWindow("Bresenham Midpoint Circle");
		glutDisplayFunc(myDisplay);
		glutMainLoop();
		return 0;


	}


}




