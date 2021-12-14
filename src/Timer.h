#ifndef IMPRESARIO_UTILS_TIMER_H
#define IMPRESARIO_UTILS_TIMER_H

#include "Time.h"
#include "Macros.h"

namespace impresarioUtils {

class Timer {
private:
    uint64_t startTime;

public:
    Timer();

    uint64_t getTime() const;

    void logTime() const;
};

}

#endif //IMPRESARIO_UTILS_TIMER_H
