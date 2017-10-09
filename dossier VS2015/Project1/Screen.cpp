#include "Screen.h"

Screen::Screen(sf::RenderWindow& wind) : window(wind)
{
}


void Screen::draw()
{
	window.clear();
	
}

void Screen::update()
{
	window.display();
}

void Screen::add(const sf::Sprite* sp)
{
	window.draw(*sp);
}

sf::RenderWindow& Screen::getWindow()
{
	return window;
}

Screen::~Screen()
{

}
