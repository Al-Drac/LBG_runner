#include "Game.h"

Game::~Game()
{

}

Game::Game(Screen& screenn, Loader& load) : screen(screenn), joueur(new Joueur(load.getMoves(), screenn))
{
	if (joueur != NULL)
	{
		map = new Map();
		moteur = new Moteur(joueur, map);
	}
}

void Game::update()
{
	screen.draw();
	moteur->update();
	joueur->update();
	//map->update();
}
void Game::draw()
{
	for (std::vector<Case*>::iterator it = map->cases->begin(); it != map->cases->end(); it++)
	{
		screen.add((*it)->getSprite());
	}

	/*
	for each (Case* casess in *map->cases)
		screen.add(map->cases->end()->getSprite());
	*/
    
    
    sf::Font font;
    if (!font.loadFromFile(resourcePath() + "sansation.ttf"))
    {
        // error...
    }
    int actualScore = joueur->getScore();
    
    //std::string s = std::to_string(actualScore);
    
    std::stringstream s;
    s << actualScore;
    std::string str = s.str();
    
    sf::Text message;
    message.setFont(font);
    message.setString(str);
    message.setCharacterSize(24);
    message.setColor(sf::Color::Red);
    screen.addTxt(message);
    
    
	screen.add(joueur->getSprite());
	screen.update();

}

void drawScore(){
}

sf::RenderWindow& Game::getWindow()
{
	return screen.getWindow();
}

Joueur* Game::getJoueur()
{
	return joueur;
}

