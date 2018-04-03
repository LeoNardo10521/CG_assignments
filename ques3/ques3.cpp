#include<GL/glut.h>
#include<cmath>

//define the car class
class car {
public:
	const int n = 100;// n times when draw the circle
	const GLfloat R = 20;// the radius of the circle
	const GLfloat pi = 3.1415926536f;
	GLfloat displace = 0;// the displacement of the car

	void init()
	{
		glClearColor(0.2f, 0.2f, 0.2f, 1.0f);// the background color

		glMatrixMode(GL_PROJECTION);// the projection matrix
		glLoadIdentity();
		glOrtho(-100, 500, -100, 100, -100, 100);

		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glEnable(GL_DEPTH_TEST);//enable the depth test
	}

	void display()
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		glPushMatrix();
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		
		glTranslatef(displace, 0, 0);// translation of the car using the displacement

		if (displace<400) displace += 0.01;//move automatically

		glBegin(GL_TRIANGLES);//draw the triangle
		glColor3f(0, 0, 1);
		glVertex3i(0, 85, 0);
		glVertex3i(50, 0, 0);
		glVertex3i(-50, 0, 0);
		glEnd();

		glBegin(GL_POLYGON);//draw the ractangle
		glColor3f(1, 0, 0);
		glVertex3i(-70, 0, 30);
		glVertex3i(70, 0, 30);
		glVertex3i(70, -40, 30);
		glVertex3i(-70, -40, 30);
		glEnd();

		glBegin(GL_POLYGON);//draw the circles
		glColor3f(0, 1, 0);
		for (int i = 0; i < n; i++)
		{
			glVertex3f(-30 + R*cos(2 * pi / n*i), -40 + R*sin(2 * pi / n*i), 60);
		}
		glEnd();

		glBegin(GL_POLYGON);
		glColor3f(1, 1, 0);
		for (int i = 0; i < n; i++)
		{
			glVertex3f(30 + R*cos(2 * pi / n*i), -40 + R*sin(2 * pi / n*i), 60);
		}
		glEnd();
		glPopMatrix();

		glutSwapBuffers();
	}

	void key_board(GLint key, GLint x, GLint y)
	{
		if (key == GLUT_KEY_LEFT && displace > 10)//move left and don't touch the edge
		{
			displace -= 10.0f;
		}
		if (key == GLUT_KEY_RIGHT && displace < 390)//move right and don't touch the edge
		{
			displace += 10.0f;
		}

		glutPostRedisplay();//redisplay
	}
};

car mycar;

void display()
{
	mycar.display();
}

void key_board(GLint key, GLint x, GLint y)
{
	mycar.key_board(key,x,y);
}

void main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(1200,400);
	glutCreateWindow("Ques2");

	glutDisplayFunc(display);
	glutIdleFunc(display);  //move automatically
	mycar.init();
	glutSpecialFunc(key_board);
	glutMainLoop();
}
