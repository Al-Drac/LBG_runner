#include "InputManager.h"

InputManager* InputManager::getInstance(Screen screeen) 
{
	if (instance == NULL)
		instance = new InputManager(screeen);
	return instance;
}

InputManager* InputManager::instance = NULL;

InputManager::InputManager(Screen screeen) : screen(screeen)
{
	input  = new int(0);
}
InputManager::~InputManager()
{

}

int* InputManager::getInputValue()
{
	return input;
}

void InputManager::getInput()
{
	while (screen.getWindow().pollEvent(event))
	{
		switch (event.type)
		{
			// fenêtre fermée
		case sf::Event::Closed:
			screen.getWindow().close();
			delete input;
			input = new int(-1);
			break;
			// touche pressée
		case sf::Event::KeyPressed:
			switch (event.key.code)
			{
			case sf::Keyboard::Escape:
				delete input;
				input = new int(-1);
				screen.getWindow().close();
				break;
			case sf::Keyboard::Space:
				delete input;
				input = new int(1);
				break;
			case sf::Keyboard::S:
				delete input;
				input = new int(2);
				break;
			default:
				break;
			}
		break;
		default:
			break;
		}
	}
}