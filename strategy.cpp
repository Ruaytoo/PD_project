#include "strategy.h"
#include <string>

std::map<std::string, float> Strategy::GetStrategy() {
	return params;
}

void Strategy::SetStrategy(std::string& n, std::map<std::string, float>& p)
{
		name = n;
		params = p;
};

bool DefectStrategy::MakeChoice() {
	return 1;
}

bool TitForTat::MakeChoice() {
	return 1;
}