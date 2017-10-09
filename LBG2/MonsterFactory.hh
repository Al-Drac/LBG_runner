#ifndef DEF_MONSTERFACTORY
#define DEF_MONSTERFACTORY

#include "Character.hh"
#include <unistd.h>
#include <string>

class MonsterFactory{
public:
  Character* Create(const std::string& type); 
};

#endif
