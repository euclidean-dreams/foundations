#ifndef IMPRESARIO_UTILS_TIME_H
#define IMPRESARIO_UTILS_TIME_H

#include <chrono>
#include <thread>

namespace impresarioUtils {

uint64_t getCurrentTime();

uint64_t getElapsedTime(uint64_t initialTime);

void sleep(uint64_t microseconds);

}

#endif //IMPRESARIO_UTILS_TIME_H
