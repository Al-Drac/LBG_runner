#ifndef _INPUTMANAGER_H_
#define _INPUTMANAGER_H_
#include "Screen.h"

class InputManager
{
public:
	static InputManager* getInstance(Screen screeen);
	int* getInputValue();
	void getInput();
private:
	int* input;
	Screen screen;
	sf::Event event;
	InputManager(Screen screeen);
	~InputManager();
	static InputManager* instance;
};

#endif //_INPUTMANAGER_H_