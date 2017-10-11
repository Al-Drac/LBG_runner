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
	sf::RenderWindow windows(sf::VideoMode(1800, 900), "SFML works!");
	std::list<std::string> images;
	images.push_back("avance2.png");
	images.push_back("avance2.png");
	images.push_back("crouch.png");
	images.push_back("dinoDeath.png");
	Loader load(images);
	Screen screen(windows);
	Game game(screen, load);
	myClock* Clock = myClock::getInstance();
	sf::Event event;
	bool jeufini;
	bool needscore;
	needscore = false;
	jeufini = false;

	while (windows.isOpen() && !jeufini)
	{
		while(windows.pollEvent(event))
		{
			switch (event.type)
			{
				// fenêtre fermée
			case sf::Event::Closed:
				windows.close();
				break;
				// touche pressée
			case sf::Event::KeyPressed:
				switch (event.key.code)
				{
				case sf::Keyboard::Escape:
					windows.close();
					break;
				case sf::Keyboard::Space :
					game.getJoueur()->setidMove(1);
						break;
				case sf::Keyboard::S:
					game.getJoueur()->setidMove(2);
					break;
				default:
					break;
				}
				break;
			default:
					break;
			}
		}
		if (Clock->getClock()->getElapsedTime().asMilliseconds() > 40.0f)
		{
			game.update();
			game.draw();
			Clock->getClock()->restart();
		}
	}
	return 0;
} 