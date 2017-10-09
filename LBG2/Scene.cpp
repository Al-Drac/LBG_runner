#include "Scene.hh"
#include "TimeManager.hh"
#include "AbstractEntity.hh"
#include <iostream>


std::list<AbstractEntity*> Scene::GetEntities(){
  return entities;
}

void Scene::AddEntity(AbstractEntity* e){
  entities.push_back(e);
}

void Scene::RemoveEntity(AbstractEntity* e){
  entities.remove(e);
}

void Scene::Update(){
  TimeManager::GetInstance().Update();
  for (std::list<AbstractEntity*>::iterator it = entities.begin(); it != entities.end(); it++){
    (*it)->Update();
    (*it)->Draw();
  }
}
