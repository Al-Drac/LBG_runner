#include "Moteur.h"

Moteur::Moteur(Joueur* jou, Map* maps, Screen screeen) : screen(screeen)
{
	joueur = jou;
	map = maps;
	gravite = new sf::Vector2f(0, 4);
	joueur->getHitbox()->AddObs(this);
	for (std::vector<Case*>::iterator it = map->cases->begin(); it != map->cases->end(); it++)
	{
		(*it)->getMyHitbox()->AddObs(this);
	}
}

void Moteur::draw()
{

}

void Moteur::Notified(Observable* obs)
{
	for (std::vector<Observable*>::iterator it = m_list.begin(); it != m_list.end(); it++)
	{
		if (compare2a2(obs->getIntRect(), (*it)->getIntRect()) && *it != obs)
		{
			*joueur->plateform = (*it)->Statut();
			return;
		}
	}
	*joueur->plateform = 0;
}

void Moteur::update()
{
	switch (*joueur->plateform)
	{
	case 1:
		if (joueur->getIdMove() == 1)
		{
			sf::Vector2f vitesse = joueur->getVitesse();
			sf::Vector2f saut = joueur->getSaut();
			joueur->setVitesse(sf::Vector2f(vitesse.x, vitesse.y + saut.y));
			joueur->setidMove(0);
		}
		else 
			joueur->setVitesse(sf::Vector2f(joueur->getVitesse().x, 0));
		break;
	case 0:
 		if (joueur->getIdMove() == 2)
			joueur->setVitesse(sf::Vector2f(joueur->getVitesse().x, joueur->getVitesse().y + gravite->y + 2));
		else
			joueur->setVitesse(sf::Vector2f(joueur->getVitesse().x, joueur->getVitesse().y + gravite->y));
			break;
	case 3:
			joueur->setVitesse(sf::Vector2f(0.0f, 0.0f));
			joueur->setidMove(3);
		break;
	case 4:
		joueur->setVitesse(sf::Vector2f(0.0f, 0.0f));
		joueur->setidMove(3);
		break;
	default:
		break;
	}
	// je remet au début de l'écran
	map->setVitesse(0.02f);
	joueur->setPosition(joueur->getposition() + (sf::Vector2i)joueur->getVitesse());
	return;
}

Moteur::~Moteur()
{

}

int Moteur::compareMapAJoueur(Hitbox* joueurPos, std::vector<Case*>* cases)
{
	for (int i = 0; i < (int) cases->size(); i++)
	{
		if (compare2a2(joueurPos->getIntRect(), cases->at(i)->getHitbox()))
		{
			return cases->at(i)->getType();
		}
	}
	return 0;
}

bool Moteur::compare2a2(sf::IntRect* joueurs, sf::IntRect* cas)
{
	if (joueurs->intersects(*cas))
		return true;
	return false;
}

