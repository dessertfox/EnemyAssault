#include "ModelFactory.h"
#include "Player.h"

static ModelFactory* instance = NULL;

ModelFactory::ModelFactory(void)
{
}

ModelFactory::~ModelFactory(void)
{
}

ModelFactory* ModelFactory::GetInstance()
{
	if(instance == NULL)
	{
		return instance = new ModelFactory();
	}
	else
	{
		return instance;
	}
}

void ModelFactory::CreatePlayer(Vector2f position)
{
	new Player(position);
}

GameObject* ModelFactory::CreateSquareEnemy(Vector2f position)
{
	GameObject* temp = new GameObject(position);
	temp->thisType = GameObject::enemyType::square;
	return temp;
}

GameObject* ModelFactory::CreateTriangleEnemy(Vector2f position)
{
	
	GameObject* temp = new GameObject(position);
	temp->thisType = GameObject::enemyType::triangle;
	return temp;
}

GameObject* ModelFactory::CreateCircleEnemy(Vector2f position)
{
	GameObject* temp = new GameObject(position);
	temp->thisType = GameObject::enemyType::circle;
	return temp;
}