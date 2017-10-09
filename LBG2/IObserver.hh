#ifndef IOBSERVER
#define IOBSERVER

//#include "IObservable.hh"

class IObservable;

class IObserver
{
public:
  IObserver(void) { }
  virtual ~IObserver(void) { }
  virtual void Notify(IObservable*){}
};

#endif
