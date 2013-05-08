#include "Point2D.h"


Point2D::Point2D(void)
{
	koord[0] = 0;
	koord[1] = 0;
	koord[2] = 1;
}


Point2D::~Point2D(void)
{
}

Point2D::Point2D(int x, int y)
{
	koord[0] = x;
	koord[1] = y;
	koord[2] = 1;
}