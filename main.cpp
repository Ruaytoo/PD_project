#include "game.h"

#define N 10

int main()
{
	strategy strategy;
	game game(N, strategy);
	game.round();
	return 0;
}