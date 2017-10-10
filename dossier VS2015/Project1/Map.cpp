#include "Map.h"
//test avec 4 cases 400/0  400/90 400/180
Map::Map()
{
	cases = new std::vector<Case*>();
	//background
	Case* cas1 = new Case(0, new sf::Vector2i(0, 0), new sf::Vector2i(0, 0));
	//bumps
	//Case* cas3 = new Case(2, sf::Vector2f(300.0f, 325.0f));
	//cactus
	Case* cas4  = new Case(1, new sf::Vector2i(0,    200), new sf::Vector2i(300, 10));
	Case* cas5  = new Case(1, new sf::Vector2i(300,  200), new sf::Vector2i(300, 10));
	Case* cas6  = new Case(1, new sf::Vector2i(600,  200), new sf::Vector2i(300, 10));
	Case* cas7  = new Case(1, new sf::Vector2i(900,  200), new sf::Vector2i(300, 10));
	Case* cas8  = new Case(1, new sf::Vector2i(1200, 200), new sf::Vector2i(300, 10));
	Case* cas9  = new Case(1, new sf::Vector2i(1500, 200), new sf::Vector2i(300, 10));
	Case* cas10 = new Case(1, new sf::Vector2i(1800, 200), new sf::Vector2i(300, 10));
	Case* cas11 = new Case(3, new sf::Vector2i(1500, 200), new sf::Vector2i(300, 10));

	cases->push_back(cas1);
	//cases->push_back(cas3);
	cases->push_back(cas4);
	cases->push_back(cas5);
	cases->push_back(cas6);
	cases->push_back(cas7);
	cases->push_back(cas8);
	cases->push_back(cas9);
	cases->push_back(cas10);
	cases->push_back(cas11);
}


Map::~Map()
{
}
