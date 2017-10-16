#include "Hitbox.h"

sf::IntRect* Hitbox::getIntRect()
{
	return carre;
}

Hitbox::Hitbox(sf::Vector2i* pos, sf::Vector2i* taille, int type)
{
	positionHitbox = pos;
	tailleHitbox = taille;
	carre = new sf::IntRect(*pos, *taille);
	type_hitbox = type;
}
sf::Vector2f Hitbox::getPosition()
{
	return (sf::Vector2f)*positionHitbox;
}
int Hitbox::Statut() 
{
	return type_hitbox;
}

 void Hitbox::SetPosition(sf::Vector2i pos)
{
*positionHitbox = pos;
*carre = sf::IntRect(pos, *tailleHitbox);
	if (type_hitbox == -1)
	{
		Notify();
	}
}

Hitbox::~Hitbox()
{
}