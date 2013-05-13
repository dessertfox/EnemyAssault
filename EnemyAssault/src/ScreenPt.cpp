#include "ScreenPt.h"

ScreenPt::ScreenPt(void)
{
	x = y = 0;
}

ScreenPt::~ScreenPt(void)
{
}

void ScreenPt::SetPixel(int x, int y)
{
	glVertex2i(x, y);
}

void ScreenPt::setCoords(GLint xCoordValue, GLint yCoordValue)
{
	x = xCoordValue;
	y = yCoordValue;
}

const GLint ScreenPt::getx()
{
	return x;
}

const GLint ScreenPt::gety()
{
	return y;
}

void ScreenPt::incrementx()
{
	x++;
}

void ScreenPt::decrementy()
{
	y--;
}

void CircleMidpoint(int xc, int yc, int radius)
{
	ScreenPt circPt;

	GLint p = 1 - radius;
	circPt.setCoords(0, radius);
	void circlePlotPoints(GLint, GLint, ScreenPt);
	circlePlotPoints(xc, yc, circPt);

	while(circPt.getx() < circPt.gety())
	{
		circPt.incrementx();
		if(p < 0)
		{
			p += 2 * circPt.getx() + 1;
		}
		else
		{
			circPt.decrementy();
			p += 2 * (circPt.getx() - circPt.gety()) + 1;
		}
		circlePlotPoints(xc, yc, circPt);
	}
}

void circlePlotPoints(GLint xc, GLint yc, ScreenPt circPt)
{
	glVertex2i(xc + circPt.getx(), yc + circPt.gety());
	glVertex2i(xc - circPt.getx(), yc + circPt.gety());
	glVertex2i(xc + circPt.getx(), yc - circPt.gety());
	glVertex2i(xc - circPt.getx(), yc - circPt.gety());
	glVertex2i(xc + circPt.gety(), yc + circPt.getx());
	glVertex2i(xc - circPt.gety(), yc + circPt.getx());
	glVertex2i(xc + circPt.gety(), yc - circPt.getx());
	glVertex2i(xc - circPt.gety(), yc - circPt.getx());
}