#include "ZombieMonster.hh"
#include "TimeManager.hh"

ZombieMonster::ZombieMonster() : Character(){
  SetLife(100);
}

ZombieMonster::~ZombieMonster(){
}

void ZombieMonster::Update(){
  unsigned int t = TimeManager::GetInstance().GetElapsedTime();
  double speed = t * 0.001 ;
  double x  = GetX() + speed;
  double y = GetY() + speed;
  SetX(x);
  SetY(y);
}
