#include "game.h"
#include <ctime>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <random>
#include <chrono>  

Game::Game(float cc, float dc, float cd, float dd, double p)
:payoff(cc, dc, cd, dd, (float) p)
{
    std::cout << "game created \n";
}


void Game::round()
{
    unsigned seed = (unsigned) std::chrono::system_clock::now().time_since_epoch().count();
    shuffle( agents.begin(), agents.end(), std::default_random_engine(seed) );
    for( std::size_t i = 0 ; i < agents.size() - 1; i += 2 )
    {
    	agents[i].choice = agents.at(i).strategy->MakeChoice(agents, (int) i);
    	agents[i+1].choice 	= agents.at(i+1).strategy->MakeChoice(agents, (int) i+1);
    	payoff.compute_score(&agents[i], &agents[i+1]);
    }
}

std::vector<int> Mutate(std::vector<int>& chromosome)
{
    std::srand(std::time(0));
    int mutation_index = rand() % 64;
    std::vector<int> new_chromosome = chromosome;

    if (rand() % 70 > 68)
    {
        int OldValue = chromosome[mutation_index];
        int NewValue;
        if (OldValue == 0)
        {
            NewValue = 1;
        }
        else
        {
            NewValue = 0;
        }
        new_chromosome[mutation_index] = NewValue;
    }

    return new_chromosome;
}

std::vector<int> Crossover(std::vector<int>& first_chromosome, std::vector<int>& second_chromosome)
{
    std::srand(std::time(0));
    std::vector<int> chromosome;
    int random_state = rand() % first_chromosome.size();

    for (int i = 0; i < random_state; i++)
    {
        chromosome.push_back(first_chromosome[i]);
    }

    for (int i = random_state; i < second_chromosome.size(); i++)
    {
        chromosome.push_back(second_chromosome[i]);
    }

    return chromosome;
}

bool comp_agents(Agent& agent_1, Agent& agent_2)
{
    return agent_1.score < agent_2.score;
}

void Game::Generate_new_population()
{
    std::vector<Agent> new_agents;
    std::sort(agents.begin(), agents.end(), comp_agents);

    /*for (int i = 0; i < agents.size() / 2; i++)
    {
        Agent new_agent = agents[i];
        new_agent.score = 0;
        new_agent.history = {};

        std::vector<int> new_chromosome = Mutate(new_agent.strategy->chromosome);
        new_agent.strategy->chromosome = new_chromosome;

        new_agents.push_back(new_agent);
    }*/

    for (int i = 0; i < agents.size() / 2; i += 1)
    {
        int random_state = rand() % (agents.size()/2);
        Agent agent_1 = agents[random_state];
        random_state = rand() % (agents.size()/2);
        Agent agent_2 = agents[random_state];
        Agent agent = agents[i];

        std::vector<int> first_chromosome = agent_1.strategy->chromosome;
        std::vector<int> second_chromosome = agent_2.strategy->chromosome;

        std::vector<int> new_chromosome = Crossover(first_chromosome, second_chromosome);
        agent.score = 0;
        agent.history = {};
        agent.strategy->chromosome = Mutate(new_chromosome);
        new_agents.push_back(agent);
    }

    for (int i = 0; i < agents.size() / 2; i += 1)
    {
        new_agents.push_back(agents[i]);
    }

    agents = new_agents;
}