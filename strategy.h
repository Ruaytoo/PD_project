#pragma once
#include <string>
#include <map>
#include <vector>
#include <iostream>

class Agent;

class Strategy
{
public:
	virtual bool MakeChoice(std::vector<Agent> agents, int agent_index) = 0;
	std::map<std::string, float> GetStrategy();
	void SetStrategy(std::string& n, std::map<std::string, float>& p);
    Strategy();
    std::vector<int> chromosome;

private:
	std::map<std::string, float> params;
	std::string name;
};



class DefectStrategy : public Strategy
{
	bool MakeChoice(std::vector<Agent> agents, int agent_index) override;
};


class TitForTat : public Strategy
{
	bool MakeChoice(std::vector<Agent> agents, int agent_index) override;
    void SetStart(int index, bool choice);

private:
    int start_strategy1 = 1;
    int start_strategy2 = 1;
};



class GeneticStrategy : public Strategy
{
    bool MakeChoice(std::vector<Agent> agents, int agent_index) override;
};



class Agent
{
public:
    void PrintStrategy();
    float score;
    std::vector<int> history;
    int choice;
    Agent();
    Strategy *strategy;
    int GetAgent_ID();

private:
    int Agent_ID;
};
