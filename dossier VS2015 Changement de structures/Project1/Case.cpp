#include "Case.h"
#include <cmath>

Case::Case(int couleur, sf::Vector2i *pos, sf::Vector2i* tail)
{
	type = couleur;
	position = new sf::Vector2i(*pos);
	taille = new sf::Vector2i(*tail);
	hitbox = new Hitbox(pos, tail, couleur);
	sprite = new sf::Sprite();
	sprite->setTexture(*Textures::getInstance()->getTexture(type));
	sprite->setPosition(sf::Vector2f(*position));
}

int Case::getType()
{
	return type;
}


sf::IntRect* Case::getHitbox()
{
	return hitbox->getIntRect();
}

Hitbox* Case::getMyHitbox()
{
	return hitbox;
}

sf::Sprite* Case::getSprite()
{
	return sprite;
}


Case::~Case()
{	
}
//decale la cases d'une valeur en arrière
void Case::decale(float tailleMap)
{
	position->x -= tailleMap;
	hitbox->SetPosition(*position);
	sprite->setPosition(sf::Vector2f(*position));
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
	strings.push_back("sol300x20.png");
	strings.push_back("sol100x20.png");
	strings.push_back("Cactus3sol60x50.png");
	strings.push_back("CactusGsol25x61.png");
	textures = new std::vector<sf::Texture*>();
	for (int i = 0; i < (int) strings.size(); i++)
	{
		sf::Texture* text = new sf::Texture();
		text->loadFromFile(strings.at(i));
		textures->push_back(text);
	}
}
sf::Texture* Textures::getTexture(int num)
{

	for (int i = 0; i < (int) textures->size(); i++)
	{
		if (i == num)
		{
			return textures->at(i);
		}
	}
	return NULL;
}

Textures::~Textures()
{}
Textures* Textures::getInstance()
{
	if (instance == NULL)
		instance = new Textures();
	return instance;
}