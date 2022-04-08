all: run

run: main.o game.o payoff.o agent.o strategy.o
	c++ main.o game.o payoff.o agent.o strategy.o -o run

main.o: main.cpp
	c++ main.cpp -c

game.o: game.cpp
	c++ game.cpp -c

payoff.o: payoff.cpp
	c++ payoff.cpp -c

agent.o: agent.cpp
	c++ agent.cpp -c

strategy.o: strategy.cpp
	c++ strategy.cpp -c

clean:
	rm -rf run *.o run