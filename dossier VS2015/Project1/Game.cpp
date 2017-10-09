#include "Game.h"


Game::~Game()
{

}

Game::Game(Screen& screenn, Loader& load) : screen(screenn), joueur(new Joueur(load.getMoves(), screenn))
{
	if (joueur != NULL)
	{
		map = new Map();
		moteur = new Moteur(joueur, map);
	}
}

void Game::update()
{
	screen.draw();
	moteur->update();
	joueur->update();
	//map->update();
}
void Game::draw()
{
	for each (Case* casess in *map->cases)
		screen.add(casess->getSprite());
	screen.add(joueur->getSprite());
	screen.update();

}
sf::RenderWindow& Game::getWindow()
{
	return screen.getWindow();
}

Joueur* Game::getJoueur()
{
	return joueur;
}

