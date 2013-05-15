#include "Object.h"


Object::Object(void)
{
}


Object::~Object(void)
{
}

Object::Object(GLint xPos, GLint yPos, GLint width, GLint height)
{
	this->xPos = xPos;
	this->yPos = yPos;
	this->width = width;
	this->height = height;
}

void Object::Render()
{
	GLint offset = 10;
	glColor3f(0.0f, 0.0f, 1.0f);

	for(int i = 0; i < 60; i++)
	{
		for(int j = 0; j < 80; j++)
		{
			glBegin(GL_LINE_LOOP);
				glVertex2i(xPos + (width) + (offset * i), yPos + (height) + (offset * j));
				glVertex2i(xPos + (width) + (offset * i), yPos - (height) + (offset * j));
				glVertex2i(xPos - (width) + (offset * i), yPos - (height) + (offset * j));
				glVertex2i(xPos - (width) + (offset * i), yPos + (height) + (offset * j));
			glEnd();
		}
	}
}