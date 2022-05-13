#pragma once
#include "strategy.h"
#include <random>
#define C 10000


class Payoff {
 private:
  std::random_device rd;
  std::mt19937 gen;
  std::uniform_int_distribution<> distr;

 public:
  float p;
  float dd, dc, cd, cc;
  Payoff(float dd, float dc, float cd, float cc, float p);

  void UpdateScore(Agent* agent1, Agent* agent2, float score1, float score2,
                   int choice1, int choice2);

  void compute_score(Agent* agent1, Agent* agent2);
};
