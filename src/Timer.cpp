#include "Timer.h"

namespace impresarioUtils {

Timer::Timer()
        : startTime{getCurrentTime()} {

}

uint64_t Timer::getTime() const {
    return getElapsedTime(startTime);
}

void Timer::logTime() const {
    LOGGER->info(getTime());
}

}
