#ifndef IMPRESARIO_UTILS_PACKETRECEIVER_H
#define IMPRESARIO_UTILS_PACKETRECEIVER_H

#include "NonCopyable.h"
#include "Packet.h"
#include "PacketCollection.h"
#include "NetworkSocket.h"

namespace impresarioUtils {

class PacketReceiver : NonCopyable {
private:
    std::unique_ptr<NetworkSocket> input;

public:
    explicit PacketReceiver(std::unique_ptr<NetworkSocket> input);

    std::unique_ptr<PacketCollection> receive();
};

}

#endif //IMPRESARIO_UTILS_PACKETRECEIVER_H
