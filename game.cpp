class game
{
private:
	std::vector<agent> agents;
	payoff payoff;

public:
	game(int N, strategy strategy)
	{
		payoff payoff(5, 3, 10, 0, 0.1);
		for (int i = 0; i < N; ++i)
		{
			agents[i] = agent(strategy);
		};
	};

	void round()
	{
		std::srand( std::time(nullptr) ) ;
	    std::random_shuffle( std::begin(agents), std::end(agents) ) ;
	    for( std::size_t i = 0 ; i < agents.size() - 1 ; i += 2 )
	    {
	    	agents[i].choice = agents[i].strategy.make_choice();
	    	agents[i+1].choice 	= agents[i+1].strategy.make_choice();
	    	payoff.compute_score(agents[i], agents[i+1]);
	    }
	};
};