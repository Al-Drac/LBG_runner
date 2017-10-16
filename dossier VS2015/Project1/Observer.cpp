#include "Observer.h"
using namespace std;

void Observateur::Update(const Observable* observable) const
{
	//on affiche l'�tat de la variable
	cout << observable->Statut() << endl;
}

Observateur::~Observateur()
{
	//pour chaque objet observ�, 
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
	//on enl�ve l'objet observ�.
	iterator it = std::find(m_list.begin(), m_list.end(), obs);
	if (it != m_list.end())
		m_list.erase(it);
}

void Observable::AddObs(Observateur* obs)
{
	//on ajoute l'observateur � notre liste 
	m_list.push_back(obs);

	//et on lui donne un nouvel objet observ�.
	obs->AddObs(this);
}

void Observable::DelObs(Observateur* obs)
{
	//m�me chose que dans Observateur::DelObs
	iterator it = find(m_list.begin(), m_list.end(), obs);
	if (it != m_list.end())
		m_list.erase(it);
}

Observable::~Observable()
{
	//m�me chose qu'avec Observateur::~Observateur
	iterator itb = m_list.begin();
	const_iterator ite = m_list.end();

	for (; itb != ite; ++itb)
	{
		(*itb)->DelObs(this);
	}
}

void Observable::Notify(void)
{
	//on pr�vient chaque observateur que l'on change de valeur
	iterator itb = m_list.begin();
	const_iterator ite = m_list.end();

	for (; itb != ite; ++itb)
	{
		(*itb)->Update(this);
	}
}