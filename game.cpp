#include "game.h"

game::game(int N, Strategy strategy,
	float cc, float dc, float cd, float dd, float p)
: payoff(cc, dc, cd, dd, p)
{
	for (int i = 0; i < N; ++i)
	{
		agents[i] = Agent(strategy);
	};
}


/*void game::round()
{
	/*std::srand( std::time(nullptr) ) ;
    std::random_shuffle( std::begin(agents), std::end(agents) ) ;
    for( std::size_t i = 0 ; i < agents.size() - 1 ; i += 2 )
    {
    	agents[i].choice = agents[i].strategy.make_choice();
    	agents[i+1].choice 	= agents[i+1].strategy.make_choice();
    	payoff.compute_score(agents[i], agents[i+1]);
    }
};*/