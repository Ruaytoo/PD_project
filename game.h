#pragma once
#include <vector>
#include <random>
#include "payoff.h"
#include "strategy.h"


class Game {
 private:
  Payoff payoff;

 public:
  std::vector<Agent> agents;
  Game(float cc, float dc, float cd, float dd, double p);
  void round();
  void Generate_new_population();
};


