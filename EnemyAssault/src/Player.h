#pragma once

#include "macros.h"
#include "GameObject.h"
#include <typeinfo>

class Player : public GameObject
{
public:
	Player(void);
	~Player(void);

	Player(Vector2f position);

	void Render();
	bool singleBool (GameObject* value);
	void Update();
	void Transform();
	void Shoot();

	Vector2f translate;
};

