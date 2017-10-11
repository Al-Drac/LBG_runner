#pragma once
#ifndef CASE_H
#define CASE_H
#include <list>
#include <vector>
#include <SFML/Graphics.hpp>
#include "Hitbox.h"

class Case
{
public:
	Case(int, sf::Vector2i* pos, sf::Vector2i* taille);
	sf::Vector2f getPosition();
	sf::Sprite* getSprite();
	int getType();
	sf::IntRect* getHitbox();
	~Case();
private:
	int type;
	Hitbox* hitbox;
	sf::Sprite* sprite;
	sf::Vector2f* position;
	sf::Vector2f* taille;
};
class Textures
{
public:
	static Textures* getInstance();
	sf::Texture* getTexture(int);

private:
	Textures();
	~Textures();
	static Textures* instance;
	std::vector<sf::Texture*>* textures;
};
#endif