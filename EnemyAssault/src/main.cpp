#include <GL\freeglut.h>
#include <GL\GL.h>
#include <GL\GLU.h>
#include <stdio.h>
#include "ScreenPt.h"
#include "Player.h"
#include "Object.h"

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;
const int SCREEN_FPS = 60;

bool quit = false;

GLboolean upPressed = false;
GLboolean downPressed = false;
GLboolean leftPressed = false;
GLboolean rightPressed = false;

ScreenPt newScreenPt;
Player player(100, 100, 50, 50);
Object background(0, 0, SCREEN_WIDTH, 1);

void RunMainLoop(int val);
void update();

bool InitGL()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0, SCREEN_WIDTH, 0.0, SCREEN_HEIGHT, 1.0, -1.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glPushMatrix();

	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

	GLenum error = glGetError();
	if(error != GL_NO_ERROR)
	{
		printf("Error initializing OpenGL! %s\n", gluErrorString(error));
		return false;
	}

	return true;
}

void handleKeys(unsigned char key, int x, int y )
{
	/*glMatrixMode(GL_MODELVIEW);
	glPopMatrix();
	glLoadIdentity();

	glTranslatef(-player.xPos, -player.yPos, 0.0f);

	glPushMatrix();*/

	glutPostRedisplay();
}

void SpecialKeys(int key, int x, int y)
{
	if(GLUT_KEY_UP == key)
	{
		upPressed = true;
	}
	if(GLUT_KEY_DOWN == key)
	{
		downPressed = true;
	}
	if(GLUT_KEY_LEFT == key)
	{
		leftPressed = true;
	}
	if(GLUT_KEY_RIGHT == key)
	{
		rightPressed = true;
	}
}

void SpecialKeysUp(int key, int x, int y)
{
	if(GLUT_KEY_UP == key)
	{
		upPressed = false;
	}
	if(GLUT_KEY_DOWN == key)
	{
		downPressed = false;
	}
	if(GLUT_KEY_LEFT == key)
	{
		leftPressed = false;
	}
	if(GLUT_KEY_RIGHT == key)
	{
		rightPressed = false;
	}
}

void Render()
{
	glClear(GL_COLOR_BUFFER_BIT);

	//glColor3f(1.0, 0.0, 0.0);

	glBegin(GL_LINE_LOOP);
		/*SetPixel(50, 100);
		SetPixel(75, 150);
		SetPixel(300, 200);
		SetPixel(200, 100);*/
		//CircleMidpoint(400, 400, 100);
	glEnd();

	background.Render();
	player.Render();

	update();

	glutSwapBuffers();

	glutTimerFunc(1000 / SCREEN_FPS, RunMainLoop, 0);
}

void update()
{
	if(upPressed)
	{
		background.yPos += 1.0f;
	}
	if(downPressed)
	{
		background.yPos -= 1.0f;
	}
	if(leftPressed)
	{
		background.xPos -= 1.0f;
	}
	if(rightPressed)
	{
		background.xPos += 1.0f;
	}
	
	//background.yPos -= 1.0;

	glutPostRedisplay();
}

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
	glutKeyboardFunc(handleKeys);
	glutSpecialFunc(SpecialKeys);
	glutSpecialUpFunc(SpecialKeysUp);
	glutTimerFunc(1000 / SCREEN_FPS, RunMainLoop, 0);
	glutMainLoop();
	
	return 0;
}

void RunMainLoop(int val)
{
	Render();
}