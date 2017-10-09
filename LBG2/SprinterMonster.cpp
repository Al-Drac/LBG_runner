#include "SprinterMonster.hh"
#include "TimeManager.hh"

SprinterMonster::SprinterMonster() : Character(){
  SetLife(25);
}

SprinterMonster::~SprinterMonster(){
}

void SprinterMonster::Update(){
  unsigned int t = TimeManager::GetInstance().GetElapsedTime();
  double speed = t * 0.005;
  double x  = GetX() + speed;
  double y = GetY() + speed;
  SetX(x);
  SetY(y);
}
