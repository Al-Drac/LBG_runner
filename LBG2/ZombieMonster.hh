#ifndef DEF_ZOMBIEMONSTER
#define DEF_ZOMBIEMONSTER

#include "Character.hh"

class ZombieMonster : public Character

{
public:
  ZombieMonster();
  ~ZombieMonster();
  //incrémente X et Y de 5 par seconde (Vous DEVEZ utiliser votre TimeManager)
  void Update();
};

#endif
