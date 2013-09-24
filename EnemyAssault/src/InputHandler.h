#pragma once

#include "macros.h"
#include "Player.h"

class InputHandler
{
public:
	~InputHandler(void);

	static InputHandler* GetInstance();
	void HandleKeyPress(unsigned char key, int x, int y);
	void HandleKeyPressUp(unsigned char key, int x, int y);
	void HandleSpecialKeyPress(int key, int x, int y);
	void HandleSpecialKeyPressUp(int key, int x, int y);
	
	Player* player;
	std::map<int, bool> state;
private:
	InputHandler(void);
};

