#pragma once
#include "agent.h"
#include <string>
#include <map>

class Strategy
{
public:
	map<string, float> GetStrategy();
	virtual bool MakeChoice() const {};
	void SetStrategy(string& n, map<string, float>& p);

private:
	map<string, float> params;
	string name;
};

class DefectStrategy : Strategy {
	bool MakeChoice() {};
}
