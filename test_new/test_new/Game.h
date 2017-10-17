#pragma once
#ifndef _GAME_H_
#define _GAME_H_
#include <list>
#include <SFML/Graphics.hpp>
#include "Observer.h"
#include "Moteur.h"
#include "Loader.h"
#include "ResourcePath.hpp"
#include <string>
#include <sstream>
#include <iostream>



class Game
{
private:
	 Joueur* joueur;
	 Moteur* moteur;
	 Map* map;
	 Screen& screen;

public:
	~Game();
	Game(Screen& screen, Loader& load);
	Joueur* getJoueur();
	sf::RenderWindow& getWindow();
	void update();
	void draw();

};


#endif _GAME_H_
