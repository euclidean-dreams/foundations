#include "RandomNumberGenerator.h"

namespace impresarioUtils {

RandomNumberGenerator::RandomNumberGenerator()
        : generator{std::random_device{}()},
          distribution{0, std::numeric_limits<int>::max()} {
}

int RandomNumberGenerator::generate(int max) {
    auto randomNumber = distribution(generator);
    return randomNumber % max;
}

}
