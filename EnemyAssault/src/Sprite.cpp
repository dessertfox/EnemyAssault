#include "Sprite.h"


Sprite::Sprite(void)
{
	x = 0;
	y = 0;
	xVel = 0;
	yVel = 0;
	xAccel = 0;
	yAccel = 0;
}

Sprite::~Sprite(void)
{
}

Sprite::Sprite(GLint x, GLint y, GLint xVel, GLint yVel, GLint xAccel, GLint yAccel)
{
	this->x = x;
	this->x = y;
	this->xVel = xVel;
	this->yVel = yVel;
	this->xAccel = xAccel;
	this->yAccel = yAccel;
}

void Sprite::SetPosition(GLint x, GLint y)
{
	this->x = x;
	this->y = y;
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