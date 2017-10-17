#include "Map.h"
#include <stdio.h>
//test avec 4 cases 400/0  400/90 400/180
Map::Map()
{
	int position = 0;
	int hauteur = 200;
	cases = new std::vector<Case*>();
	//background
	sf::Vector2i* taillecas0 = new sf::Vector2i(0, 0);
	sf::Vector2i* taillecas1 = new sf::Vector2i(300, 20);
	sf::Vector2i* taillecas2 = new sf::Vector2i(100, 20);
	sf::Vector2i* taillecas3 = new sf::Vector2i(60, 45);
	sf::Vector2i* taillecas4 = new sf::Vector2i(25, 60);
    
	std::string str = "01314141314131413141324";
	
	for (unsigned i = 0; i<str.length(); ++i)
	{
		Case* cas;
		switch (str.at(i))
		{
		case '0':
			cas = new Case(0, new sf::Vector2i(position, 0), taillecas0);
			position += taillecas0->x;
			break;
		case '1':
			cas = new Case(1, new sf::Vector2i(position, hauteur - taillecas1->y), taillecas1);
			position += taillecas1->x;
			break;
		case '2':
			cas = new Case(1, new sf::Vector2i(position, hauteur - taillecas2->y), taillecas2);
			position += taillecas2->x;
			break;
		case '3':
			cas = new Case(3, new sf::Vector2i(position, hauteur - taillecas3->y), taillecas3);
			position += taillecas3->x;
			break; 
		case '4':
			cas = new Case(4, new sf::Vector2i(position, hauteur - taillecas4->y), taillecas4);
			position += taillecas4->x;
			break;
		default:
			break;
		}
		cases->push_back(cas);
	}
	
	/**
	
	
	
	
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
	*/
}


Map::~Map()
{
}
