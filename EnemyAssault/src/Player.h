#pragma once
#include "sprite.h"

class Player : public Sprite
{
public:
	Player(void);
	~Player(void);

	void Render();
};

