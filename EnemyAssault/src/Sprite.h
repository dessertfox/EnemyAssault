#pragma once

#include <GL\freeglut.h>
#include <gl\GL.h>
#include <gl\GLU.h>
#include <string>

class Sprite
{
public:
	Sprite(void);
	~Sprite(void);

	Sprite(GLint xPos, GLint yPos, GLint xVel, GLint yVel, GLint xAccel, GLint yAccel);
	void SetPosition(GLint xPos, GLint yPos);
	void SetVel(std::string axis, GLint vel);
	void SetAccel(std::string axis, GLint accel);
	virtual void Render();

	GLint xPos, yPos, xVel, yVel, xAccel, yAccel, width, height;
};

