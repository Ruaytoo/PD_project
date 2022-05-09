#pragma once
#include <string>
#include <map>
#include <vector>
#include <iostream>

class Agent;

class Strategy
{
public:
	virtual bool MakeChoice(const std::vector<Agent>& agents, int agent_index) = 0;
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
public:
	bool MakeChoice(const std::vector<Agent>& agents, int agent_index);
};


class CoopStrategy : public Strategy
{
public:
    bool MakeChoice(const std::vector<Agent>& agents, int agent_index);
};


class TitForTat : public Strategy
{
	bool MakeChoice(const std::vector<Agent>& agents, int agent_index);
    void SetStart(int index, bool choice);

private:
    int start_strategy1;
    int start_strategy2;
};



class GeneticStrategy : public Strategy
{
    bool MakeChoice(const std::vector<Agent>& agents, int agent_index);
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
