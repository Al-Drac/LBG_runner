#pragma once
#ifndef OBS_H
#define OBS_H

#include <iostream>
#include <list>
#include <SFML/Graphics.hpp>
#include "myClock.h"
#include "Screen.h"
#include "Hitbox.h"

#define HAUTEUR_PERSO 49
#define LARGEUR_PERSO 40
typedef int Info;


class Observable;

class Observateur
{
protected:
	std::list<Observable*> m_list;
	typedef std::list<Observable*>::iterator iterator;
	typedef std::list<Observable*>::const_iterator const_iterator;
	virtual ~Observateur() = 0;
public:
	virtual void Update(const Observable* observable) const;

	void AddObs(Observable* obs);
	void DelObs(Observable* obs);
};

class Observable
{
	std::list<Observateur*> m_list;
	typedef std::list<Observateur*>::iterator iterator;
	typedef std::list<Observateur*>::const_iterator const_iterator;

public:
	void AddObs(Observateur* obs);
	void DelObs(Observateur* obs);

	virtual Info Statut(void) const = 0;
	virtual ~Observable();
protected:
	void Notify(void);

};



class MeteoFrance : public Observateur
{

};

#endif