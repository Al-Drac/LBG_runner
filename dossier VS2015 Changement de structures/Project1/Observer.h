#ifndef OBS_H
#define OBS_H

#include <vector>
#include <iostream>
#include <SFML\Graphics.hpp>
#define HAUTEUR_PERSO 49
#define LARGEUR_PERSO 40


class Observable;

class Observateur
{
protected:
	std::vector<Observable*> m_list;
	typedef std::vector<Observable*>::iterator iterator;
	typedef std::vector<Observable*>::const_iterator const_iterator;
	virtual ~Observateur() = 0;
public:
	virtual void Notified(Observable* observable) = 0;

	void AddObs(Observable* obs);
	void DelObs(Observable* obs);
};

class Observable
{
	std::vector<Observateur*> m_list;
	typedef std::vector<Observateur*>::iterator iterator;
	typedef std::vector<Observateur*>::const_iterator const_iterator;

public:
	void AddObs(Observateur* obs);
	void DelObs(Observateur* obs);
	virtual sf::IntRect* getIntRect();
	virtual void SetPosition(sf::Vector2i pos);
	virtual int Statut(void) = 0;
	virtual ~Observable();
protected:
	void Notify(void);

};
#endif