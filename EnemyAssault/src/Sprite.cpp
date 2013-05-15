#include "Sprite.h"


Sprite::Sprite(void)
{
	xPos = 0;
	yPos = 0;
	xVel = 0;
	yVel = 0;
	xAccel = 0;
	yAccel = 0;
}

Sprite::~Sprite(void)
{
}

Sprite::Sprite(GLint xPos, GLint yPos, GLint xVel, GLint yVel, GLint xAccel, GLint yAccel)
{
	this->xPos = xPos;
	this->xPos = yPos;
	this->xVel = xVel;
	this->yVel = yVel;
	this->xAccel = xAccel;
	this->yAccel = yAccel;
}

void Sprite::SetPosition(GLint xPos, GLint yPos)
{
	this->xPos = xPos;
	this->yPos = yPos;
}

void Sprite::SetVel(std::string axis, GLint vel)
{
	if(axis == "x" || axis == "X")
	{
		this->xVel = vel;
	}
	else if(axis == "y" || axis == "Y")
	{
		this->yVel = vel;
	}
}

void Sprite::SetAccel(std::string axis, GLint accel)
{
	if(axis == "x" || axis == "X")
	{
		this->xAccel = accel;
	}
	else if(axis == "y" || axis == "Y")
	{
		this->yAccel = accel;
	}
}

void Sprite::Render()
{
	
}