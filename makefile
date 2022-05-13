all: run

run: main.o game.o payoff.o agent.o strategy.o Unit_tests.o
	c++ -ggdb3 -Wall -Wextra -Wconversion -pedantic main.o game.o payoff.o agent.o strategy.o Unit_tests.o -o run

main.o: main.cpp
	c++ -ggdb3 -Wall -Wextra -Wconversion -pedantic -std=c++11 main.cpp -c

game.o: game.cpp
	c++ -ggdb3 -Wall -Wextra -Wconversion -pedantic -std=c++11 game.cpp -c

payoff.o: payoff.cpp
	c++ -ggdb3 -Wall -Wextra -Wconversion -pedantic -std=c++11 payoff.cpp -c

agent.o: agent.cpp
	c++ -ggdb3 -Wall -Wextra -Wconversion  -pedantic -std=c++11 agent.cpp -c

strategy.o: strategy.cpp
	c++ -ggdb3 -Wall -Wextra -Wconversion -pedantic -std=c++11 strategy.cpp -c

Unit_tests.o: Unit_tests.cpp
	c++ -ggdb3 -Wall -Wextra -Wconversion -pedantic -std=c++11 Unit_tests.cpp -c

clean:
	rm -rf run *.o run