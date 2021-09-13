#include "PacketCollection.h"

namespace impresarioUtils {

PacketCollection::PacketCollection()
        : packets{} {

}

void PacketCollection::pushPacket(std::unique_ptr<const Packet> packet) {
    packets.push_front(move(packet));
}

bool PacketCollection::morePacketsLeft() const {
    return !packets.empty();
}

std::unique_ptr<const Packet> PacketCollection::popPacket() {
    auto result = move(packets.back());
    packets.pop_back();
    return result;
}

}
