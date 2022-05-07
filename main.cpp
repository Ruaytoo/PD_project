#include "game.h"
#include <iostream>
#define N 6
#define R 40


int main()
{
	Game game(5, 3, 10, 1, (double) 0.01);

	for (int i = 0; i < N; ++i)
	{
		DefectStrategy strategy;
		Agent agent;
		agent.strategy = &strategy;
		game.agents.push_back(agent);
		//std::cout << agent.strategy->MakeChoice(game.agents, i) << ' ';
		if (i > 1)
			std::cout << game.agents.at(i).strategy->MakeChoice(game.agents, i) << ' ';
	}


	std::cout << '\n';

	for (int i = 0; i < N; ++i)
	{
		std::cout << game.agents.at(i).strategy->MakeChoice(game.agents, i);
	}

	for (unsigned long i = 1; i <= R; ++i)
	{
		game.round();
		game.Generate_new_population();
	}

	for (unsigned long i = 1; i <= 40; ++i)
	{
		game.round();
	}

	int s = 0;
	for (auto a : game.agents)
	{
		for (unsigned long i = 0; i < a.history.size(); ++i)
		{
			std::cout << a.history.at(i) << ' ';
			if (i >= 9.0 * R / 10)
    			s += a.history.at(i);
		}
		std::cout << "a\n\n";
	}
	std::cout << 10.0*s/R/N;

	return 0;
}