#include "agent.h"

Agent::Agent(Strategy* strategy)
:strategy(strategy) 
{

}

void Agent::PrintStrategy() {
	std::map<std::string, float> strat = strategy->GetStrategy();
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
