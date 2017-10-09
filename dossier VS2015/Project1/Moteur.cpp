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
	if (compareMapAJoueur(joueur->getposition(), map->cases))
	{
		//met le joueur dans l'état de la case pour le test le metra à 1 ou 0 quand il est en l'air
		*joueur->plateform = 1;
	}
	else
		*joueur->plateform = 0;
	
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
		joueur->setVitesse(sf::Vector2f(joueur->getVitesse().x , joueur->getVitesse().y + gravite->y));
			break;
	default:
		break;
	}
	// je remet au début de l'écran
	if (joueur->getposition().x > 1900)
	{
		joueur->setPosition(sf::Vector2f(50.0f, 200.0f));
		joueur->setVitesse(sf::Vector2f(10.0f, 00.0f));
	}
	joueur->setPosition(joueur->getposition() + joueur->getVitesse());
	return;
}
Moteur::~Moteur()
{

}



bool Moteur::compareMapAJoueur(sf::Vector2f joueurPos, std::vector<Case*>* cases)
{
	for each(Case* sf in *cases)
	{
		if (compare2a2(joueurPos, sf->getPosition()))
		{
			return true;
		}
	}
	return false;
}
bool Moteur::compare2a2(sf::Vector2f joueurs, sf::Vector2f cas)
{
	if (abs(joueurs.x - cas.x) < TAILLE_JOUEUR && abs(joueurs.y - cas.y) < 1)
		return true;
	return false;
}