#ifndef IMPRESARIO_UTILS_CIRCLET_H
#define IMPRESARIO_UTILS_CIRCLET_H

#include <thread>
#include "Circulable.h"
#include "TickingCirculable.h"
#include "../Time.h"

namespace impresarioUtils {

class Circlet {
public:
    static std::unique_ptr<std::thread> begin(std::unique_ptr<Circulable> circulable);

    static std::unique_ptr<std::thread> beginTicking(std::unique_ptr<TickingCirculable> circulable);

    static void circle(std::unique_ptr<Circulable> circulable);

    static void tickingCircle(std::unique_ptr<TickingCirculable> circulable);
};

}

#endif //IMPRESARIO_UTILS_CIRCLET_H
