#pragma once
#include "agent.h"
#include <string>
#include <map>
#include <vector>

class Strategy
{
public:
	virtual bool MakeChoice(std::vector<Agent> agents, int agent_index) = 0;
	std::map<std::string, float> GetStrategy();
	void SetStrategy(std::string& n, std::map<std::string, float>& p);

private:
	std::map<std::string, float> params;
	std::string name;
};

class DefectStrategy : public Strategy{
	bool MakeChoice(std::vector<Agent> agents, int agent_index) override;
};


class TitForTat : public Strategy{
	bool MakeChoice(std::vector<Agent> agents, int agent_index) override;
    void SetStart(int index, bool choice);

private:
    int start_strategy1 = 1;
    int start_strategy2 = 1;
};
