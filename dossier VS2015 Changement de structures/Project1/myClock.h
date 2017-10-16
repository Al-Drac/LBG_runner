#ifndef _MY_CLOCK_H_
#define _MY_CLOCK_H_

#include <SFML/Graphics.hpp>

class MyClock
{
public :
	static MyClock* getInstance();
	sf::Clock* getClock();
private:
	sf::Clock* Clock;
	MyClock();
	~MyClock();
	static MyClock* instance;
};

#endif