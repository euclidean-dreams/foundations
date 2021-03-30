#ifndef IMPRESARIO_UTILS_SERIALIZEDDATA_H
#define IMPRESARIO_UTILS_SERIALIZEDDATA_H

#include <zmq.hpp>
#include <memory>
#include <IdentifierWrapper_generated.h>
#include "NonCopyable.h"

namespace impresarioUtils {

class SerializedData : impresarioUtils::NonCopyable {
private:
    ImpresarioSerialization::Identifier identifier;
    std::unique_ptr<char[]> buffer;

    static std::unique_ptr<char[]> alignBuffer(void *sourceBuffer, int size);

public:
    SerializedData(zmq::message_t &identifierWrapper, zmq::message_t &payload);

    ImpresarioSerialization::Identifier getIdentifier();

    const char *getBuffer();
};

}

#endif //IMPRESARIO_UTILS_SERIALIZEDDATA_H
