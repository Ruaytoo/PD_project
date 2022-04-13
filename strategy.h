#pragma once
#include <string>
#include <map>

class Strategy
{
public:
	virtual bool MakeChoice() = 0;
	std::map<std::string, float> GetStrategy();
	void SetStrategy(std::string& n, std::map<std::string, float>& p);

private:
	std::map<std::string, float> params;
	std::string name;
};

class DefectStrategy : public Strategy{
	bool MakeChoice() override;
};


class TitForTat : public Strategy{
	bool MakeChoice() override;
};
