#include "game.h"
#include <ctime>
#include <iostream>

Game::Game(int N, Strategy strategy,
	float cc, float dc, float cd, float dd, float p)
:payoff(cc, dc, cd, dd, p), agents(N, Agent(strategy))
{
}


void Game::round()
{
	std::srand( std::time(nullptr) ) ;
    std::random_shuffle( std::begin(agents), std::end(agents) );
    for( std::size_t i = 0 ; i < agents.size(); i += 2 )
    {
    	agents[i].choice = agents[i].strategy.MakeChoice();
    	agents[i+1].choice 	= agents[i+1].strategy.MakeChoice();
    	payoff.compute_score(agents[i], agents[i+1]);
    }
}