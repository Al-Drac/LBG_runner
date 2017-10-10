#ifndef _HITBOX_H_
#define _HITBOX_H_
#include <SFML/Graphics.hpp>
class Hitbox
{
public:
	Hitbox(sf::Vector2i* pos, sf::Vector2i* taille);
	~Hitbox();
	sf::Vector2f getPosition();
	sf::IntRect* getIntRect();
private:
	sf::Vector2i* positionHitbox;
	sf::Vector2i* tailleHitbox;
	sf::IntRect* carre;
};
#endif _HITBOX_H_
