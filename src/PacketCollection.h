#ifndef IMPRESARIO_UTILS_PACKETCOLLECTION_H
#define IMPRESARIO_UTILS_PACKETCOLLECTION_H

#include <list>
#include <memory>
#include "Packet.h"

namespace impresarioUtils {

class PacketCollection : NonCopyable {
private:
    std::list<std::unique_ptr<const Packet>> packets;

public:
    PacketCollection();

    void pushPacket(std::unique_ptr<const Packet> packet);

    bool morePacketsLeft() const;

    std::unique_ptr<const Packet> popPacket();
};

}

#endif //IMPRESARIO_UTILS_PACKETCOLLECTION_H
