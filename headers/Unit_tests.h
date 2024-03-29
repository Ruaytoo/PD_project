#pragma once
#include "game.h"
#include <vector>
#include <stdexcept>
#include <sstream>
#include <string>

void RunTest(void (*func)(), const std::string& test_name);

template <class T, class U>
void AssertEqual(T& t, U& u, std::string hint);

void TestMutation();

void TestCrossover();

void TestGeneratePopulation();

void TestUpdateScore();
