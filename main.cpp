#include "game.h"
#include <iostream>
#define N 20
#define R 40000


int main()
{
	Game game(8, 0, 10, 3, (double) 0.01);


	for (int i = 0; i < N; ++i)
	{
		Agent agent;
		agent.strategy = new GeneticStrategy;
		game.agents.push_back(agent);
	}



	for (unsigned long i = 1; i <= R; ++i)
	{
		game.round();
		game.Generate_new_population();
	}



	for (unsigned long i = 1; i <= 100; ++i)
	{
		game.round();
	}


	std::cout << game.agents.size() << '\n';

	int s = 0;
	for (auto a : game.agents)
	{
		for (unsigned long i = 0; i < a.history.size(); ++i)
		{
			std::cout << a.history.at(i) << ' ';
			if (i >= 180)
			{
    			s += a.history.at(i);
			}

		}
		std::cout << '\n' << '\n';
	}
	std::cout << s/20./N;



	return 0;
}