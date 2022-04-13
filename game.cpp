#include "game.h"
#include <ctime>
#include <iostream>

Game::Game(std::vector<Agent> agents,
	float cc, float dc, float cd, float dd, float p)
:payoff(cc, dc, cd, dd, p), agents(agents)
{
}


void Game::round()
{
	std::srand( std::time(nullptr) ) ;
    std::random_shuffle( std::begin(agents), std::end(agents) );
    for( std::size_t i = 0 ; i < agents.size() - 1; i += 2 )
    {
    	agents[i].choice = agents.at(i).strategy->MakeChoice(agents.at(i).history);
    	agents[i+1].choice 	= agents.at(i+1).strategy->MakeChoice(agents.at(i+1).history);
    	payoff.compute_score(agents[i], agents[i+1]);
    }
}