#ifndef IMPRESARIO_UTILS_TICKINGCIRCULABLE_H
#define IMPRESARIO_UTILS_TICKINGCIRCULABLE_H

#include <cstdint>
#include "Circulable.h"

namespace impresarioUtils {

class TickingCirculable : public Circulable {
public:
    virtual ~TickingCirculable() = default;

    virtual uint64_t getTickInterval() = 0;
};

}
#endif //IMPRESARIO_UTILS_TICKINGCIRCULABLE_H
