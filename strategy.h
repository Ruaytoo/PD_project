#pragma once
#include <string>
#include <map>

class Strategy
{
public:
	std::map<std::string, float> GetStrategy();
	bool MakeChoice();
	void SetStrategy(std::string& n, std::map<std::string, float>& p);

private:
	std::map<std::string, float> params;
	std::string name;
};

class DefectStrategy : public Strategy {
	bool MakeChoice();
};
