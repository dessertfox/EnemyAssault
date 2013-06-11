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

GLboolean upUp = false;
GLboolean downUp = false;
GLboolean leftUp = false;
GLboolean rightUp = false;

ScreenPt newScreenPt;
Player player(100, 100, 50, 50);
Object background(0, 0, SCREEN_WIDTH, 1);
Object powerUp(400, 400, 50, 50);

GLint powerUpPointsX[3];
GLint powerUpPointsY[3];

SDL_Event event;

void RunMainLoop(int val);
void update();

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
		return false;
	}

	powerUpPointsX[0] = 400;
	powerUpPointsX[1] = 400;
	powerUpPointsX[2] = 450;

	powerUpPointsY[0] = 400;
	powerUpPointsY[1] = 450;
	powerUpPointsY[2] = 450;

	return true;
}

static void ProcessEvents()
{
	switch(event.type)
	{
		case SDL_KEYDOWN: 
			switch(event.key.keysym.sym)
			{
				case SDLK_UP:
					player.yVel = 1.0;
					upUp = false;
					break;
				case SDLK_DOWN:
					player.yVel = -1.0;
					downUp = false;
					break;
				case SDLK_LEFT:
					player.xVel = -1.0;
					leftUp = false;
					break;
				case SDLK_RIGHT:
					player.xVel = 1.0;
					rightUp = false;
					break;
				case SDLK_ESCAPE:
					quit = true;
					break;
			}
			break;
		case SDL_KEYUP:
			switch(event.key.keysym.sym)
			{
				case SDLK_UP:
					player.yVel = 0;
					upUp = true;
					break;
				case SDLK_DOWN:
					player.yVel = 0;
					downUp = true;
					break;
				case SDLK_LEFT:
					player.xVel = 0;
					leftUp = true;
					break;
				case SDLK_RIGHT:
					player.xVel = 0;
					rightUp = true;
					break;
			}
			break;
		case SDL_QUIT: 
			quit = true;
			break;
	}
}

void ScreenConstraint(Player *a)
{
	if(a->xPos - a->width < 0)
	{
		a->xPos = 0 + a->width;
	}
	if(a->xPos + a->width > SCREEN_WIDTH)
	{
		a->xPos = SCREEN_WIDTH - a->width;
	}
	if(a->yPos - a->height < 0)
	{
		a->yPos = 0 + a->height;
	}
	if(a->yPos + a->height > SCREEN_HEIGHT)
	{
		a->yPos = SCREEN_HEIGHT - a->height;
	}
}

void Render()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//background.Render();
	powerUp.Render(powerUpPointsX, powerUpPointsY);
	player.Render();

	SDL_GL_SwapBuffers();
}

void update()
{
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	/*if(CollisionDetected(powerUp, randomObject))
	{
		Physics(&powerUp, &randomObject);
	}*/

	ScreenConstraint(&player);

	/*if(!upUp)
	{
		player.yVel -= 0.1;
	}
	if(!downUp)
	{
		player.yVel += 0.1;
	}
	if(!leftUp)
	{
		player.xVel -= 0.1;
	}
	if(!rightUp)
	{
		player.xVel += 0.1;
	}*/

	player.yPos += player.yVel;
	player.xPos += player.xVel;
	
	//background.yPos -= 1.0;
}

int main(int argc, char *args[])
{
	const SDL_VideoInfo *info = NULL;

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
		update();
		Render();

		while(SDL_PollEvent(&event))
		{
			ProcessEvents();
		}
	}

	SDL_Quit();
	
	return 0;
}

void RunMainLoop(int val)
{
	Render();
}