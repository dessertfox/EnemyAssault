#include <SDL.h>
#include <SDL_opengl.h>
#include <stdio.h>
#include "ScreenPt.h"
#include "Player.h"
#include "Object.h"

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;
const int SCREEN_BPP = 32;
const int SCREEN_FPS = 60;

bool quit = false;

GLboolean upPressed = false;
GLboolean downPressed = false;
GLboolean leftPressed = false;
GLboolean rightPressed = false;

ScreenPt newScreenPt;
Player player(100, 100, 50, 50);
Object background(0, 0, SCREEN_WIDTH, 1);
Object powerUp(400, 400, 50, 50);
Object randomObject(300, 300, 100, 100);

GLint powerUpPointsX[3];
GLint powerUpPointsY[3];

GLint randomObjectPointsX[4];
GLint randomObjectPointsY[4];

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

	/*GLenum error = glGetError();
	if(error != GL_NO_ERROR)
	{
		printf("Error initializing OpenGL! %s\n", gluErrorString(error));
		return false;
	}*/

	powerUpPointsX[0] = 400;
	powerUpPointsX[1] = 400;
	powerUpPointsX[2] = 450;

	powerUpPointsY[0] = 400;
	powerUpPointsY[1] = 450;
	powerUpPointsY[2] = 450;

	randomObjectPointsX[0] = 300;
	randomObjectPointsX[1] = 300;
	randomObjectPointsX[2] = 400;
	randomObjectPointsX[3] = 400;

	randomObjectPointsY[0] = 300;
	randomObjectPointsY[1] = 400;
	randomObjectPointsY[2] = 400;
	randomObjectPointsY[3] = 300;

	return true;
}

void HandleKeydown(SDL_keysym *keysym)
{
	switch(keysym->sym)
	{
		case SDLK_ESCAPE: quit = true;
		break;
	}
}

//void SpecialKeys(int key, int x, int y)
//{
//	if(GLUT_KEY_UP == key)
//	{
//		upPressed = true;
//	}
//	if(GLUT_KEY_DOWN == key)
//	{
//		downPressed = true;
//	}
//	if(GLUT_KEY_LEFT == key)
//	{
//		leftPressed = true;
//	}
//	if(GLUT_KEY_RIGHT == key)
//	{
//		rightPressed = true;
//	}
//}


//void SpecialKeysUp(int key, int x, int y)
//{
//	if(GLUT_KEY_UP == key)
//	{
//		upPressed = false;
//	}
//	if(GLUT_KEY_DOWN == key)
//	{
//		downPressed = false;
//	}
//	if(GLUT_KEY_LEFT == key)
//	{
//		leftPressed = false;
//	}
//	if(GLUT_KEY_RIGHT == key)
//	{
//		rightPressed = false;
//	}
//}

static void ProcessEvents()
{
	SDL_Event event;

	while(SDL_PollEvent(&event))
	{
		switch(event.type)
		{
			case SDL_KEYDOWN: HandleKeydown(&event.key.keysym);
			break;
			case SDL_QUIT: quit = true;
			break;
		}
	}
}

void ScreenConstraint(Player a)
{
	if(a.xPos < 0)
	{
		a.xPos = 0;
	}
	if(a.xPos + a.width > SCREEN_WIDTH)
	{
		a.xPos = SCREEN_WIDTH - a.width;
	}
	if(a.yPos < 0)
	{
		a.yPos = 0;
	}
	if(a.yPos + a.height > SCREEN_HEIGHT)
	{
		a.yPos = SCREEN_HEIGHT - a.height;
	}
}

bool CollisionDetected(Object a, Object b)
{
	if(a.xPos + a.width <= b.xPos)
	{
		return false;
	}
	if(a.xPos >= b.xPos + b.width)
	{
		return false;
	}
	if(a.yPos >= b.yPos + b.height)
	{
		return false;
	}
	if(a.yPos + a.height <= b.yPos)
	{
		return false;
	}
	return true;
}

