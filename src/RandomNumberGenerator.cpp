#include "RandomNumberGenerator.h"

RandomNumberGenerator::RandomNumberGenerator()
        : generator{static_cast<uint32_t>(system_clock::now().time_since_epoch().count())},
          distribution{0, numeric_limits<int>::max()} {
}

int RandomNumberGenerator::generate(int max) {
    auto randomNumber = distribution(generator);
    return randomNumber % max;
}
