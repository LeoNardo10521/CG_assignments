#include<GL/glut.h>

void init()
{
	glClearColor(0.2f, 0.2f, 0.2f, 1.0f);//define the color of background

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-100, 100, -100, 100, -100, 100);//3d projection

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glEnable(GL_DEPTH_TEST);//enable the depth test
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	// use gluLootAt function to observe from different place other than the front in order to see the 3d structure
	gluLookAt(1, 1, 1, 0, 0, 0, 0, 1, 0);

	glBegin(GL_QUADS);// to draw the 6 sides of the cube

	glColor3f(1, 0, 0);// red color
	glVertex3i(50, 50, 50);
	glVertex3i(50, -50, 50);
	glVertex3i(-50, -50, 50);
	glVertex3i(-50, 50, 50);

	glVertex3i(50, 50, -50);
	glVertex3i(50, -50, -50);
	glVertex3i(-50, -50, -50);
	glVertex3i(-50, 50, -50);

	glColor3f(0.6, 0,0 );//red color with some shade
	glVertex3i(-50, 50, -50);
	glVertex3i(50, 50, -50);
	glVertex3i(50, 50, 50);
	glVertex3i(-50, 50, 50);

	glVertex3i(-50, -50, -50);
	glVertex3i(50, -50, -50);
	glVertex3i(50, -50, 50);
	glVertex3i(-50, -50, 50);

	glColor3f(0.3, 0, 0);//red color with more shade
	glVertex3i(50, 50, -50);
	glVertex3i(50, 50, 50);
	glVertex3i(50, -50, 50);
	glVertex3i(50, -50, -50);

	glVertex3i(-50, 50, -50);
	glVertex3i(-50, 50, 50);
	glVertex3i(-50, -50, 50);
	glVertex3i(-50, -50, -50);

	glEnd();

	glutSwapBuffers();
}

void main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);//double caches and depth
	glutInitWindowSize(600, 600);
	glutCreateWindow("Ques1");

	glutDisplayFunc(display);
	init();
	glutMainLoop();
}
