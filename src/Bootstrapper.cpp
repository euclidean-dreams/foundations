#include "Bootstrapper.h"

namespace impresarioUtils {

Bootstrapper::Bootstrapper(std::string &configFilePath, int zmqThreads)
        : context{zmqThreads} {
    Config::initialize(configFilePath);
    RandomNumberGenerator::initialize();
    spdlog::stdout_color_mt(LOGGER_NAME);
}

zmq::context_t &Bootstrapper::getZmqContext() {
    return context;
}

}
