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
	GLint offset = 30;
	glColor3f(0.0f, 0.0f, 1.0f);

	for(int i = 0; i < 27; i++)
	{
		for(int j = 0; j < 20; j++)
		{
			//Vertical Lines
			glBegin(GL_LINES);
				glVertex2i(xPos + (offset * i), yPos + (offset * j));
				glVertex2i(xPos + 800, yPos + (offset * j));
				//glVertex2i(800 + (offset * i), yPos + (offset * j));
			glEnd();

			//Horizontal Lines
			glBegin(GL_LINES);
				glVertex2i(xPos + (offset * i), yPos + (offset * j));
				glVertex2i(xPos + (offset * i), yPos + 600);
				//glVertex2i(xPos + (offset * i), 600 + (offset * j));
			glEnd();
		}
	}
}