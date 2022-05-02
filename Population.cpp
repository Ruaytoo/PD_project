#include "Population.h"

Population::Population(int size) : population_size(size)
{
}

int Population::Get_population_size()
{
    return population_size;
}

void Population::Initialize_population()
{
    int i, j;
    int size = Get_population_size();

    for (i = 0; i < size; i++)
    {
        std::vector<int> chromosome;
        for (j = 0; j < 15; j++)
        {
            int random_state = rand() % 2;
            if (random_state % 2 == 0)
            {
                chromosome.push_back(0);
            }
            else
            {
                chromosome.push_back(1);
            }
        }
        population.push_back(chromosome);
    }
}

int Next_step(std::vector<int>& player, std::vector<int>& contestor,
              std::vector<int> player_history , std::vector<int> contestor_history)
{

}

std::vector<int> Update_history(std::vector<int> history, int step)
{

}

int Calculate_score(int player_step, int contestor_step)
{
    if (player_step == 0 && contestor_step == 0)
    {
        return 3;
    }

    if (player_step == 0 && contestor_step == 1)
    {
        return 0;
    }

    if (player_step == 1 && contestor_step == 0)
    {
        return 5;
    }

    if (player_step == 1 && contestor_step == 1)
    {
        return 1;
    }
}

std::map<std::string, int> Game_Iteration(std::vector<int>& player, std::vector<int>& contestor,
                                          std::vector<int> player_history , std::vector<int> contestor_history)
{
    std::map<std::string , int> iteration;
    int player_step = Next_step(player, contestor, player_history, contestor_history);
    int contestor_step = Next_step(contestor, player, contestor_history, player_history);

    int current_score = Calculate_score(player_step, contestor_step);

    iteration["score"] = current_score;
    iteration["player_step"] = player_step;
    iteration["contestor_step"] = contestor_step;

    return iteration;
}

int Play_Game(std::vector<int>& player, std::vector<int>& contestor)
{
    int i, current_score = 0;
    std::vector<int> player_history = {};
    std::vector<int> contestor_history = {};

    for (i = 0; i < 100; i++)
    {
        std::map<std::string, int> iteration_result = Game_Iteration(player, contestor,
                                                                     player_history, contestor_history);
        current_score += iteration_result["score"];
        player_history = Update_history(player_history, iteration_result["player_step"]);
        contestor_history = Update_history(contestor_history, iteration_result["contestor_step"]);
    }

    return current_score;
}

void Population::Competition()
{
    int i, j;
    int size = Get_population_size();

    for (i = 0; i < size; i++)
    {
        int score = 0;

        for (j = 0; j < size; j++)
        {
            if (j != i) {
                score += Play_Game(population[i], population[j]);
            }
        }

        population[i].push_back(score);
    }

    return;
}

