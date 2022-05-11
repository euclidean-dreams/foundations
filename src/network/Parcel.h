#ifndef IMPRESARIO_UTILS_PARCEL_H
#define IMPRESARIO_UTILS_PARCEL_H

#include <zmq.hpp>
#include <memory>
#include <ImpresarioSerialization.h>
#include "../NonCopyable.h"

namespace impresarioUtils {

class Parcel : NonCopyable {
private:
    ImpresarioSerialization::Identifier identifier;
    std::unique_ptr<char[]> buffer;

    static std::unique_ptr<char[]> alignBuffer(void *sourceBuffer, int size);

public:
    size_t size;

    Parcel(zmq::message_t &identifierWrapper, zmq::message_t &payload);

    ImpresarioSerialization::Identifier getIdentifier() const;

    const char *getBuffer() const;
};

}

#endif //IMPRESARIO_UTILS_PARCEL_H
