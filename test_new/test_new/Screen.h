#pragma once
#ifndef _SCREEN_H_
#define _SCREEN_H_
#include <list>
#include <vector>
#include <SFML/Graphics.hpp>
class Screen
{
	sf::RenderWindow& window;
public:
	void update();
	Screen(sf::RenderWindow&);
	~Screen();
	void draw();
    void addTxt(const sf::Text);
	void add(const sf::Sprite*);
	sf::RenderWindow& getWindow();
};



#endif // !_SCREEN_H_
