#ifndef IMPRESARIO_UTILS_UNWRAP_H
#define IMPRESARIO_UTILS_UNWRAP_H

#include <ImpresarioSerialization.h>
#include "Parcel.h"

namespace impresarioUtils {

class Unwrap {
public:
    static const ImpresarioSerialization::Axiomology *Axiomology(const Parcel &parcel);

    static const ImpresarioSerialization::Essentia *Essentia(const Parcel &parcel);

    static const ImpresarioSerialization::Glimpse *Glimpse(const Parcel &parcel);

    static const ImpresarioSerialization::Phenomenon *Phenomenon(const Parcel &parcel);
};

class InvalidUnwrapException : public std::logic_error {
public:
    InvalidUnwrapException() : logic_error(
            "attempted to unwrap parcel using a different type than the one indicated by its identifier"
    ) {}
};

}

#endif //IMPRESARIO_UTILS_UNWRAP_H
