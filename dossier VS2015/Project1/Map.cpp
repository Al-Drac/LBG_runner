#include "Map.h"
//test avec 4 cases 400/0  400/90 400/180
Map::Map()
{
	cases = new std::vector<Case*>();
	//background
	Case* cas1 = new Case(0, sf::Vector2f(0.0f, 0.0f));
	//bumps
	Case* cas3 = new Case(2, sf::Vector2f(300.0f, 325.0f));
	//cactus
	Case* cas4 = new Case(1, sf::Vector2f(0.0f, 200.0f));
	Case* cas5 = new Case(1, sf::Vector2f(300.0f,200.0f));
	Case* cas6 = new Case(1, sf::Vector2f(600.0f, 200.0f));
	Case* cas7 = new Case(1, sf::Vector2f(900.0f, 200.0f));
	Case* cas8 = new Case(1, sf::Vector2f(1200.0f, 200.0f));
	Case* cas9 = new Case(1, sf::Vector2f(1500.0f, 200.0f));
	Case* cas10 = new Case(1, sf::Vector2f(1800.0f, 200.0f));
	cases->push_back(cas1);
	cases->push_back(cas3);
	cases->push_back(cas4);
	cases->push_back(cas5);
	cases->push_back(cas6);
	cases->push_back(cas7);
	cases->push_back(cas8);
	cases->push_back(cas9);
	cases->push_back(cas10);
}


Map::~Map()
{
}
