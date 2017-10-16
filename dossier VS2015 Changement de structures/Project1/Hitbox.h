#ifndef _HITBOX_H_
#define _HITBOX_H_
#include <SFML/Graphics.hpp>
#include "Observer.h"

class Hitbox : public Observable
{
public:
	Hitbox(sf::Vector2i* pos, sf::Vector2i* taille, int type);
	~Hitbox();
	std::vector<Observateur*> m_list;
	sf::Vector2f getPosition();
	sf::IntRect* getIntRect();
	int Statut();
	void SetPosition(sf::Vector2i pos);
private:
	sf::Vector2i* positionHitbox;
	int type_hitbox;
	sf::Vector2i* tailleHitbox;
	sf::IntRect* carre;
};
#endif _HITBOX_H_
