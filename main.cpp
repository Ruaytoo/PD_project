#include "game.h"

#define N 10

int main()
{
	DefectStrategy strategy;
	game game(N, strategy, 5, 3, 10, 0, 0.1);
	//game.round();
	return 0;
}