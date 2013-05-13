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

	Sprite(GLint x, GLint y, GLint xVel, GLint yVel, GLint xAccel, GLint yAccel);
	void SetPosition(GLint x, GLint y);
	void SetVel(std::string axis, GLint vel);
	void SetAccel(std::string axis, GLint accel);
	virtual void Render();

private:
	GLint x, y, xVel, yVel, xAccel, yAccel;
};

