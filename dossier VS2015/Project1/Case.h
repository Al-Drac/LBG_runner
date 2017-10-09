#pragma once
#ifndef CASE_H
#define CASE_H
#include <SFML/Graphics.hpp>
class Case
{
public:
	Case(int, sf::Vector2f);
	int getCouleur();
	sf::Vector2f getPosition();
	sf::Sprite* getSprite();
	~Case();
private:
	int couleur;
	sf::Sprite* sprite;
	sf::Vector2f position;
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