#ifndef ABSTRACT_ENTITY_H
#define         ABSTRACT_ENTITY_H
#include "Hitbox.h"
#include <vector>
#include <SFML/Graphics.hpp>
class           AbstractEntity
{
public:
	AbstractEntity(void) {};
	virtual  ~AbstractEntity(void) = 0;
	virtual void Draw();
	virtual void Update();
	virtual void MoveHitBoxes(sf::Vector2i);
private :
	std::vector<Hitbox> hitboxes;
};
#endif
