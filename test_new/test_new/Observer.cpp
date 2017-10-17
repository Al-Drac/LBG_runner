#include <iostream>

#include "Observer.h"
using namespace std;

void Observateur::Update(const Observable* observable) const
{
	//on affiche l'état de la variable
	cout << observable->Statut() << endl;
}

Observateur::~Observateur()
{
	//pour chaque objet observé, 
	//on lui dit qu'on doit supprimer l'observateur courant
	const_iterator ite = m_list.end();

	for (iterator itb = m_list.begin(); itb != ite; ++itb)
	{
		(*itb)->DelObs(this);
	}
}

void Observateur::AddObs(Observable* obs)
{
	m_list.push_back(obs);
}

void Observateur::DelObs(Observable* obs)
{
	//on enlève l'objet observé.
	iterator it = std::find(m_list.begin(), m_list.end(), obs);
	if (it != m_list.end())
		m_list.erase(it);
}

void Observable::AddObs(Observateur* obs)
{
	//on ajoute l'observateur à notre liste 
	m_list.push_back(obs);

	//et on lui donne un nouvel objet observé.
	obs->AddObs(this);
}

void Observable::DelObs(Observateur* obs)
{
	//même chose que dans Observateur::DelObs
	iterator it = find(m_list.begin(), m_list.end(), obs);
	if (it != m_list.end())
		m_list.erase(it);
}

Observable::~Observable()
{
	//même chose qu'avec Observateur::~Observateur
	iterator itb = m_list.begin();
	const_iterator ite = m_list.end();

	for (; itb != ite; ++itb)
	{
		(*itb)->DelObs(this);
	}
}

sf::Vector2f Joueur::getVitesse()
{
	return *vitesse;
}
sf::Vector2i Joueur::getposition()
{
	return *position;
}
void Joueur::setVitesse(sf::Vector2f valeur)
{
	*vitesse = valeur;
}
void Joueur::setPosition(sf::Vector2i valeur)
{
	*position = valeur;
}



void Joueur::addTemps(sf::Time valeur)
{
	*tempsMilli += valeur;
}

void Joueur::addScore(int valeur)
{
	score = score + valeur;
}

sf::Time Joueur::getTemps()
{
	return *tempsMilli;
}

int Joueur::getScore()
{
	return score;
}

void Observable::Notify(void)
{
	//on prévient chaque observateur que l'on change de valeur
	iterator itb = m_list.begin();
	const_iterator ite = m_list.end();

	for (; itb != ite; ++itb)
	{
		(*itb)->Update(this);
	}
}

void Joueur::SpriteAdvance()
{

}

void Joueur::update()
{
	addTemps(myClock::getInstance()->getClock()->getElapsedTime());
	if (tempsMilli->asMilliseconds() > 150.0f)
	{
		tempsMilli = new sf::Time();
		for (int i = 0; i < movements->size(); i++)
		{
			if (*idMove == movements->at(i).getId())
			{
				sprite = movements->at(i).getNextSprite();
				*idMove = 0;
                addScore(1);
			}
		}
		/*
		for each (Movement mov in *movements)
		{
			if (*idMove == mov.getId())
			{
				sprite = mov.getNextSprite();
				*idMove = 0;
			}
		}
		*/
	}
    //addScore(1);
	sprite->setPosition((sf::Vector2f)*position);
	delete hitbox;
	hitbox = new Hitbox(position, taille);
	return;
}
void Joueur::draw()
{
}

int Joueur::getIdMove()
{
	return *idMove;
}


sf::Vector2f Joueur::getSaut()
{
	return *saut;
}


Hitbox* Joueur::getHitbox()
{
	return hitbox;
}

Joueur::Joueur(std::vector<Movement>* moves, Screen scre) : screen(scre)
{
	movements = moves;
	saut = new sf::Vector2f(0, -20);
	vitesse = new sf::Vector2f(8.0f, 0.0f);
	position = new sf::Vector2i(LARGEUR_PERSO, 200.0f-HAUTEUR_PERSO);
	taille = new sf::Vector2i(HAUTEUR_PERSO, LARGEUR_PERSO);
	hitbox = new Hitbox(position, taille);
	tempsMilli = new sf::Time();
	deplacement = new sf::Vector2f(10, 0);
	plateform = new int(0);
	sprite = new sf::Sprite();
	idMove = new int(0);
	score = 0;
}
Joueur::~Joueur()
{

}

void Joueur::Change(int valeur)
{
	if (*plateform != valeur)
	{
		*plateform = valeur;
		Notify();
	}
}


int Joueur::Statut(void) const
{
	return *plateform;
}

Movement::Movement(int id, std::vector<sf::Sprite*>* sprites, std::vector<sf::Texture*>* tes)
{
	MovementId = new int (id);
	movements = sprites;
	textures = tes;
	place = new int(0);
	movements = sprites;
	textures = tes;
}
sf::Sprite* Joueur::getSprite()
{
	return sprite;
}

void Joueur::setidMove(int move)
{
	*idMove = move;
}

Movement::~Movement()
{

}
//retourne le prochaine sprite ou le premier si on était déjà au dernier.
sf::Sprite* Movement::getNextSprite()
{
	if (movements->size() > 0)
	{
		if (*place == movements->size()-1)
			resetMovements();
		else
			(*place)++;
	}
	
	return movements->at(*place);
}
int Movement::getId()
{
	return *MovementId;
}
void Movement::resetMovements()
{
	*place = 0;
}
