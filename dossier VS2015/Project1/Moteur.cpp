#include "Moteur.h"

Moteur::Moteur(Joueur* jou, Map* maps)
{
	joueur = jou;
	map = maps;
	gravite = new sf::Vector2f(0, 2);
}

void Moteur::draw()
{

}

void Moteur::update()
{
	//*joueur->plateform = compareMapAJoueur(joueur->getposition(), map->cases);
	*joueur->plateform = compareMapAJoueur(joueur->getHitbox(), map->cases);
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
	default:
		break;
	}
	// je remet au début de l'écran
	if (joueur->getposition().x > 1900)
	{
		joueur->setPosition(sf::Vector2i(LARGEUR_PERSO, 200.0f - HAUTEUR_PERSO));
		joueur->setVitesse(sf::Vector2f(joueur->getVitesse().x+2, 00.0f));
	}
	joueur->setPosition(joueur->getposition() + (sf::Vector2i)joueur->getVitesse());
	return;
}

Moteur::~Moteur()
{

}

int Moteur::compareMapAJoueur(Hitbox* joueurPos, std::vector<Case*>* cases)
{
	for each(Case* sf in *cases)
	{
		if (compare2a2(joueurPos->getIntRect(), sf->getHitbox()))
		{
			return sf->getType();
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

