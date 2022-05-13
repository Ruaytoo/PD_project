#include "Unit_tests.h"

//template <class TestFunc >
void RunTest( void (*func)() , const std::string& test_name ) {
    try {
        func ();
    } catch ( std::runtime_error & e) {
        std::cerr << test_name << " fail: " << e.what () << std::endl;
    }
}

template <class T, class U>
void AssertEqual (T& t, U& u, std::string hint) {
    if (t != u)
    {
        std::string os = "";
        os  = os +  "Assertion failed: " + hint;
        throw std::runtime_error(os);
    }
}

void TestMutation()
{
    std::vector<std::vector<int>> chromosomes = {
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
            {0, 0, 0, 0, 0, 1, 1, 1, 1, 1},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
            {1, 1, 1, 0, 1, 1, 1, 1, 1, 1},
            {0, 1, 0, 1, 0, 1, 0, 1, 0, 1},
            {1, 0, 0, 0, 1, 1, 0, 0, 0, 1}
    };

    std::vector<std::vector<int>> expected = {
            {1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {1, 1, 1, 1, 1, 1, 1, 1, 1, 0},
            {0, 0, 0, 0, 1, 1, 1, 1, 1, 1},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
            {0, 1, 0, 1, 0, 1, 1, 1, 0, 1},
            {1, 0, 0, 0, 1, 1, 0, 1, 0, 1}
    };

    std::vector<int> index = {0, 9, 4, 9, 3, 6, 7};

    for (int i = 0; i < index.size(); i++)
    {

        std::vector<int> chromosome = Mutate(chromosomes[i], index[i]);
        AssertEqual(expected[i], chromosome, std::to_string(i) + " test failed");
    }

    std::cerr << "mutation test ok" << '\n';
}

void TestCrossover()
{
    std::vector<std::vector<int>> first_pair = {
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
            {0, 1, 0, 1, 0, 1, 0, 1, 0, 1},
            {0, 0, 1, 1, 1, 1, 1, 1, 0, 0}
    };

    std::vector<std::vector<int>> second_pair = {
            {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {1, 0, 0, 0, 1, 1, 0, 0, 0, 1},
            {0, 0, 1, 1, 1, 1, 0, 0, 1, 1}
    };

    std::vector<int> index = {5, 5, 2, 10};

    std::vector<std::vector<int>> expected = {
            {0, 0, 0, 0, 0, 1, 1, 1, 1, 1},
            {1, 1, 1, 1, 1, 0, 0, 0, 0, 0},
            {0, 1, 0, 0, 1, 1, 0, 0, 0, 1},
            {0, 0, 1, 1, 1, 1, 1, 1, 0, 0}
    };

    for (int i = 0; i < index.size(); i++)
    {
        std::vector<int> chromosome = Crossover(first_pair[i], second_pair[i],index[i]);
        AssertEqual(expected[i], chromosome, std::to_string(i) + " test failed");
    }

    std::cerr << "Crossover test ok" << '\n';
}

