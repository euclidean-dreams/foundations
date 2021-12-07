#ifndef IMPRESARIO_UTILS_PARCEL_H
#define IMPRESARIO_UTILS_PARCEL_H

#include <memory>
#include <ImpresarioSerialization.h>
#include "../NonCopyable.h"
#include "../network/SerializedData.h"
#include "../network/InvalidDeserializationException.h"

namespace impresarioUtils {

class Parcel : NonCopyable {
private:
    std::unique_ptr<SerializedData> payload;

public:
    explicit Parcel(std::unique_ptr<SerializedData> payload);

    ImpresarioSerialization::Identifier getIdentifier() const;

    const ImpresarioSerialization::Signalarium *getSignalarium() const;

    const ImpresarioSerialization::Axiomology *getAxiomology() const;

    const ImpresarioSerialization::Phenomenon *getPhenomenon() const;
};

}

#endif //IMPRESARIO_UTILS_PARCEL_H
