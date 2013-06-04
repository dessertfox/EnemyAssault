#pragma once
#include <SDL.h>
#include <SDL_opengl.h>

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

