#pragma once
#include <vector>
#include <random>
#include "payoff.h"
#include "strategy.h"

///класс игры с реализаций итераций и генерацией новой популяции
class Game
{
private:
  ///задаваемая матрица счета
  Payoff payoff;

public:
  ///вектор игроков
  std::vector < Agent > agents;
  Game (float cc, float dc, float cd, float dd, double p);
  ///одна игровая итерация
  void round ();
  ///эволюция агентов
  void Generate_new_population ();
};

///мутации хромосом
std::vector < int >
Mutate (std::vector < int >&chromosome, unsigned int mutation_index = 100);

///кросинговер между 2мя хромосомама
std::vector < int >
Crossover (std::vector < int >&first_chromosome,
	   std::vector < int >&second_chromosome, unsigned int random_state =
	   100);

///линейный порядок на множестве агентов
bool comp_agents (Agent & agent_1, Agent & agent_2);
