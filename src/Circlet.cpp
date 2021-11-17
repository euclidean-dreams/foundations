#include "Circlet.h"

namespace impresarioUtils {

std::unique_ptr<std::thread> Circlet::begin(std::unique_ptr<Circulable> circulable) {
    auto thread = std::make_unique<std::thread>(circle, move(circulable));
    return thread;
}

void Circlet::circle(std::unique_ptr<Circulable> circulable) {
    while (!circulable->finished()) {
        auto cycleStartTime = getCurrentTime();
        circulable->activate();
        auto totalCycleTime = getElapsedTime(cycleStartTime);
        if (circulable->getTickInterval() > totalCycleTime) {
            std::this_thread::sleep_for(
                    std::chrono::microseconds(circulable->getTickInterval() - totalCycleTime)
            );
        }
    }
}

}
