#pragma once
#ifndef _MY_CLOCK_H_
#define _MY_CLOCK_H_
#include <SFML/Graphics.hpp>

class myClock
{
public :
	static myClock* getInstance();
	sf::Clock* getClock();
private:
	sf::Clock* Clock;
	myClock();
	~myClock();
	static myClock* instance;
};

#endif