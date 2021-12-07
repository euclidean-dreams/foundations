#ifndef IMPRESARIO_UTILS_PARCELRECEIVER_H
#define IMPRESARIO_UTILS_PARCELRECEIVER_H

#include "../NonCopyable.h"
#include "../network/NetworkSocket.h"
#include "Parcel.h"
#include "ParcelCollection.h"

namespace impresarioUtils {

class ParcelReceiver : NonCopyable {
private:
    std::unique_ptr<NetworkSocket> input;

public:
    explicit ParcelReceiver(std::unique_ptr<NetworkSocket> input);

    std::unique_ptr<ParcelCollection> receive();
};

}

#endif //IMPRESARIO_UTILS_PARCELRECEIVER_H
