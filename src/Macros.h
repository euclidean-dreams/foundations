#ifndef IMPRESARIO_UTILS_MACROS_H
#define IMPRESARIO_UTILS_MACROS_H

#define FMT_HEADER_ONLY
#include <spdlog/spdlog.h>

#define LOGGER_NAME "logger"
#define LOGGER spdlog::get(LOGGER_NAME)
#define LOG_BREAK LOGGER->info("-------")

#endif //IMPRESARIO_UTILS_MACROS_H
