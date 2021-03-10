#ifndef IMPRESARIO_UTILS_TIME_H
#define IMPRESARIO_UTILS_TIME_H

#include <chrono>

namespace impresarioUtils {

uint64_t getCurrentTime();

uint64_t getElapsedTime(uint64_t initialTime);

}

#endif //IMPRESARIO_UTILS_TIME_H
