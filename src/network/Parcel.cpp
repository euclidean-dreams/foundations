#include "Parcel.h"

namespace impresarioUtils {

Parcel::Parcel(zmq::message_t &identifierWrapper, zmq::message_t &payload)
        : identifier{ImpresarioSerialization::GetIdentifierWrapper(identifierWrapper.data())->identifier()},
          buffer{alignBuffer(payload.data(), payload.size())},
          size{payload.size()} {

}

std::unique_ptr<char[]> Parcel::alignBuffer(void *sourceBuffer, int size) {
    auto destinationBuffer = std::make_unique<char[]>(size);
    memcpy(destinationBuffer.get(), sourceBuffer, size);
    return destinationBuffer;
}

ImpresarioSerialization::Identifier Parcel::getIdentifier() const {
    return identifier;
}

const char *Parcel::getBuffer() const {
    return buffer.get();
}

}
