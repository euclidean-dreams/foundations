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

    void logTime();
};

}

#endif //IMPRESARIO_UTILS_TIMER_H
