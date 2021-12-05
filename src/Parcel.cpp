#include "Parcel.h"

namespace impresarioUtils {

Parcel::Parcel(std::unique_ptr<SerializedData> payload)
        : payload{move(payload)} {

}

ImpresarioSerialization::Identifier Parcel::getIdentifier() const {
    return payload->getIdentifier();
}

const ImpresarioSerialization::Signalarium *Parcel::getSignalarium() const {
    if (getIdentifier() == ImpresarioSerialization::Identifier::signalarium) {
        return ImpresarioSerialization::GetSignalarium(payload->getBuffer());
    } else {
        throw InvalidDeserializationException();
    }
}

const ImpresarioSerialization::Axiomology *Parcel::getAxiomology() const {
    if (getIdentifier() == ImpresarioSerialization::Identifier::axiomology) {
        return ImpresarioSerialization::GetAxiomology(payload->getBuffer());
    } else {
        throw InvalidDeserializationException();
    }
}

const ImpresarioSerialization::Phenomenon *Parcel::getPhenomenon() const {
    if (getIdentifier() == ImpresarioSerialization::Identifier::phenomenon) {
        return ImpresarioSerialization::GetPhenomenon(payload->getBuffer());
    } else {
        throw InvalidDeserializationException();
    }
}

}
