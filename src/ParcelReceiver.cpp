#include "ParcelReceiver.h"

namespace impresarioUtils {

ParcelReceiver::ParcelReceiver(std::unique_ptr<impresarioUtils::NetworkSocket> input)
        : input{move(input)} {

}

std::unique_ptr<ParcelCollection> ParcelReceiver::receive() {
    auto parcels = std::make_unique<ParcelCollection>();
    auto moreParcelsToCollect = true;
    while (moreParcelsToCollect) {
        auto serializedData = input->receiveSerializedData(zmq::recv_flags::dontwait);
        if (serializedData != nullptr) {
            auto parcel = std::make_unique<Parcel>(move(serializedData));
            parcels->pushParcel(move(parcel));
        } else {
            moreParcelsToCollect = false;
        }
    }
    return parcels;
}

}
