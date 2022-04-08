/*#include <vector>
#include <string>
#include "strategy.h"

class agent
{
public:
	float score;
	std::vector<int> history;
	Strategy strategy;
	agent(Strategy strategy)
	{
		score = 0;
		strategy = strategy;
	}
};*/

#include "agent.h"
#include <map>
#include <iostream>

Agent::Agent(Strategy strategy)
:strategy(strategy) {}

void Agent::PrintStrategy() {
	std::map<std::string, float> strat = strategy.GetStrategy();
	std::cout << "Agent " << Agent_ID <<
                        " currently has the following strategy:" << std::endl;
	int i = 1;
	for (const auto& param : strat) {
		std::cout << param.first << " : " << param.second;
		if (i < strat.size()) {
			std::cout << ", ";
		}
		else {
			std::cout << std::endl;
		}
		i++;
	}
}
