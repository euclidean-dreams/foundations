#include "Circlet.h"

namespace impresarioUtils {

std::unique_ptr<std::thread> Circlet::begin(std::unique_ptr<Circulable> circulable) {
    auto thread = std::make_unique<std::thread>(circle, move(circulable));
    return thread;
}

std::unique_ptr<std::thread> Circlet::beginTicking(std::unique_ptr<TickingCirculable> circulable) {
    auto thread = std::make_unique<std::thread>(tickingCircle, move(circulable));
    return thread;
}

void Circlet::circle(std::unique_ptr<Circulable> circulable) {
    while (!circulable->finished()) {
        circulable->activate();
    }
}

void Circlet::tickingCircle(std::unique_ptr<TickingCirculable> circulable) {
    while (!circulable->finished()) {
        auto cycleStartTime = getCurrentTime();
        circulable->activate();
        auto totalCycleTime = getElapsedTime(cycleStartTime);
        if (circulable->getTickInterval() > totalCycleTime) {
            sleep(circulable->getTickInterval() - totalCycleTime);
        }
    }
}

}
