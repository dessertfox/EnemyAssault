#pragma once

#include "macros.h"
#include "SceneGraph.h"

class ModelFactory
{
public:
	~ModelFactory(void);
	
	static ModelFactory* GetInstance();
	void CreatePlayer(Vector2f position);
	GameObject* CreateSquareEnemy(Vector2f position);
	GameObject* CreateTriangleEnemy(Vector2f position);
	GameObject* CreateCircleEnemy(Vector2f position);
private:
	ModelFactory(void);
};

