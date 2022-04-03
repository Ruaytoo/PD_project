#include "game.h"
#include <random>

#define N 10

int main()
{
	strategy strategy;
	game<int> game(N, strategy);
	return 0;
}