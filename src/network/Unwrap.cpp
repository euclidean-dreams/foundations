#include "Unwrap.h"

namespace impresarioUtils {

const ImpresarioSerialization::Axiomology *Unwrap::Axiomology(const Parcel &parcel) {
    if (parcel.getIdentifier() == ImpresarioSerialization::Identifier::axiomology) {
        return ImpresarioSerialization::GetAxiomology(parcel.getBuffer());
    } else {
        throw InvalidUnwrapException();
    }
}

const ImpresarioSerialization::Essentia *Unwrap::Essentia(const Parcel &parcel) {
    if (parcel.getIdentifier() == ImpresarioSerialization::Identifier::essentia) {
        return ImpresarioSerialization::GetEssentia(parcel.getBuffer());
    } else {
        throw InvalidUnwrapException();
    }
}

const ImpresarioSerialization::Glimpse *Unwrap::Glimpse(const Parcel &parcel) {
    if (parcel.getIdentifier() == ImpresarioSerialization::Identifier::glimpse) {
        return ImpresarioSerialization::GetGlimpse(parcel.getBuffer());
    } else {
        throw InvalidUnwrapException();
    }
}

const ImpresarioSerialization::Phenomenon *Unwrap::Phenomenon(const Parcel &parcel) {
    if (parcel.getIdentifier() == ImpresarioSerialization::Identifier::phenomenon) {
        return ImpresarioSerialization::GetPhenomenon(parcel.getBuffer());
    } else {
        throw InvalidUnwrapException();
    }
}
}
