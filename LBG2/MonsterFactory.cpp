#include "MonsterFactory.hh"
#include "ZombieMonster.hh"
#include "SprinterMonster.hh"
#include <unistd.h>

Character* MonsterFactory::Create(const std::string& type){
  if(type == "ZombieMonster"){
    return new ZombieMonster;
  }
  else if(type == "SprinterMonster"){
    return new SprinterMonster;
  }   
 return NULL;
}