void Physics(Object *a, Object *b)
{
	GLint topTop = b->yPos;
	GLint topBottom = b->yPos + 2;
	GLint bottomTop = b->yPos + b->height - 2;
	GLint bottomBottom = b->yPos + b->height;
	GLint leftLeft = b->xPos;
	GLint leftRight = b->xPos + 2;
	GLint rightLeft = b->xPos + b->width - 2;
	GLint rightRight = b->xPos + b->width;

	if(a->yPos + a->height > topTop && a->yPos + a->height < topBottom)
	{
		a->yPos -= (a->yPos + a->height) - b->yPos;
	}
	if(a->yPos < bottomBottom && a->yPos > bottomTop)
	{
		a->yPos += (b->yPos + b->height) - a->yPos;
	}
	if(a->xPos + a->width > leftLeft && a->xPos + a->width < leftRight)
	{
		a->xPos -= (a->xPos + a->width) - b->xPos;
	}
	if(a->xPos < rightRight && a->xPos > rightLeft)
	{
		a->xPos -= (b->xPos + b->width) - a->xPos;
	}
}

void Render()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//glColor3f(1.0, 0.0, 0.0);

	//glBegin(GL_LINE_LOOP);
	//	/*SetPixel(50, 100);
	//	SetPixel(75, 150);
	//	SetPixel(300, 200);
	//	SetPixel(200, 100);*/
	//	CircleMidpoint(400, 400, 100);
	//glEnd();

	//background.Render();
	powerUp.Render(powerUpPointsX, powerUpPointsY);
	randomObject.Render(randomObjectPointsX, randomObjectPointsY);
	player.Render();

	SDL_GL_SwapBuffers();
}

void update()
{
	glMatrixMode(GL_MODELVIEW);
	glPopMatrix();
	glLoadIdentity();

	/*if(CollisionDetected(powerUp, randomObject))
	{
		Physics(&powerUp, &randomObject);
	}*/

	ScreenConstraint(player);

	if(upPressed)
	{
		player.yPos += 1.0f;
	}
	if(downPressed)
	{
		player.yPos -= 1.0f;
	}
	if(leftPressed)
	{
		player.xPos -= 1.0f;
	}
	if(rightPressed)
	{
		player.xPos += 1.0f;
	}
	
	//background.yPos -= 1.0;

	//glutPostRedisplay();
}

int main(int argc, char *args[])
{
	const SDL_VideoInfo *info = NULL;
	SDL_Event keyEvent;

	int flags = 0;

	if(SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		fprintf(stderr, "SDL Video Initialization failed: %s\n", SDL_GetError());
	}

	info = SDL_GetVideoInfo();

	if(!info)
	{
		fprintf(stderr, "SDL Video query failed: %s\n", SDL_GetError());
	}

	SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 5);
	SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 5);
	SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 5);
	SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 16);
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

	flags = SDL_OPENGL;

	if(SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, flags) == 0)
	{
		fprintf(stderr, "Video mode set failed: %s\n", SDL_GetError());
	}

	InitGL();

	if(!InitGL())
	{
		printf("Unable to initialize graphics library!");
		return 1;
	}

	while(!quit)
	{
		ProcessEvents();
		Render();
		while(SDL_PollEvent(&keyEvent))
		{
			player.Controller(&keyEvent.key.keysym);
		}
	}

	SDL_Quit();

	/*glutInit(&argc, args);

	glutInitContextVersion(2, 1);

	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(SCREEN_WIDTH, SCREEN_HEIGHT);
	glutCreateWindow("OpenGL");*/

	/*glutDisplayFunc(Render);
	glutKeyboardFunc(handleKeys);
	glutSpecialFunc(SpecialKeys);
	glutSpecialUpFunc(SpecialKeysUp);
	glutTimerFunc(1000 / SCREEN_FPS, RunMainLoop, 0);
	glutMainLoop();*/
	
	return 0;
}

void RunMainLoop(int val)
{
	Render();
}