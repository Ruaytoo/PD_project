#include "game.h"
#include <ctime>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <random>
#include <chrono>  

Game::Game(std::vector<Agent> agents,
	float cc, float dc, float cd, float dd, double p)
:payoff(cc, dc, cd, dd, (float) p), agents(agents)
{
    std::cout << "game created \n";
    std::cout << agents.at(0).score << '\n';
    agents.at(0).history.push_back(0);
    agents.at(1).history.push_back(1);
    std::cout << agents.at(1).history[0] << '\n';
}


void Game::round()
{
    unsigned seed = (unsigned) std::chrono::system_clock::now().time_since_epoch().count();
    shuffle( agents.begin(), agents.end(), std::default_random_engine(seed));
    for( std::size_t i = 0 ; i < agents.size() - 1; i += 2 )
    {
    	agents[i].choice = agents.at(i).strategy->MakeChoice(agents, (int) i);
    	agents[i+1].choice 	= agents.at(i+1).strategy->MakeChoice(agents, (int) i+1);
    	payoff.compute_score(&agents[i], &agents[i+1]);
    }
}