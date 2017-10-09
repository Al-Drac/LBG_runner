#include "AbstractEntity.hh"
#include "Character.hh"
#include "IObservable.hh"
#include "IObserver.hh"

Character::Character(){
}

Character::~Character(){
}

void Character::SetX(double xValue)
{
  this->x = xValue;
  IObservable::notifyObservers(this);
}
void Character::SetY(double yValue)
{
  this->y = yValue;
  IObservable::notifyObservers(this);
}
void Character::SetLife(int lifeValue)
{
  this->life = lifeValue;
  IObservable::notifyObservers(this);
}
double Character::GetX() const{
  return this->x;
}
double Character::GetY() const {
  return this->y;
}
int Character::GetLife() const{
  return this->life;
}
