#ifndef SCENE
#define SCENE

#include "AbstractEntity.hh"
#include <unistd.h>
#include <list>
#include <iostream>

class Scene{
public:
  std::list<AbstractEntity*> GetEntities();
  void AddEntity(AbstractEntity* e);
  void RemoveEntity(AbstractEntity* e);
  void Update();
  
  std::list<AbstractEntity*> entities;
};
#endif
