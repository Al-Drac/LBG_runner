#ifndef DEF_TIMEMANAGER
#define DEF_TIMEMANAGER

class TimeManager {

public:
  static TimeManager& GetInstance();
  void Start();
  //Mettre à jour
  void Update();
  //renvoie le temps passé en milliseconde entre les deux derniers appels de la méthode Update() (ou zéro dans le cas échéant )
  unsigned int GetElapsedTime() const;
  //renvoie le temps passé en milliseconde entre le dernier appel à la méthode Start() et le dernier appel a Update()
  unsigned int GetStartedTime() const;


  double start;
  static int startedTime;
  static int elapsedTime;
  double stockedTime1;
  double stockedTime2;

private:
  TimeManager& operator= (const TimeManager&);
  TimeManager (const TimeManager&);

  static TimeManager m_instance;
  TimeManager();
  ~TimeManager();


/*
private:
  TimeManager();
  ~TimeManager();
  TimeManager& operator= (const TimeManager&);
  TimeManager (const TimeManager&);

public:
  static TimeManager& GetInstance();
  //Remet à zero
  void Start();
  //Mettre à jour
  void Update();
  //renvoie le temps passé en milliseconde entre les deux derniers appels de la méthode Update() (ou zéro dans le cas échéant)
  unsigned int GetElapsedTime();
  //renvoie le temps passé en milliseconde entre le dernier appel à la méthode Start() et le dernier appel a Update()
  unsigned int GetStartedTime();

  int start;
  int startedTime;
  int elapsedTime;
  int stockedTime1  = 0;
  int stockedTime2 = 0;*/

};

#endif
