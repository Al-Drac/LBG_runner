#ifndef _MOTEUR_H_
#define _MOTEUR_H_
#include "Observer.h"
#include "Case.h"
#include "Map.h"
#include <iostream>
#define TAILLE_JOUEUR 300
#include <math.h>
class Moteur
{
	Joueur* joueur;
	Map* map;
	sf::Vector2f* gravite;
public:
	Moteur(Joueur*, Map*);
	~Moteur();
	bool compareMapAJoueur(sf::Vector2f joueurPos, std::vector<Case*>* cases);
	bool compare2a2(sf::Vector2f, sf::Vector2f);
	void update();
	void draw();

};

#endif