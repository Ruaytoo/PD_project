#pragma once
#include "strategy.h"
#include <random>
#define C 10000

///класс для пересчета текущего скора каждого игрока
class Payoff
{
private:
  std::random_device rd;
  std::mt19937 gen;
  std::uniform_int_distribution <> distr;



public:
  ///вероятность ошибки в начислении счета
  float p;
  ///очки за обоюдное предательство
  float dd;
  ///очки за предательство + сотрудничество
  float dc;
  ///очки за сотрудничество + предательство
  float cd;
  ///очки за обоюдное сотрудничество 
  float cc;
    Payoff (float dd, float dc, float cd, float cc, float p);

  void UpdateScore (Agent * agent1, Agent * agent2, float score1,
		    float score2, int choice1, int choice2);

  void compute_score (Agent * agent1, Agent * agent2);
};
