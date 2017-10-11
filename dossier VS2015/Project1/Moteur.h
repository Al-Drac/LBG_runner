#ifndef _MOTEUR_H_
#define _MOTEUR_H_
#include "Observer.h"
#include "Case.h"
#include "Map.h"
#include <iostream>
#define HAUTEUR_PERSO 49
#define LARGEUR_PERSO 40
#include <math.h>
class Moteur
{
	Joueur* joueur;
	Map* map;
	sf::Vector2f* gravite;
public:
	Moteur(Joueur*, Map*);
	~Moteur();
	int compareMapAJoueur(sf::Vector2f joueurPos, std::vector<Case*>* cases);
	int compareMapAJoueur(Hitbox* joueurPos, std::vector<Case*>* cases);
	bool compare2a2(sf::Vector2f, sf::Vector2f);
	bool compare2a2(sf::IntRect*, sf::IntRect*);
	void update();
	void draw();

};

#endif