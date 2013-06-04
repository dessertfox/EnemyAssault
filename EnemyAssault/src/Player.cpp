#include "Player.h"

int SCREEN_WIDTH = 800;
int SCREEN_HEIGHT = 600;

Player::Player(void)
{
}


Player::~Player(void)
{
}

Player::Player(GLint xPos, GLint yPos, GLint width, GLint height)
{
	this->xPos = xPos;
	this->yPos = yPos;
	this->width = width;
	this->height = height;
}

void Player::Render()
{
	glColor3f(1.0f, 0.0f, 0.0f);

	glBegin(GL_LINE_LOOP);
		glVertex2i(xPos + (width / 2), yPos + (height / 2));
		glVertex2i(xPos + (width / 2), yPos - (height / 2));
		glVertex2i(xPos - (width / 2), yPos - (height / 2));
		glVertex2i(xPos - (width / 2), yPos + (height / 2));
	glEnd();
}

void Player::Controller(SDL_keysym *keysym)
{
	switch(keysym->sym)
	{
		case SDLK_UP: Player::yPos += 10;
		break;
		case SDLK_DOWN: Player::yPos -= 10;
		break;
		case SDLK_LEFT: Player::xPos -= 10;
		break;
		case SDLK_RIGHT: Player::xPos += 10;
		break;
	}
}