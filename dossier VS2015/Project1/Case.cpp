#include "Case.h"
#include <cmath>

Case::Case(int couleur, sf::Vector2i *pos, sf::Vector2i* tail)
{
	type = couleur;
	position = new sf::Vector2f(*pos);
	hitbox = new Hitbox(pos, tail);
	sprite = new sf::Sprite();
	sprite->setTexture(*Textures::getInstance()->getTexture(type));
	position->y -= 100;
	sprite->setPosition(*position);
}

int Case::getType()
{
	return type;
}


sf::IntRect* Case::getHitbox()
{
	return hitbox->getIntRect();
}


sf::Sprite* Case::getSprite()
{
	return sprite;
}


Case::~Case()
{
	
}

sf::Vector2f Case::getPosition()
{
	return hitbox->getPosition();
}

Textures* Textures::instance = NULL;

//TODO modifier pour utiliser lire depuis fichier ressources
Textures::Textures()
{
	std::vector<std::string> strings;
	strings.push_back("background.png");
	strings.push_back("foreground2.png");
	strings.push_back("bump.png");
	//strings.push_back("cactus1.png");
	strings.push_back("cactus2.png");
	strings.push_back("cactus3.png");
	textures = new std::vector<sf::Texture*>();
	for each(std::string strin in strings)
	{
		sf::Texture* text = new sf::Texture();
		text->loadFromFile(strin);
		textures->push_back(text);
	}
}
sf::Texture* Textures::getTexture(int num)
{
	int i = 0;
	for each (sf::Texture* tex in *textures)
	{
		if (i == num)
		{
			return tex;
		}
		i++;
	}
}
//TODO
Textures::~Textures()
{}
Textures* Textures::getInstance()
{
	if (instance == NULL)
		instance = new Textures();
	return instance;
}