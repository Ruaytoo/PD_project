#pragma once
#include <string>
#include <map>
#include <vector>
#include <iostream>

///агент, для которого хранится история и стратегия
class Agent;

///виртуальный класс стратегии, от которого наследуются отдельные конкретные
///алгоритмы выбора хода
class Strategy {
 public:
  ///функция, делающая выбор, какой ход предпринять
  virtual bool MakeChoice(const std::vector<Agent> &agents,
                          int agent_index) = 0;

  std::map<std::string, float> GetStrategy();

  void SetStrategy(std::string &n, std::map<std::string, float> &p);

  Strategy();
  ///хромосома, в которой хранится алгоритм выбора и 3 последних хода
  std::vector<int> chromosome;

 private:
  std::map<std::string, float> params;
  ///имя стратегии
  std::string name;
};

///стратегия - всегда предавать
class DefectStrategy : public Strategy {
 public:
  bool MakeChoice(const std::vector<Agent> &agents, int agent_index);
};

///стратегия - всегда сотрудничать
class CoopStrategy : public Strategy {
 public:
  bool MakeChoice(const std::vector<Agent> &agents, int agent_index);
};

///стратегия - копирования предыдущего хода противника, по умолчанию первый ход
///- сотрудничать
class TitForTat : public Strategy {
  bool MakeChoice(const std::vector<Agent> &agents, int agent_index);
  ///установить новый начальный ход
  void SetStart(int index, bool choice);

 private:
  int start_strategy1;
  int start_strategy2;
};

///стратегия, делающая выбор на основе 3 последних ходов
class GeneticStrategy : public Strategy {
  bool MakeChoice(const std::vector<Agent> &agents, int agent_index);
};

class DetectiveStrategy : public Strategy {
  bool MakeChoice(const std::vector<Agent> &agents, int agent_index);

  double p = 0.1;
};

///агент, для которого хранится история и стратегия
class Agent {
 public:
  void PrintStrategy();
  ///текущий счет игрока
  float score;
  ///история ходов: четные индексы - ходы противника
  std::vector<int> history;
  ///текущий выбор игрока
  int choice;
  Agent();
  ///указатель, на текущую стратегию игрока
  Strategy *strategy;
  int GetAgent_ID();

 private:
  int Agent_ID;
};
