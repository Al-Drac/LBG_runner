#include "myClock.h"

myClock* myClock::getInstance()
{
	if (instance == NULL)
		instance = new myClock();
	return instance;
}

myClock* myClock::instance = NULL;

myClock::myClock()
{
	Clock = new sf::Clock();
}
myClock::~myClock()
{

}
sf::Clock* myClock::getClock()
{
	return Clock;
}

