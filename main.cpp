#include "game.h"
#include <iostream>
#define N 9
#define R 10


int main()
{
	Strategy strategy;
	Game game(N, strategy, 5, 3, 10, 0, 0.1);
	for (int i = 1; i <= R; ++i)
		game.round();
	for (int i: game.agents[0].history)
    	std::cout << i << ' ';
	return 0;
}