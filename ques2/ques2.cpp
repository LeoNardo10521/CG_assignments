#include<GL/glut.h>

void init()
{
	glClearColor(0.2f, 0.2f, 0.2f, 1.0f);// define the color of background
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-100, 100, -100, 100);//use 2d projection

	glClear(GL_COLOR_BUFFER_BIT);
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT );

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glBegin(GL_TRIANGLES);// draw the triangle

	glColor3f(0, 0,1);// define the color: blue
	glVertex2i(0, 35);
	glVertex2i(50, -50);
	glVertex2i(-50, -50);

	glEnd();
	glPopMatrix();

	glutSwapBuffers();
}

void main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB );
	glutInitWindowSize(600, 600);
	glutCreateWindow("Ques2");

	glutDisplayFunc(display);//display
	init();
	glutMainLoop();
}
