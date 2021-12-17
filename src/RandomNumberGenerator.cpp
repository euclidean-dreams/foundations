#include "RandomNumberGenerator.h"

namespace impresarioUtils {

std::unique_ptr<RandomNumberGenerator> RandomNumberGenerator::instance = nullptr;

RandomNumberGenerator &RandomNumberGenerator::getInstance() {
    return *instance;
}

void RandomNumberGenerator::initialize() {
    if (instance == nullptr) {
        instance = std::unique_ptr<RandomNumberGenerator>(new RandomNumberGenerator());
    } else {
        throw std::logic_error("Attempted to initialize RandomNumberGenerator singleton more than once");
    }
}

RandomNumberGenerator::RandomNumberGenerator()
        : generator{std::random_device{}()},
          distribution{0, std::numeric_limits<int>::max()},
          mutex{} {
}

int RandomNumberGenerator::generateNumber(int exclusive_max) {
    if (exclusive_max <= 0) {
        return 0;
    }
    auto randomNumber = distribution(generator);
    return randomNumber % exclusive_max;
}

int RandomNumberGenerator::generate(int exclusive_max) {
    std::unique_lock<std::mutex> lock{mutex};
    return generateNumber(exclusive_max);
}

float RandomNumberGenerator::generateProportion() {
    std::unique_lock<std::mutex> lock{mutex};
    return static_cast<float>(generateNumber(10000)) / 9999;
}

}
