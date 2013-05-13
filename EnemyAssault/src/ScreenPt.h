#pragma once
#include <GL\freeglut.h>
#include <GL\GL.h>
#include <GL\GLU.h>

class ScreenPt
{
private:
	GLint x, y;

public:
	ScreenPt(void);
	~ScreenPt(void);

	void SetPixel(int x, int y);
	void setCoords(GLint xCoordValue, GLint yCoordValue);
	const GLint getx();
	const GLint gety();
	void incrementx();
	void decrementy();

	void CircleMidpoint(int xc, int yc, int radius);
	void circlePlotPoints(GLint xc, GLint yc, ScreenPt circPt);
};

