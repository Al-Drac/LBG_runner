#ifndef IOBSERVABLE
#define IOBSERVABLE

#include <list>
#include <unistd.h>
#include "IObserver.hh"
//class IObserver;

class IObservable
{
public:
  //void notifierObservateurs() const
  //{
    // Notifier tous les observateurs
  //list<IObservateur*>::const_iterator end = m_observateurs.end();
  //for (list<IObservateur*>::const_iterator it = m_observateurs.begin(); it != end; ++it)
  //  (*it)->notifier();
  //}
  
  IObservable(void) { }
  virtual ~IObservable(void) { }

  void AddObserver(IObserver* observer)
  {
    // On ajoute un abonné à la liste en le plaçant en premier (implémenté en pull).
    // On pourrait placer cet observateur en dernier (implémenté en push, plus commun).
    m_observers.push_front(observer);
  }

  void RemoveObserver(IObserver* observer)
  {
    // Enlever un abonné a la liste
    m_observers.remove(observer);
  }

  void notifyObservers(IObservable* IObservable) const
  {
    // Notifier tous les observateurs
    std::list<IObserver*>::const_iterator end = m_observers.end();
    for (std::list<IObserver*>::const_iterator it = m_observers.begin(); it != end; ++it)
      (*it)->Notify(IObservable);
  }
    
private:
  std::list<IObserver*> m_observers;
};

#endif
