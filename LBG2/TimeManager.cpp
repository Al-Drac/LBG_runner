
#include "TimeManager.hh"
#include <chrono>
#include <iostream>
#include <unistd.h>
using namespace std;

TimeManager TimeManager::m_instance=TimeManager();

int TimeManager::startedTime;
int TimeManager::elapsedTime;
//auto TimeManager::start =0;
//auto TimeManager::stockedTime1=0;
//auto TimeManager::stockedTime2=0;

TimeManager::TimeManager()
{
  //cout<<"Creation"<<endl;
}

TimeManager::~TimeManager()
{
  //cout<<"Destruction"<<endl;
}

TimeManager& TimeManager::GetInstance()
{
  return m_instance;
}

void  TimeManager::Start(){
  auto beginningOfTime = std::chrono::system_clock::now().time_since_epoch();
  auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(beginningOfTime).count();
  start =  ms;
}

void TimeManager::Update(){
  auto beginningOfTime = std::chrono::system_clock::now().time_since_epoch();
  auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(beginningOfTime).count();
  if(stockedTime1 == 0){
    stockedTime1 =  ms;
  }
  else if (stockedTime2 == 0 && (ms > stockedTime1)){
    stockedTime2 = ms;
  }
  else {
    stockedTime1 = stockedTime2;
    stockedTime2 = ms;
  }
}

unsigned int TimeManager::GetElapsedTime() const {
  TimeManager::elapsedTime = (stockedTime2 - stockedTime1);
  return elapsedTime;
}

unsigned int TimeManager::GetStartedTime() const {
  double toComp;
  if (stockedTime2 > stockedTime1){
    toComp = stockedTime2;
  }
  else{
    toComp = stockedTime1;
  }
  TimeManager::startedTime = (toComp - start);
  return startedTime;
}


/*
int main(void)
{
  //1er appel de Instance: on alloue le pointeur SoundManager::m_instance
  TimeManager& tm = TimeManager::GetInstance();
    
  //2eme appel:on se contente de renvoyer le pointeur déjà allouer.
  //TimeManager& ptr2=TimeManager::Instance();
  
  //ptr1 et ptr2 pointe sur la même adresse mémoire.
  //On voit donc qu'il ny a bien qu'un seul objet.
  //cout<<&ptr1<<"|"<<&ptr2<<endl;


  tm.Start();
  std::cout << "Start" << std::endl;
  std::cout << tm.start << std::endl;
  sleep(5);
  tm.Update();
  std::cout << "Socked Time 1" << std::endl;
  std::cout << tm.stockedTime1 << std::endl;
  sleep(5);
  tm.Update();
  tm.GetElapsedTime();
  std::cout << "Elapsed Time" << std::endl;
  std::cout << tm.elapsedTime << std::endl;
  std::cout << "Stocked Time 2" << std::endl;
  std::cout << tm.stockedTime2 << std::endl;
  std::cout << "GetStarted" << std::endl;
  tm.GetStartedTime();
  std::cout << tm.startedTime << std::endl;

  return 0;
  }
*/
/*
TimeManager::TimeManager() {};
TimeManager::~TimeManager() {};

TimeManager& TimeManager::GetInstance(){
  static TimeManager instance;
  
  return instance;
};

void  TimeManager::Start(){
  auto beginningOfTime = std::chrono::system_clock::now().time_since_epoch();
  auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(beginningOfTime).count();
  start =  ms * 0.001;
};

void TimeManager::Update(){
  auto beginningOfTime = std::chrono::system_clock::now().time_since_epoch();
  auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(beginningOfTime).count();
  if(stockedTime1 == 0){
  stockedTime1 =  ms * 0.001;
  }
  else if (stockedTime2 == 0 && (ms * 0.001 > stockedTime1)){
    stockedTime2 = ms * 0.001;
  }
  else {
    stockedTime1 = stockedTime2;
    stockedTime2 = ms * 0.001;
  }
};

unsigned int TimeManager::GetElapsedTime(){
  elapsedTime = stockedTime2 - stockedTime1;
  return elapsedTime;
};

unsigned int TimeManager::GetStartedTime(){
  int toComp; 
  if (stockedTime2 > stockedTime1){
    toComp = stockedTime2;
  }
  else{
    toComp = stockedTime1;
}
  startedTime = toComp - start;
  return startedTime;
*/

