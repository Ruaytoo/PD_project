#include "game.h"
#include <iostream>
#define N 9
#define R 3


int main()
{
	TitForTat strategy;
	std::vector<Agent> agents(N, &strategy);
	Game game(agents, 5, 3, 10, 0, 0.0);
	for (int i = 1; i <= R; ++i)
		game.round();
	std::cout << game.agents[0].history[0] << ' ' ;
	for (int i: game.agents[0].history)
    	std::cout << i << ' ';
	return 0;
}