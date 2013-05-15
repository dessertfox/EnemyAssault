#include "Player.h"


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

void handleKeys(unsigned char key, int x, int y )
{
	if(key == GLUT_KEY_UP)
	{
		glTranslatef(0.0f, 1.0f, 0.0f);
	}
	else if(key == GLUT_KEY_DOWN)
	{
		glTranslatef(0.0f, -1.0f, 0.0f);
	}
	else if(key == GLUT_KEY_LEFT)
	{
		glTranslatef(-1.0f, 0.0f, 0.0f);
	}
	else if(key == GLUT_KEY_RIGHT)
	{
		glTranslatef(1.0f, 0.0f, 0.0f);
	}
}