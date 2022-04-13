#include "strategy.h"
#include <string>


bool Strategy::MakeChoice() {
	return 1;
}

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
