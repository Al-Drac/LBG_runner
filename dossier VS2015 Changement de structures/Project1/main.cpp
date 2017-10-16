#include <SFML/Graphics.hpp>
#include "Observer.h"
#include "Case.h"
#include "Moteur.h"
#include "Game.h"
#include "Loader.h"
#include <list>
#include "myClock.h"
#include "main.h"
int main()
{
	sf::RenderWindow windows(sf::VideoMode(1800, 900), "Little Big Raptor !");
	std::list<std::string> images;
	images.push_back("avance.png");
	images.push_back("avance2.png");
	images.push_back("crouch.png");
	images.push_back("dinoDeath.png");
	Loader load(images);
	Screen screen(windows);
	Game game(screen, load);
	game.start();
	return 0;
} 