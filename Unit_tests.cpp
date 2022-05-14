#include "Unit_tests.h"

void RunTest(void (*func)(), const std::string& test_name) {
  try {
    func();
  } catch (std::runtime_error& e) {
    std::cerr << test_name << " fail: " << e.what() << std::endl;
  }
}

template <class T, class U>
void AssertEqual(T& t, U& u, std::string hint) {
  if (t != u) {
    std::string os = "";
    os = os + "Assertion failed: " + hint;
    throw std::runtime_error(os);
  }
}

void TestMutation() {
  std::vector<std::vector<int>> chromosomes = {
      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
      {0, 0, 0, 0, 0, 1, 1, 1, 1, 1}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
      {1, 1, 1, 0, 1, 1, 1, 1, 1, 1}, {0, 1, 0, 1, 0, 1, 0, 1, 0, 1},
      {1, 0, 0, 0, 1, 1, 0, 0, 0, 1}};

  std::vector<std::vector<int>> expected = {
      {1, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {1, 1, 1, 1, 1, 1, 1, 1, 1, 0},
      {0, 0, 0, 0, 1, 1, 1, 1, 1, 1}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
      {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, {0, 1, 0, 1, 0, 1, 1, 1, 0, 1},
      {1, 0, 0, 0, 1, 1, 0, 1, 0, 1}};

  std::vector<int> index = {0, 9, 4, 9, 3, 6, 7};

  for (unsigned long i = 0; i < index.size(); i++) {
    std::vector<int> chromosome =
        (std::vector<int>)Mutate(chromosomes[i], (unsigned int)index[i]);
    AssertEqual(expected[i], chromosome, std::to_string(i) + " test failed");
  }

  std::cerr << "mutation test ok" << '\n';
}

void TestCrossover() {
  std::vector<std::vector<int>> first_pair = {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                                              {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
                                              {0, 1, 0, 1, 0, 1, 0, 1, 0, 1},
                                              {0, 0, 1, 1, 1, 1, 1, 1, 0, 0}};

  std::vector<std::vector<int>> second_pair = {{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
                                               {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                                               {1, 0, 0, 0, 1, 1, 0, 0, 0, 1},
                                               {0, 0, 1, 1, 1, 1, 0, 0, 1, 1}};

  std::vector<int> index = {5, 5, 2, 10};

  std::vector<std::vector<int>> expected = {{0, 0, 0, 0, 0, 1, 1, 1, 1, 1},
                                            {1, 1, 1, 1, 1, 0, 0, 0, 0, 0},
                                            {0, 1, 0, 0, 1, 1, 0, 0, 0, 1},
                                            {0, 0, 1, 1, 1, 1, 1, 1, 0, 0}};

  for (unsigned long i = 0; i < index.size(); i++) {
    std::vector<int> chromosome =
        Crossover(first_pair[i], second_pair[i], (unsigned int)index[i]);
    AssertEqual(expected[i], chromosome, std::to_string(i) + " test failed");
  }

  std::cerr << "Crossover test ok" << '\n';
}

void TestGeneratePopulation() {
  std::vector<int> sizes = {10, 50, 100};

  for (unsigned long i = 0; i < 3; i++) {
    Game game(1, 1, 1, 1, 0);
    for (int j = 0; j < sizes[i]; j++) {
      Agent agent;
      agent.strategy = new DefectStrategy;
      game.agents.push_back(agent);
    }

    game.Generate_new_population();
    int size = (int)game.agents.size();
    AssertEqual(sizes[i], size, std::to_string(i) + " test failed");
  }

  std::cerr << "GeneratePopulation test ok" << '\n';
}

void TestUpdateScore() {
  Payoff payoff(1, 1, 1, 1, 1);
  Agent agent_1, agent_2;

  agent_1.strategy = new GeneticStrategy;
  agent_2.strategy = new GeneticStrategy;

  std::vector<std::pair<float, float>> scores = {
      std::make_pair(10, 10), std::make_pair(0, 5), std::make_pair(5, 0),
      std::make_pair(1, 1)};

  std::vector<std::pair<int, int>> choices = {
      std::make_pair(0, 0), std::make_pair(0, 1), std::make_pair(1, 0),
      std::make_pair(1, 1)};

  std::vector<std::pair<float, float>> expected_scores = {
      std::make_pair(10, 10), std::make_pair(0, 5), std::make_pair(5, 0),
      std::make_pair(1, 1)};

  std::vector<std::pair<int, int>> expected_choices = {
      std::make_pair(0, 0), std::make_pair(1, 0), std::make_pair(0, 1),
      std::make_pair(1, 1)};

  for (unsigned long i = 0; i < scores.size(); i++) {
    agent_1.score = 0;
    agent_2.score = 0;

    std::pair<float, float> score = scores[i];
    std::pair<int, int> choice = choices[i];
    payoff.UpdateScore(&agent_1, &agent_2, score.first, score.second,
                       choice.first, choice.second);

    std::pair<float, float> temp = std::make_pair(agent_1.score, agent_2.score);
    AssertEqual(expected_scores[i], temp,
                std::to_string(i) + "(1) test failed");

    std::pair<int, int> temp_2 =
        std::make_pair(agent_1.history.back(), agent_2.history.back());
    AssertEqual(expected_choices[i], temp_2,
                std::to_string(i) + "(2) test failed");
  }

  std::cerr << "GeneratePopulation test ok" << '\n';
}
