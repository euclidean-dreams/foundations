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

int RandomNumberGenerator::generate(int max) {
    std::unique_lock<std::mutex> lock{mutex};
    auto randomNumber = distribution(generator);
    return randomNumber % max;
}

float RandomNumberGenerator::generateProportion() {
    std::unique_lock<std::mutex> lock{mutex};
    return static_cast<float>(generate(1000)) / 1000;
}

}
