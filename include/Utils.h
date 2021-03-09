#ifndef IMPRESARIO_UTILS_UTILS_H
#define IMPRESARIO_UTILS_UTILS_H

#include <chrono>

using namespace std;
using namespace chrono;

inline uint64_t getCurrentTime() {
    return time_point_cast<microseconds>(high_resolution_clock::now()).time_since_epoch().count();
}

inline uint64_t getElapsedTime(uint64_t initialTime) {
    return getCurrentTime() - initialTime;
}

#endif //IMPRESARIO_UTILS_UTILS_H
