#include "Loader.h"
Loader::Loader(std::list<std::string> lst)
{
	tabImages = std::list<std::string>();
	for (std::list<std::string>::iterator it = lst.begin(); it != lst.end(); it++)
	{
		tabImages.push_back(*it);
	}

}
Loader::~Loader() {
	
}
std::vector<Movement>* Loader::getMoves()
{
	initPers();
	return moves;
}
void Loader::initPers()
{
	sf::Texture* texture;
	moves = new std::vector<Movement>();
	std::list<std::string>::iterator it = tabImages.begin();
	for (unsigned int i = 0; i < tabImages.size(); i++)
	{
		std::vector<sf::Sprite*>* sprites = new std::vector<sf::Sprite*>();
		std::vector<sf::Texture*>* textures = new std::vector<sf::Texture*>();
		for (int y = 0; y < IMG_SIZE / TAILLE_PERS; y++)
		{
			sf::Sprite* sprite = new sf::Sprite();
			texture = new sf::Texture();
			if (!texture->loadFromFile(*it, sf::IntRect(y*TAILLE_PERS, 0, (1 + y)*TAILLE_PERS, TAILLE_PERS)))
				std::cout << "erreur" << std::endl;
			else {
					sprite->setTexture(*texture);
					textures->push_back(texture);
					sprites->push_back(sprite);
				}
		}
		moves->push_back(Movement(i, sprites, textures));
		it++;
	}
}