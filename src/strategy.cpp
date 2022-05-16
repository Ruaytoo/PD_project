#include "../headers/strategy.h"
#include <string>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>
#include <random>
#include <chrono>

Strategy::Strategy() {
  std::srand((unsigned int)std::time(0));

  for (int j = 0; j < 70; j++) {
    int random_state = rand() % 2;

    if (random_state % 2 == 0) {
      chromosome.push_back(0);
    } else {
      chromosome.push_back(1);
    }
  }
}

std::map<std::string, float> Strategy::GetStrategy() { return params; }

void Strategy::SetStrategy(std::string &n, std::map<std::string, float> &p) {
  name = n;
  params = p;
};

bool DefectStrategy::MakeChoice(const std::vector<Agent> &agents,
                                int agent_index) {
  if (agents.size() > (unsigned long)agent_index)
    return 0;
  else
    throw std::runtime_error("wrong agent index in DefectStrategy");
}

bool CoopStrategy::MakeChoice(const std::vector<Agent> &agents,
                              int agent_index) {
  if (agents.size() > (unsigned long)agent_index)
    return 1;
  else
    throw std::runtime_error("wrong agent index in CoopStrategy");
}

bool TitForTat::MakeChoice(const std::vector<Agent> &agents, int agent_index) {
  if (agents[(unsigned long)agent_index].history.empty()) {
    int init = rand() % 2;

    if (init % 2 == 0) {
      return start_strategy1;
    } else {
      return start_strategy2;
    }

  } else {
    if (agent_index % 2 == 0) {
      return agents[(unsigned long)agent_index + 1].history.back();

    } else {
      return agents[(unsigned long)agent_index - 1].history.back();
    }
  }
}

void TitForTat::SetStart(int index, bool choice) {
  if (index == 1) {
    start_strategy1 = choice;
  } else {
    start_strategy2 = choice;
  }
}

bool GeneticStrategy::MakeChoice(const std::vector<Agent> &agents,
                                 int agent_index) {
  unsigned long asBinary = 0;

  for (int i = 64; i < 70; ++i) {
    asBinary *= 2;
    asBinary += (unsigned long)agents.at((unsigned long)agent_index)
                    .strategy->chromosome.at((unsigned long)i);
  }

  return agents.at((unsigned long)agent_index)
      .strategy->chromosome.at(asBinary);
}

bool DetectiveStrategy::MakeChoice(const std::vector<Agent> &agents,
                                   int agent_index) {
  Agent agent = agents[(unsigned long)agent_index];
  if (agent.history.empty()) {
    return 0;
  }

  if (agent.history[agent.history.size() - 1] == 1) {
    double new_p = p;
    if (p < 1) {
      new_p += 0.1;
    }
    float random_var = float(rand()) / RAND_MAX;
    if (random_var > p) {
      p = new_p;
      return 0;
    } else {
      p = new_p;
      return 1;
    }
  }

  else {
    if (p > 0.1) {
      p -= 0.1;
    }
    return 0;
  }
}
