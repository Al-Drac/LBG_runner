#include "Game.h"


Game::~Game()
{
}

Game::Game(Screen& screenn, Loader& load) : screen(screenn)
{
	Map* map = new Map(screen);
	Joueur* joueur = new Joueur(load.getMoves(), screen);
	partiefini = new bool(false);
	moteur = new Moteur(joueur, map, screen, partiefini);
	entities = std::vector<AbstractEntity*>();
	entities.push_back((AbstractEntity*)map);
	entities.push_back((AbstractEntity*)joueur);
	jeufini = false;
	Clock = MyClock::getInstance()->getClock();
}

void Game::start()
{
	Clock->restart();
	while (!jeufini)
	{
		InputManager::getInstance(screen)->getInput();
		while (!(*partiefini))
		{
			InputManager::getInstance(screen)->getInput();
			if (Clock->getElapsedTime().asMilliseconds() > 40.0f)
			{
				update();
				draw();
				Clock->restart();
			}
		}
		if (*InputManager::getInstance(screen)->getInputValue() == -1)
		{
			jeufini = true;
			*partiefini = true;
		}
		else if (*InputManager::getInstance(screen)->getInputValue() == 1)
 			*partiefini = false;
	}
}

void Game::update()
{
	screen.draw();
	moteur->update();
	for (std::vector<AbstractEntity*>::iterator it = entities.begin(); it != entities.end(); it++)
	{
		(*it)->Update();
	}
}
// a modifier, je ne sais pasencore où on dessinera sur l'écran sur l'écran les deux son possible on modifiera au moins le fait d'utiliser les liste
void Game::draw()
{
	for (std::vector<AbstractEntity*>::iterator it = entities.begin(); it != entities.end(); it++)
	{
		(*it)->Draw();
	}
	screen.update();
}

sf::RenderWindow& Game::getWindow()
{
	return screen.getWindow();
}


