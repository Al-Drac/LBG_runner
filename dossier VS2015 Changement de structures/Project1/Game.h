#pragma once
#ifndef _GAME_H_
#define _GAME_H_
#include <list>
#include <SFML/Graphics.hpp>
#include "Joueur.h"
#include "Moteur.h"
#include "Loader.h"
#include "myClock.h"
#include "AbstractEntity.h"
#include "Observer.h"
#include "InputManager.h"


class Game
{
private:
	 Moteur* moteur;
	 Screen& screen;
	 sf::Clock* Clock;
	 bool jeufini; 
	 bool* partiefini;
	 std::vector<AbstractEntity*> entities;
public:
	~Game();
	Game(Screen& screen, Loader& load);
	sf::RenderWindow& getWindow();
	void start();
	void update();
	void draw();

};


#endif _GAME_H_