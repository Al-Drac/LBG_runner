#ifndef _MAP_H_
#define _MAP_H_
#include <SFML/Graphics.hpp>
#include <stdio.h>
#include "Case.h"
#include "Screen.h"
#include "AbstractEntity.h"
#define TAILLE_ECRAN 1800
class Map : public AbstractEntity
{
private:
	float vitesse;
public: 
	Map(Screen& screen);
	~Map();
	void setVitesse(float);
	std::vector<Case*>* cases;
	Screen& screen;
	void Update();
	void Draw();
};




#endif