#ifndef PERFORMER_RANDOMNUMBERGENERATOR_H
#define PERFORMER_RANDOMNUMBERGENERATOR_H

#include <random>
#include "utils/Time.h"

namespace utils {

class RandomNumberGenerator {
private:
    std::default_random_engine generator;
    std::uniform_int_distribution<int> distribution;

public:
    RandomNumberGenerator();

    int generate(int max);
};

}

#endif //PERFORMER_RANDOMNUMBERGENERATOR_H
