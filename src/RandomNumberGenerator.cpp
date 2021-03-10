#include "RandomNumberGenerator.h"

namespace impresarioUtils {

RandomNumberGenerator::RandomNumberGenerator()
        : generator{getCurrentTime()},
          distribution{0, std::numeric_limits<int>::max()} {
}

int RandomNumberGenerator::generate(int max) {
    auto randomNumber = distribution(generator);
    return randomNumber % max;
}

}
