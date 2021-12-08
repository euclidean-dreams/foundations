#include "Unwrap.h"

namespace impresarioUtils {

const ImpresarioSerialization::Axiomology *Unwrap::Axiomology(Parcel &serializedData) {
    if (serializedData.getIdentifier() == ImpresarioSerialization::Identifier::axiomology) {
        return ImpresarioSerialization::GetAxiomology(serializedData.getBuffer());
    } else {
        throw InvalidUnwrapException();
    }
}

const ImpresarioSerialization::Essentia *Unwrap::Essentia(Parcel &serializedData) {
    if (serializedData.getIdentifier() == ImpresarioSerialization::Identifier::essentia) {
        return ImpresarioSerialization::GetEssentia(serializedData.getBuffer());
    } else {
        throw InvalidUnwrapException();
    }
}

const ImpresarioSerialization::Glimpse *Unwrap::Glimpse(Parcel &serializedData) {
    if (serializedData.getIdentifier() == ImpresarioSerialization::Identifier::glimpse) {
        return ImpresarioSerialization::GetGlimpse(serializedData.getBuffer());
    } else {
        throw InvalidUnwrapException();
    }
}

const ImpresarioSerialization::Phenomenon *Unwrap::Phenomenon(Parcel &serializedData) {
    if (serializedData.getIdentifier() == ImpresarioSerialization::Identifier::phenomenon) {
        return ImpresarioSerialization::GetPhenomenon(serializedData.getBuffer());
    } else {
        throw InvalidUnwrapException();
    }
}
}
