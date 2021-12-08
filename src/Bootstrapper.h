#ifndef IMPRESARIO_UTILS_BOOTSTRAPPER_H
#define IMPRESARIO_UTILS_BOOTSTRAPPER_H

#include <string>
#include <zmq.hpp>
#include <spdlog/sinks/stdout_color_sinks.h>
#include "Config.h"
#include "Macros.h"
#include "RandomNumberGenerator.h"

namespace impresarioUtils {

class Bootstrapper {
private:
    zmq::context_t context;

public:
    Bootstrapper(std::string &configFilePath, int zmqThreads);

    zmq::context_t &getZmqContext();
};

}

#endif //IMPRESARIO_UTILS_BOOTSTRAPPER_H
