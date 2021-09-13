#ifndef IMPRESARIO_UTILS_PACKET_H
#define IMPRESARIO_UTILS_PACKET_H

#include <memory>
#include <ImpresarioSerialization.h>
#include "NonCopyable.h"
#include "SerializedData.h"
#include "InvalidDeserializationException.h"

namespace impresarioUtils {

class Packet : NonCopyable {
private:
    std::unique_ptr<SerializedData> payload;

public:
    explicit Packet(std::unique_ptr<SerializedData> payload);

    ImpresarioSerialization::Identifier getIdentifier() const;

    const ImpresarioSerialization::DisplaySignal *getDisplaySignal() const;

    const ImpresarioSerialization::FloatMorsel *getFloatMorsel() const;

    const ImpresarioSerialization::FloatArrayMorsel *getFloatArrayMorsel() const;
};

}

#endif //IMPRESARIO_UTILS_PACKET_H
