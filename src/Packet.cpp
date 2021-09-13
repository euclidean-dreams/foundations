#include "Packet.h"

namespace impresarioUtils {

Packet::Packet(std::unique_ptr<SerializedData> payload)
        : payload{move(payload)} {

}

ImpresarioSerialization::Identifier Packet::getIdentifier() const {
    return payload->getIdentifier();
}

const ImpresarioSerialization::DisplaySignal *Packet::getDisplaySignal() const {
    if (getIdentifier() == ImpresarioSerialization::Identifier::displaySignal) {
        return ImpresarioSerialization::GetDisplaySignal(payload->getBuffer());
    } else {
        throw InvalidDeserializationException();
    }
}

const ImpresarioSerialization::FloatMorsel *Packet::getFloatMorsel() const {
    if (getIdentifier() == ImpresarioSerialization::Identifier::floatMorsel) {
        return ImpresarioSerialization::GetFloatMorsel(payload->getBuffer());
    } else {
        throw InvalidDeserializationException();
    }
}

const ImpresarioSerialization::FloatArrayMorsel *Packet::getFloatArrayMorsel() const {
    if (getIdentifier() == ImpresarioSerialization::Identifier::floatArrayMorsel) {
        return ImpresarioSerialization::GetFloatArrayMorsel(payload->getBuffer());
    } else {
        throw InvalidDeserializationException();
    }
}

}
