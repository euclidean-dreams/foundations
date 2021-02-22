#ifndef PERFORMER_RANDOMNUMBERGENERATOR_H
#define PERFORMER_RANDOMNUMBERGENERATOR_H

#include <random>
#include <chrono>

using namespace std;
using namespace chrono;

class RandomNumberGenerator {
private:
    default_random_engine generator;
    uniform_int_distribution<int> distribution;

public:
    RandomNumberGenerator();

    int generate(int max);
};

#endif //PERFORMER_RANDOMNUMBERGENERATOR_H
