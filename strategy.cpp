#include "strategy.h"
#include <string>
#include <vector>
#include <iostream>

std::map<std::string, float> Strategy::GetStrategy() {
	return params;
}

void Strategy::SetStrategy(std::string& n, std::map<std::string, float>& p)
{
		name = n;
		params = p;
};

bool DefectStrategy::MakeChoice(std::vector<int> history) {
	return 0;
}

bool TitForTat::MakeChoice(std::vector<int> history) {
	if (history.size() == 0)
		return 1;
	return history.back();
}