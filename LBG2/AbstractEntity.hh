#ifndef ABSTRACT_ENTITY_H
	#define         ABSTRACT_ENTITY_H
	class           AbstractEntity
	{
		public:
	  AbstractEntity(void){};
	  virtual  ~AbstractEntity(void)=0;
	  virtual void Draw();
	  virtual void Update();
	};
#endif
