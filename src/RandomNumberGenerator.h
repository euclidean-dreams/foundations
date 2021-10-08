#ifndef IMPRESARIO_UTILS_RANDOMNUMBERGENERATOR_H
#define IMPRESARIO_UTILS_RANDOMNUMBERGENERATOR_H

#include <random>
#include "Time.h"
#include "NonCopyable.h"

namespace impresarioUtils {

class RandomNumberGenerator : NonCopyable {
private:
    std::default_random_engine generator;
    std::uniform_int_distribution<int> distribution;

public:
    RandomNumberGenerator();

    int generate(int max);

    float generateProportion();
};

}

#endif //IMPRESARIO_UTILS_RANDOMNUMBERGENERATOR_H
