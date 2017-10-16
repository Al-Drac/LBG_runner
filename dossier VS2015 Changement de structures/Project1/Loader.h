#pragma once
#ifndef _LOADER_H_
#define _LOADER_H_
#define TAILLE_PERS 64
#define IMG_SIZE 128
#include <list>
#include <vector>
#include <iostream>
#include "Joueur.h"
class Loader
{
	std::vector<Movement*>* moves;
	std::list<std::string> tabImages;
	//map
public:
	Loader(std::list<std::string> lst);
	~Loader();
	std::vector<Movement*>* getMoves();
	//getmap;
private:
	void initPers();
	//void initMap();
};

#endif _LOADER_H_