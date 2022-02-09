#ifndef IMPRESARIO_UTILS_MACROS_H
#define IMPRESARIO_UTILS_MACROS_H

#include <spdlog/spdlog.h>

#define LOGGER_NAME "logger"
#define LOGGER spdlog::get(LOGGER_NAME)
#define LOG_BREAK LOGGER->info("-------")

#endif //IMPRESARIO_UTILS_MACROS_H
