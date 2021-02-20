#ifndef IMPRESARIO_UTILS_UTILS_H
#define IMPRESARIO_UTILS_UTILS_H

#include <chrono>
#include <memory>
#include <cstring>

using namespace std;
using namespace chrono;

inline uint64_t getCurrentTime() {
    return time_point_cast<microseconds>(high_resolution_clock::now()).time_since_epoch().count();
}

inline unique_ptr<char[]> alignBuffer(void *sourceBuffer, int size) {
    auto destinationBuffer = make_unique<char[]>(size);
    memcpy(destinationBuffer.get(), sourceBuffer, size);
    return destinationBuffer;
}

#endif //IMPRESARIO_UTILS_UTILS_H
