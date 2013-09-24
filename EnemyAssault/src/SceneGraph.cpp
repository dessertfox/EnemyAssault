#include "SceneGraph.h"
#include "GameObject.h"

static SceneGraph* instance = NULL;

SceneGraph::SceneGraph(void)
{
	gameObjectList = std::vector<GameObject*>();
}

SceneGraph::~SceneGraph(void)
{
}

SceneGraph* SceneGraph::GetInstance()
{
	if(instance == NULL)
	{
		return instance = new SceneGraph();
	}
	else
	{
		return instance;
	}
}

void SceneGraph::Render()
{
	if(!tempList.empty())
	{
		FOREACH(it, gameObjectList)
		{
			(*it)->Render();
		}
		gameObjectList = tempList;
	}
}

void SceneGraph::Update()
{
	if(!tempList.empty())
	{
		FOREACH(it, gameObjectList)
		{
			if(*it)
			{
				(*it)->Update();
			}
		}
		gameObjectList = tempList;
	}
}

void SceneGraph::AddItem(GameObject* object)
{
	tempList.push_back(object);
}
	
void SceneGraph::RemoveItem(GameObject* object)
{
	std::vector<GameObject*>::iterator it = std::find(tempList.begin(), tempList.end(), object);
	tempList.erase(it);
}