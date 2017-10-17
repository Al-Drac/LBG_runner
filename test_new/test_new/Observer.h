#pragma once
#ifndef OBS_H
#define OBS_H

#include <iostream>
#include <list>
#include <SFML/Graphics.hpp>
#include "myClock.h"
#include "Screen.h"
#include "Hitbox.h"

#define HAUTEUR_PERSO 49
#define LARGEUR_PERSO 40
typedef int Info;


class Observable;

class Observateur
{
protected:
	std::list<Observable*> m_list;
	typedef std::list<Observable*>::iterator iterator;
	typedef std::list<Observable*>::const_iterator const_iterator;
	virtual ~Observateur() = 0;
public:
	virtual void Update(const Observable* observable) const;

	void AddObs(Observable* obs);
	void DelObs(Observable* obs);
};

class Observable
{
	std::list<Observateur*> m_list;

	typedef std::list<Observateur*>::iterator iterator;
	typedef std::list<Observateur*>::const_iterator const_iterator;

public:
	void AddObs(Observateur* obs);
	void DelObs(Observateur* obs);

	virtual Info Statut(void) const = 0;
	virtual ~Observable();
protected:
	void Notify(void);

};

class Movement
{
	int* MovementId;
	std::vector<sf::Sprite*>* movements;
	std::vector<sf::Texture*>* textures;
	int* place;
public:
	sf::Sprite* getNextSprite();
	void resetMovements();
	int getId();
	Movement(int, std::vector<sf::Sprite*>*, std::vector<sf::Texture*>*);
	~Movement();
};
class Joueur : public Observable
{
	 int score;
	 sf::Time* tempsMilli;
	 int* idMove;
	 sf::Vector2i* position;
	 sf::Vector2i* taille;
	 sf::Vector2f* vitesse;
	 sf::Sprite* sprite;
	 std::vector<Movement>* movements;
	 sf::Vector2f* saut;
	 sf::Vector2f* deplacement;
public:
	 //static Joueur* getInstance(std::list<Movement> moves);
	 void update();
	 void draw();
	 void SpriteAdvance();
	 Hitbox* hitbox;
	 Hitbox* getHitbox();
	 Screen& screen;
	 int* plateform;
	 void Change(int valeur);
	 sf::Vector2f getVitesse();
	 sf::Vector2i getposition();
	 sf::Time getTemps();
	 int getScore();
	 void setVitesse(sf::Vector2f);
	 void setPosition(sf::Vector2i);
	 void setidMove(int move);
	 int getIdMove();
	 sf::Vector2f getSaut();
	 void addTemps(sf::Time);
	 void addScore(int);
	 sf::Sprite* getSprite();
	 int Statut(void) const;
	 Joueur(std::vector<Movement>* moves, Screen scre);
	 ~Joueur();
private :
};


class MeteoFrance : public Observateur
{

};

#endif
