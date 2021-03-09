#ifndef IMPRESARIO_UTILS_TIME_H
#define IMPRESARIO_UTILS_TIME_H

#include <chrono>

namespace impresarioUtils {

uint64_t getCurrentTime() {
    auto rawTime = std::chrono::time_point_cast<std::chrono::microseconds>(std::chrono::high_resolution_clock::now());
    return rawTime.time_since_epoch().count();
}

uint64_t getElapsedTime(uint64_t initialTime) {
    return getCurrentTime() - initialTime;
}

}

#endif //IMPRESARIO_UTILS_TIME_H
