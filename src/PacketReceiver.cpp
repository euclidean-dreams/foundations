#include "PacketReceiver.h"

namespace impresarioUtils {

PacketReceiver::PacketReceiver(std::unique_ptr<impresarioUtils::NetworkSocket> input)
        : input{move(input)} {

}

std::unique_ptr<PacketCollection> PacketReceiver::receive() {
    auto packets = std::make_unique<PacketCollection>();
    auto morePacketsToCollect = true;
    while (morePacketsToCollect) {
        auto serializedData = input->receiveSerializedData(zmq::recv_flags::dontwait);
        if (serializedData != nullptr) {
            auto packet = std::make_unique<Packet>(move(serializedData));
            packets->pushPacket(move(packet));
        } else {
            morePacketsToCollect = false;
        }
    }
    return packets;
}

}
