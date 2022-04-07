#include "strategy.h"
#include <string>


map<string, float> Strategy:: GetStrategy() {
	return params;
}

void Strategy::SetStrategy(string& n, map<string, float>& p) : 
	name(n`), params(p){};

bool DefectStrategy::MakeChoice() {
	return 1;
}
