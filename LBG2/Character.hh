#ifndef DEF_CHARACTER
#define DEF_CHARACTER
 

#include "AbstractEntity.hh"
#include "IObservable.hh"
 
class Character :  public IObservable 

{
protected :
  double x;
  double y;
  int life;
public:
  Character();
  virtual ~Character(void)=0;

  double GetX() const;
  void SetX(double value);
  double GetY() const;
  void SetY(double value);
  int GetLife() const;
  void SetLife(int value);


};
 
#endif
