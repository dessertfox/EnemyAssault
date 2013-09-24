#pragma once

#include "macros.h"

class GameObject;

class SceneGraph
{
public:
	~SceneGraph(void);

	static SceneGraph* GetInstance();
	void Render();
	void Update();
	void AddItem(GameObject* object);
	void RemoveItem(GameObject* object);

	std::vector<GameObject*>tempList; 
	std::vector<GameObject*> gameObjectList;
private:
	SceneGraph(void);
};

