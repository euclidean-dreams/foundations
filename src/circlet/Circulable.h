#ifndef IMPRESARIO_UTILS_CIRCULABLE_H
#define IMPRESARIO_UTILS_CIRCULABLE_H

#include "../NonCopyable.h"

namespace impresarioUtils {

class Circulable : public NonCopyable {
public:
    virtual ~Circulable() = default;

    virtual void activate() = 0;

    virtual bool finished() { return false; };
};

}
#endif //IMPRESARIO_UTILS_CIRCULABLE_H
