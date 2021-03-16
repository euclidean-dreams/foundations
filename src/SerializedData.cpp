#include "SerializedData.h"

namespace impresarioUtils {

SerializedData::SerializedData(zmq::message_t &identifierWrapper, zmq::message_t &payload)
        : identifier{ImpresarioSerialization::GetIdentifierWrapper(identifierWrapper.data())->identifier()},
          buffer{alignBuffer(payload.data(), payload.size())} {

}

std::unique_ptr<char[]> SerializedData::alignBuffer(void *sourceBuffer, int size) {
    auto destinationBuffer = std::make_unique<char[]>(size);
    memcpy(destinationBuffer.get(), sourceBuffer, size);
    return destinationBuffer;
}

ImpresarioSerialization::Identifier SerializedData::getIdentifier() {
    return identifier;
}

const char *SerializedData::getBuffer() {
    return buffer.get();
}

}
