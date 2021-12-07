#ifndef IMPRESARIO_UTILS_CIRCULABLE_H
#define IMPRESARIO_UTILS_CIRCULABLE_H

#include "NonCopyable.h"

namespace impresarioUtils {

class Circulable : public impresarioUtils::NonCopyable {
public:
    virtual ~Circulable() = default;

    virtual void activate() = 0;

    virtual uint64_t getTickInterval() = 0;

    virtual bool finished() = 0;
};

}
#endif //IMPRESARIO_UTILS_CIRCULABLE_H
