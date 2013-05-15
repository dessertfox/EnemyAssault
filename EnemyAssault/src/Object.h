#pragma once
#include "sprite.h"
class Object : public Sprite
{
public:
	Object(void);
	~Object(void);

	Object(GLint xPos, GLint yPos, GLint width, GLint height);
	void Render();
};

