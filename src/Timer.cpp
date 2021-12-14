#include "Timer.h"

namespace impresarioUtils {

Timer::Timer()
        : startTime{getCurrentTime()} {

}

void Timer::logTime() {
    LOGGER->info(getElapsedTime(startTime));
}

}
