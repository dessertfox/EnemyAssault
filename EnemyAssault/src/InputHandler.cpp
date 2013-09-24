#include "InputHandler.h"

static InputHandler* instance = NULL;

InputHandler::InputHandler(void)
{
	InputHandler::state.insert(std::make_pair<int, bool>('w', false));
	InputHandler::state.insert(std::make_pair<int, bool>('s', false));
	InputHandler::state.insert(std::make_pair<int, bool>('a', false));
	InputHandler::state.insert(std::make_pair<int, bool>('d', false));
	InputHandler::state.insert(std::make_pair<int, bool>(32, false));
	InputHandler::state.insert(std::make_pair<int, bool>(100, false));
	InputHandler::state.insert(std::make_pair<int, bool>(101, false));
	InputHandler::state.insert(std::make_pair<int, bool>(103, false));
	InputHandler::state.insert(std::make_pair<int, bool>(102, false));
}


InputHandler::~InputHandler(void)
{
}

InputHandler* InputHandler::GetInstance()
{
	if(instance == NULL)
	{
		return instance = new InputHandler();
	}
	else
	{
		return instance;
	}	
}

void InputHandler::HandleKeyPress(unsigned char key, int x, int y) 
{
	if(InputHandler::player)
	{
		InputHandler::state.at(key) = true;
	}
}

void InputHandler::HandleKeyPressUp(unsigned char key, int x, int y)
{
	InputHandler::state.at(key) = false;
}

void InputHandler::HandleSpecialKeyPress(int key, int x, int y) 
{
	if(InputHandler::player)
	{
		InputHandler::state.at(key) = true;
	}
}

void InputHandler::HandleSpecialKeyPressUp(int key, int x, int y)
{
	InputHandler::state.at(key) = false;
}
