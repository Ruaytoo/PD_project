<<<<<<< HEAD
class agent
{
public:
	float score;
	std::vector<int> history;
	strategy strategy;
	agent(strategy strategy)
	{
		score = 0;
		strategy = strategy;
	}
};
=======
#include "agent.h"
#include <map>
#include <iostream>

void Agent::PrintStrategy() {
	map<string, float> strat = strategy.GetStrategy();
	cout << "Agent " << Agent_ID <<
                        " currently has the following strategy:" << endl;
	int i = 1;
	for (const auto& param : strat) {
		cout << param.first << " : " << param.second;
		if (i < strat.size()) {
			cout << ", ";
		}
		else {
			cout << endl;
		}
		i++;
	}
}

>>>>>>> e5dcebbf7186d97baf9ed6454e8295f09fcb0491
