#include "game.h"
#include <iostream>
#define N 100
#define R 5000


int main()
{
	TitForTat strategy;
	std::vector<Agent> agents(N, &strategy);
	Game game(agents, 5, 3, 10, 0, 0.002);
	for (int i = 1; i <= R; ++i)
		game.round();
	int s = 0;
	for (auto a : game.agents)
	{
		for (int i = 0; i < a.history.size(); ++i)
			if (i > 2.0 * R / 3)
    			s += a.history.at(i);
	}
	std::cout << 3.0*s/R/N;
	return 0;
}