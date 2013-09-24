#include "GameObject.h"

GameObject::GameObject(void)
{

}

GameObject::GameObject(Vector2f position)
{
	this->position.x = position.x;
	this->position.y = position.y;
	this->radius = 0;

	SceneGraph::GetInstance()->AddItem(this);
}

GameObject::~GameObject(void)
{
	SceneGraph::GetInstance()->RemoveItem(this);
}

void GameObject::Render()
{
	glPushMatrix();

	glTranslatef(position.x, position.y, 0);

	//glRotatef(position.y, 0, 0, 1);

	glColor3f(0, 1, 0);

	glBegin(GL_LINE_LOOP);

	switch(this->thisType)
	{
	case (GameObject::enemyType::square):

		radius = 25;
		glVertex2f(-25, -25);
		glVertex2f(25, -25);
		glVertex2f(25, 25);
		glVertex2f(-25, 25);

		break;
	case (GameObject::enemyType::triangle):

		radius = 25;
		glVertex2f(-25, -25);
		glVertex2f(25, -25);
		glVertex2f(0, 25);

		break;
	case (GameObject::enemyType::circle):

		radius = 25;
		for (int i=0; i <= 360; i++)
		{
			float angle = i * DEG2RAD;
			glVertex2f(cos(angle) * 50, sin(angle) * 50);
		}
	}
	glEnd();

	glPopMatrix();
}

void GameObject::Update()
{
	CheckCollision();
	position.y++;
}

void GameObject::Transform()
{
	
}

Vector2f GameObject::PointToScala(Vector2f point)
{
	Vector2f scala;
	scala.x = (point.x / 400) * 100 - 100;
	scala.y = (point.y / 300) * 100 - 100;
	return scala;
}

float GameObject::ScalaToPoint(float scala)
{

	int perspectiveMoveRatio = 1.2;
	return scala * perspectiveMoveRatio;
}

bool GameObject::CheckCollision()
{
	FOREACH(it, SceneGraph::GetInstance()->gameObjectList)
	{
		if((*it) != this)
		{
			if(DistanceBetween(position, (*it)->position) < radius + (*it)->radius)
			{
				colliderObject = (*it);
				return true;
			}
			//else
			//{
			//	colliderObject = NULL;
			//	return false;
			//}
		}
		else
		{
			//return false;
		}
	}

	return false;
}