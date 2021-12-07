#ifndef IMPRESARIO_UTILS_NETWORKSOCKET_H
#define IMPRESARIO_UTILS_NETWORKSOCKET_H

#include <string_view>
#include <zmq.hpp>
#include <zmq_addon.hpp>
#include <ImpresarioSerialization.h>
#include "../NonCopyable.h"
#include "SerializedData.h"

namespace impresarioUtils {

class NetworkSocket : NonCopyable {
private:
    zmq::socket_t socket;

public:
    NetworkSocket(zmq::context_t &context, const std::string &endpoint, zmq::socket_type socketType, bool bind);

    void setSubscriptionFilter(ImpresarioSerialization::Identifier identifier);

    std::unique_ptr<zmq::multipart_t> receive(zmq::recv_flags flags = zmq::recv_flags::none);

    std::unique_ptr<SerializedData> receiveSerializedData(zmq::recv_flags flags = zmq::recv_flags::none);

    void send(zmq::multipart_t &message);

    void sendSerializedData(ImpresarioSerialization::Identifier identifier,
                            flatbuffers::FlatBufferBuilder &messageBuilder);

    zmq::socket_ref getSocketRef();
};

}

#endif //IMPRESARIO_UTILS_NETWORKSOCKET_H
