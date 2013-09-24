#pragma once

#include "macros.h"
#include "SceneGraph.h"
#include "ModelFactory.h"

class GameObject
{
public:
	GameObject(void);
	~GameObject(void);

	GameObject(Vector2f position);
	virtual void Render();
	virtual void Update();
	virtual void Transform();
	Vector2f PointToScala(Vector2f point);
	float ScalaToPoint(float scala);
	virtual bool CheckCollision();

	Vector2f position;
	enum enemyType { square, circle, triangle };
	enemyType thisType;
	GameObject* colliderObject;
	float radius;
};

