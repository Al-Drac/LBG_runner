#ifndef _MOTEUR_H_
#define _MOTEUR_H_
#include "Joueur.h"
#include "Case.h"
#include "Screen.h"
#include "Map.h"
#include <iostream>
#define HAUTEUR_PERSO 49
#define LARGEUR_PERSO 40
#include <math.h>
#include "InputManager.h"
class Moteur : Observateur
{
	Joueur* joueur;
	Map* map;
	sf::Vector2f* gravite;
	int state;
	bool* partiefini;
	Screen screen;
public:
	Moteur(Joueur*, Map*, Screen screeen, bool* partie_fini);
	~Moteur();
	void Notified(Observable* obs);
	int compareMapAJoueur(Hitbox* joueurPos, std::vector<Case*>* cases);
	bool compare2a2(sf::IntRect*, sf::IntRect*);
	void update();
	void draw();

};

#endif