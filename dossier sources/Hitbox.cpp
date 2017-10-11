#include "Hitbox.h"

sf::IntRect* Hitbox::getIntRect()
{
	return carre;
}

Hitbox::Hitbox(sf::Vector2i* pos, sf::Vector2i* taille)
{
	positionHitbox = pos;
	tailleHitbox = taille;
	carre = new sf::IntRect(*pos, *taille);
}
sf::Vector2f Hitbox::getPosition()
{
	return (sf::Vector2f)*positionHitbox;
}
Hitbox::~Hitbox()
{

}