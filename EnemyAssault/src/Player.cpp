#include "Player.h"
#include "InputHandler.h"

Player::Player(void) : GameObject()
{
}

Player::~Player(void)
{
}

Player::Player(Vector2f position) : GameObject()
{
	this->position.x = position.x;
	this->position.y = position.y;
	this->translate = Vector2f(0, 0);

	SceneGraph::GetInstance()->AddItem(this);
	InputHandler::GetInstance()->player = this;
}

void Player::Render()
{
	glPushMatrix();

	glTranslatef(position.x, position.y, 0);

	glColor3f(0, 0, 1);

	glBegin(GL_LINE_LOOP);

	radius = 25;
	glVertex2f(-25, -25);
	glVertex2f(25, -25);
	glVertex2f(25, 25);
	glVertex2f(-25, 25);

	glEnd();

	glPopMatrix();
}

bool Player::singleBool (GameObject* value)
{
	//return (typeid(value) == typeid(Player));
	return (value == this);
}

void Player::Update()
{
	Transform();
	Shoot();

	if(CheckCollision())
	{
		if(colliderObject->thisType == GameObject::enemyType::circle)
		{
			SceneGraph::GetInstance()->RemoveItem(this);
		}
	}
}

void Player::Transform()
{
	if(InputHandler::GetInstance()->state['w'] || InputHandler::GetInstance()->state[101])
	{
		position.y += 10;
	}
	else if(InputHandler::GetInstance()->state['s'] || InputHandler::GetInstance()->state[103])
	{
		position.y -= 10;
	}
	else if(InputHandler::GetInstance()->state['a'] || InputHandler::GetInstance()->state[100])
	{
		position.x -= 10;
	}
	else if(InputHandler::GetInstance()->state['d'] || InputHandler::GetInstance()->state[102])
	{
		position.x += 10;
	}
}

void Player::Shoot()
{
	if(InputHandler::GetInstance()->state[32])
	{
		ModelFactory::GetInstance()->CreateTriangleEnemy(Vector2f(position.x, position.y));
	}
}