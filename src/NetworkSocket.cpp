#include "NetworkSocket.h"

namespace impresarioUtils {

NetworkSocket::NetworkSocket(zmq::context_t &context, const std::string &endpoint, zmq::socket_type socketType,
                             bool bind)
        : socket{context, socketType} {
    if (bind) {
        socket.bind(endpoint);
    } else {
        socket.connect(endpoint);
    }
}

void NetworkSocket::setSubscriptionFilter(const std::string &filter) {
    socket.set(zmq::sockopt::subscribe, filter);
}

std::unique_ptr<zmq::multipart_t> NetworkSocket::receive(zmq::recv_flags flags) {
    auto message = std::make_unique<zmq::multipart_t>();
    message->recv(socket, static_cast<int>(flags));
    return message;
}

std::unique_ptr<char[]> NetworkSocket::receiveBuffer(zmq::recv_flags flags) {
    auto envelope = receive(flags);
    if (!envelope->empty()) {
        auto message = envelope->pop();
        return alignBuffer(message.data(), message.size());
    } else {
        return nullptr;
    }
}

inline std::unique_ptr<char[]> NetworkSocket::alignBuffer(void *sourceBuffer, int size) {
    auto destinationBuffer = std::make_unique<char[]>(size);
    memcpy(destinationBuffer.get(), sourceBuffer, size);
    return destinationBuffer;
}

void NetworkSocket::send(zmq::multipart_t &message) {
    message.send(socket);
}

zmq::socket_ref NetworkSocket::getSocketRef() {
    return socket;
}

}
