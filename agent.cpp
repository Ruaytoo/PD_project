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

