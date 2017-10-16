#ifndef  _JOUEUR_H_
#define _JOUEUR_H_

#include <vector>
#include <SFML/Graphics.hpp>
#include "Screen.h"
#include "AbstractEntity.h"
#include "myClock.h"
#include "InputManager.h"
class Movement
{
	int* MovementId;
	std::vector<sf::Sprite*>* sprites;
	std::vector<sf::Texture*>* textures;
	int* place;
public:
	sf::Sprite* getNextSprite();
	void resetMovements();
	int getId();
	Movement(int, std::vector<sf::Sprite*>*, std::vector<sf::Texture*>*);
	~Movement();
};

class Joueur : public AbstractEntity
{
	int* score;
	sf::Time* tempsMilli;
	int* idMove;
	sf::Vector2i* position;
	sf::Vector2i* taille;
	sf::Vector2f* vitesse;
	sf::Sprite* sprite;
	std::vector<Movement*>* movements;
	sf::Vector2f* saut;
	sf::Vector2f* deplacement;
public:
	//static Joueur* getInstance(std::list<Movement> moves);
	void Update();
	void Draw();
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
	Joueur(std::vector<Movement*>* moves, Screen& scre);
	~Joueur();
private:
};

#endif