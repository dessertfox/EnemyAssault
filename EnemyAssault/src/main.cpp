#include <GL\freeglut.h>
#include <GL\GL.h>
#include <GL\GLU.h>
#include <stdio.h>

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;
const int SCREEN_FPS = 60;

void SetPixel(int x, int y)
{
	glVertex2i(x, y);
}

bool InitGL()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0, SCREEN_WIDTH, 0.0, SCREEN_HEIGHT, 1.0, -1.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

	GLenum error = glGetError();
	if(error != GL_NO_ERROR)
	{
		printf("Error initializing OpenGL! %s\n", gluErrorString(error));
		return false;
	}

	return true;
}

void Render()
{
	glClear(GL_COLOR_BUFFER_BIT);

	glColor3f(1.0, 0.0, 0.0);

	glBegin(GL_POINTS);
		glVertex2i(180, 15);
		glVertex2i(10, 145);
	glEnd();

	glutSwapBuffers();
}

void RunMainLoop(int val);

int main(int argc, char *args[])
{
	glutInit(&argc, args);

	glutInitContextVersion(2, 1);

	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(SCREEN_WIDTH, SCREEN_HEIGHT);
	glutCreateWindow("OpenGL");

	if(!InitGL())
	{
		printf("Unable to initialize graphics library!");
		return 1;
	}

	glutDisplayFunc(Render);
	glutTimerFunc(1000 / SCREEN_FPS, RunMainLoop, 0);
	glutMainLoop();

	return 0;
}

void RunMainLoop(int val)
{
	Render();

	glutTimerFunc(1000 / SCREEN_FPS, RunMainLoop, val);
}