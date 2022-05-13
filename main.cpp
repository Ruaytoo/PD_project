#include "main.h"

int main() {
  RunTest(&TestMutation, "MutationTest");
  RunTest(&TestCrossover, "CrossoverTest");

  int N = 2;
  int R = 200;
  int E = 10;
  std::string strategy_name = "GeneticStrategy";

  parse(N, R, E, strategy_name);

  std::ofstream result;
  result.open("result.txt");
  result << N << ' ' << E << '\n';

  for (double p = 0; p <= 1; p += 0.01) {
    std::cout << p << '\n';

    for (int k = 0; k < E; ++k) {
      Game game(8, 0, 10, 3, static_cast<double>(p));

      for (int i = 0; i < N; ++i) {
        Agent agent;
        if (strategy_name == "GeneticStrategy")
          agent.strategy = new GeneticStrategy;
        else if (strategy_name == "TitForTat")
          agent.strategy = new TitForTat;
        else if (strategy_name == "DefectStrategy")
          agent.strategy = new DefectStrategy;
        else if (strategy_name == "CoopStrategy")
          agent.strategy = new CoopStrategy;
        else
          throw std::runtime_error("wrong strategy_name");
        game.agents.push_back(agent);
      }

      for (int i = 1; i <= R; ++i) {
        for (int j = 0; j < 10; ++j) game.round();
        game.Generate_new_population();
      }

      for (unsigned long i = 1; i <= 10; ++i) {
        game.round();
      }

      for (auto a : game.agents) {
        for (unsigned long i = 0; i < a.history.size(); ++i) {
          result << a.history.at(i) << ' ';
        }
        result << '\n';
      }
    }
  }

  result.close();

  return 0;
}

void parse(int& N, int& R, int& E, std::string& strategy_name) {
  std::ifstream cFile("config.txt");

  if (cFile.is_open()) {
    std::string line;

    while (getline(cFile, line)) {
      line.erase(std::remove_if(line.begin(), line.end(), isspace), line.end());

      if (line[0] == '#' || line.empty()) continue;
      auto delimiterPos = line.find("=");
      auto name = line.substr(0, delimiterPos);
      auto value = line.substr(delimiterPos + 1);
      
      if (name == "N") N = std::stoi(value);
      if (name == "R") R = std::stoi(value);
      if (name == "E") E = std::stoi(value);
      if (name == "strategy") strategy_name = value;
    }

  } else {
    std::cerr
        << "Couldn't open config file for reading.\n Using default values.";
  }
}