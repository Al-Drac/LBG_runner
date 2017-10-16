#include "myClock.h"

MyClock* MyClock::getInstance()
{
	if (instance == NULL)
		instance = new MyClock();
	return instance;
}

MyClock* MyClock::instance = NULL;

MyClock::MyClock()
{
	Clock = new sf::Clock();
}
MyClock::~MyClock()
{

}
sf::Clock* MyClock::getClock()
{
	return Clock;
}