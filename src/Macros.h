#ifndef IMPRESARIO_UTILS_MACROS_H
#define IMPRESARIO_UTILS_MACROS_H

#include <spdlog/spdlog.h>

#define LOGGER_NAME "logger"
#define LOGGER spdlog::get(LOGGER_NAME)

#endif //IMPRESARIO_UTILS_MACROS_H
