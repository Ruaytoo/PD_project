all: ./objects/run

./objects/run: ./objects/main.o ./objects/game.o ./objects/payoff.o \
			./objects/agent.o ./objects/strategy.o ./objects/Unit_tests.o

			c++ -ggdb3 -Wall -Wextra -Wconversion -pedantic -fsanitize=address\
			 ./objects/main.o ./objects/game.o ./objects/payoff.o ./objects/agent.o\
			  ./objects/strategy.o ./objects/Unit_tests.o -o ./objects/run

./objects/main.o -o: ./src/main.cpp
	c++ -ggdb3 -Wall -Wextra -Wconversion -pedantic -fsanitize=address -std=c++11 -c ./src/main.cpp -o ./objects/main.o

./objects/game.o: ./src/game.cpp
	c++ -ggdb3 -Wall -Wextra -Wconversion -pedantic -fsanitize=address -std=c++11 -c ./src/game.cpp -o ./objects/game.o

./objects/payoff.o: ./src/payoff.cpp
	c++ -ggdb3 -Wall -Wextra -Wconversion -pedantic -fsanitize=address -std=c++11 -c ./src/payoff.cpp -o ./objects/payoff.o

./objects/agent.o: ./src/agent.cpp
	c++ -ggdb3 -Wall -Wextra -Wconversion  -pedantic -fsanitize=address -std=c++11 -c ./src/agent.cpp -o ./objects/agent.o

./objects/strategy.o: ./src/strategy.cpp
	c++ -ggdb3 -Wall -Wextra -Wconversion -pedantic -fsanitize=address -std=c++11 -c ./src/strategy.cpp -o\
	 ./objects/strategy.o

./objects/Unit_tests.o: ./src/Unit_tests.cpp
	c++ -ggdb3 -Wall -Wextra -Wconversion -pedantic -fsanitize=address -std=c++11 -c ./src/Unit_tests.cpp -o\
	./objects/Unit_tests.o

clean:
	rm -rf ./objects/run ./objects/*.o ./objects/run