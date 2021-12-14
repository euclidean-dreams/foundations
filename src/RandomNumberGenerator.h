#ifndef IMPRESARIO_UTILS_RANDOMNUMBERGENERATOR_H
#define IMPRESARIO_UTILS_RANDOMNUMBERGENERATOR_H

#include <mutex>
#include <random>
#include <memory>
#include "NonCopyable.h"

#define RANDOM impresarioUtils::RandomNumberGenerator::getInstance()

namespace impresarioUtils {

class RandomNumberGenerator : public NonCopyable {
private:
    static std::unique_ptr<RandomNumberGenerator> instance;

    std::mutex mutex;
    std::default_random_engine generator;
    std::uniform_int_distribution<int> distribution;

    RandomNumberGenerator();

    int generateNumber(int exclusive_max);

public:
    static RandomNumberGenerator &getInstance();

    static void initialize();

    int generate(int exclusive_max);

    float generateProportion();
};

}

#endif //IMPRESARIO_UTILS_RANDOMNUMBERGENERATOR_H
