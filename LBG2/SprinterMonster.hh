#ifndef DEF_SPRINTERMONSTER
#define DEF_SPRINTERMONSTER

#include "Character.hh"

class SprinterMonster : public Character

{
public:
  SprinterMonster();
  ~SprinterMonster();
  //incrémente X et Y de 5 par seconde (Vous DEVEZ utiliser votre TimeManager)
  void Update();
};

#endif
