#include "game.h"
#include <ctime>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <random>
#include <chrono>

Game::Game(float cc, float dc, float cd, float dd, double p)
    : payoff(cc, dc, cd, dd, (float)p) {}

void Game::round() {
  unsigned seed =
      (unsigned)std::chrono::system_clock::now().time_since_epoch().count();

  shuffle(agents.begin(), agents.end(), std::default_random_engine(seed));

  for (std::size_t i = 0; i < agents.size() - 1; i += 2) {
    agents[i].choice = agents.at(i).strategy->MakeChoice(agents, (int)i);
    agents[i + 1].choice =
        agents.at(i + 1).strategy->MakeChoice(agents, (int)i + 1);
    payoff.compute_score(&agents[i], &agents[i + 1]);
  }
}

std::vector<int> Mutate(std::vector<int>& chromosome,
                        unsigned int mutation_index) {
  std::srand((unsigned int)std::time(0));
  if (mutation_index == 100) {
    mutation_index = (unsigned int)rand() % chromosome.size();
  } else if (mutation_index > 69)
    throw std::runtime_error("wrong strategy_name");
  std::vector<int> new_chromosome = chromosome;

  int OldValue = chromosome[mutation_index];
  int NewValue;

  if (OldValue == 0) {
    NewValue = 1;
  } else {
    NewValue = 0;
  }

  new_chromosome[mutation_index] = NewValue;

  return new_chromosome;
}

std::vector<int> Crossover(std::vector<int>& first_chromosome,
                           std::vector<int>& second_chromosome,
                           unsigned int random_state) {
  std::srand((unsigned int)std::time(0));

  std::vector<int> chromosome;
  if (random_state == 100) {
    random_state = (unsigned int)rand() % (first_chromosome.size() + 1);
  }

  for (unsigned int i = 0; i < random_state; i++) {
    chromosome.push_back(first_chromosome[(unsigned long)i]);
  }

  for (unsigned int i = random_state; i < second_chromosome.size(); i++) {
    chromosome.push_back(second_chromosome[i]);
  }

  return chromosome;

  return first_chromosome;
}

bool comp_agents(Agent& agent_1, Agent& agent_2) {
  return agent_1.score < agent_2.score;
}

void Game::Generate_new_population() {
  std::vector<Agent> new_agents;
  std::sort(agents.begin(), agents.end(), comp_agents);

  for (unsigned long i = 0; i < agents.size() / 2; i += 1) {
    unsigned long random_state = (unsigned long)rand() % (agents.size() / 2);

    Agent agent_1 = agents[random_state];
    random_state = (unsigned long)rand() % (agents.size());
    Agent agent_2 = agents[random_state];
    Agent agent = agents[(unsigned long)i];

    std::vector<int> first_chromosome = agent_1.strategy->chromosome;
    std::vector<int> second_chromosome = agent_2.strategy->chromosome;

    std::vector<int> new_chromosome =
        Crossover(first_chromosome, second_chromosome);
    agent.score = 0;
    agent.history = {};
    agent.strategy->chromosome = Mutate(new_chromosome);
    new_agents.push_back(agent);

    random_state = (unsigned long)rand() % (agents.size() / 2);
    agent_1 = agents[random_state];
    random_state = (unsigned long)rand() % (agents.size());
    agent_2 = agents[random_state];
    agent = agents[(unsigned long)i];

    first_chromosome = agent_1.strategy->chromosome;
    second_chromosome = agent_2.strategy->chromosome;

    new_chromosome = Crossover(first_chromosome, second_chromosome);
    agent.score = 0;
    agent.history = {};
    agent.strategy->chromosome = Mutate(new_chromosome);
    new_agents.push_back(agent);
  }

  agents = new_agents;
}
