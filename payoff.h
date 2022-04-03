#pragma once
#include "agent.h"
#include <vector>

class payoff
{
private:
	float left_high, right_high, left_low, right_low;

public:
	payoff(float left_high, float right_high,
		float left_low, float right_low);

	~payoff();

	void compute_score(std::vector<agent>);
};