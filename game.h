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


std::vector<int> Mutate(std::vector<int>& chromosome,
                        unsigned int mutation_index=100);

std::vector<int> Crossover(std::vector<int>& first_chromosome, std::vector<int>& second_chromosome,
                           unsigned int random_state = 100);

bool comp_agents(Agent& agent_1, Agent& agent_2);

