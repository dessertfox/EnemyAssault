#pragma once
#include "sprite.h"

class Player : public Sprite
{
public:
	Player(void);
	~Player(void);

	Player(GLint xPos, GLint yPos, GLint width, GLint height);
	void Render();
	void Controller(SDL_keysym *keysym);
};

