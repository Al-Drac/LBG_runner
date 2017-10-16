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
	sf::Vector2i* taillecas3 = new sf::Vector2i(60, 49);
	sf::Vector2i* taillecas4 = new sf::Vector2i(25, 61);
	std::string str = "0131414131413141314132411112111131113111311121111131111211113111121111211112111112111211121";
	
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
}

void Map::update()
{
	for (std::vector<Case*>::iterator it = cases->begin(); it != cases->end(); it++)
	{
        (*it)->decale(TAILLE_ECRAN);
	}
}
Map::~Map()
{
}
