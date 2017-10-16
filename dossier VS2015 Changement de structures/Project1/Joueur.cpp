#include "Joueur.h"

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
	score += valeur;
}

sf::Time Joueur::getTemps()
{
	return *tempsMilli;
}

int Joueur::getScore()
{
	return *score;
}
void Joueur::Update()
{
	addTemps(MyClock::getInstance()->getClock()->getElapsedTime());
	if (idMove != InputManager::getInstance(screen)->getInputValue()|| tempsMilli->asMilliseconds() > 150.0f)
		idMove = InputManager::getInstance(screen)->getInputValue();
	if (tempsMilli->asMilliseconds() > 150.0f)
	{
 		
		*tempsMilli = sf::Time();
		for (int i = 0; i < movements->size(); i++)
		{
			if (*idMove == (*movements->at(i)).getId())
			{
				sprite = (*movements->at(i)).getNextSprite();
			}
		}
	}
	sprite->setPosition(sf::Vector2<float>(*position));
	hitbox->SetPosition(*position);
	return;
}
void Joueur::Draw()
{
	screen.add(getSprite());
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

Joueur::Joueur(std::vector<Movement*>* moves, Screen& scre) : screen(scre)
{
	movements = moves;
	saut = new sf::Vector2f(0, -30);
	vitesse = new sf::Vector2f(0.0f, 0.0f);
	position = new sf::Vector2i(LARGEUR_PERSO, 200 - HAUTEUR_PERSO);
	taille = new sf::Vector2i(LARGEUR_PERSO, HAUTEUR_PERSO);
	hitbox = new Hitbox(position, taille, -1);
	tempsMilli = new sf::Time();
	deplacement = new sf::Vector2f(10, 0);
	plateform = new int(0);
	sprite = new sf::Sprite();
	idMove = new int();
	score = new int(0);
}
Joueur::~Joueur()
{

}

void Joueur::Change(int valeur)
{
	if (*plateform != valeur)
	{
		*plateform = valeur;
	}
}

int Joueur::Statut(void) const
{
	return *plateform;
}

sf::Sprite* Joueur::getSprite()
{
	return sprite;
}

void Joueur::setidMove(int move)
{
	*idMove = move;
}

Movement::Movement(int id, std::vector<sf::Sprite*>* spritess, std::vector<sf::Texture*>* tes)
{
	MovementId = new int(id);
	sprites = spritess;
	textures = tes;
	place = new int(0);
	textures = tes;
}

Movement::~Movement()
{

}

//retourne le prochaine sprite ou le premier si on était déjà au dernier.
sf::Sprite* Movement::getNextSprite()
{
	if (sprites->size() > 0)
	{
		if (*place == sprites->size() - 1)
			resetMovements();
		else
			(*place)++;
	}
	return sprites->at(*place);
}

int Movement::getId()
{
	return *MovementId;
}

void Movement::resetMovements()
{
	*place = 0;
}