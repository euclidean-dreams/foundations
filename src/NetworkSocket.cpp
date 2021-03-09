#include "NetworkSocket.h"

NetworkSocket::NetworkSocket(context_t &context, const string &endpoint, socket_type socketType, bool bind)
        : socket{context, socketType} {
    if (bind) {
        socket.bind(endpoint);
    } else {
        socket.connect(endpoint);
    }
}

void NetworkSocket::setSubscriptionFilter(const string &filter) {
    socket.set(sockopt::subscribe, filter);
}

unique_ptr<multipart_t> NetworkSocket::receive(recv_flags flags) {
    auto message = make_unique<multipart_t>();
    if (message->recv(socket, static_cast<int>(flags))) {
        return message;
    } else {
        return nullptr;
    }
}

unique_ptr<char[]> NetworkSocket::receiveBuffer(recv_flags flags) {
    auto envelope = receive(flags);
    if (!envelope->empty()) {
        auto message = envelope->pop();
        return alignBuffer(message.data(), message.size());
    } else {
        return nullptr;
    }
}

inline unique_ptr<char[]> NetworkSocket::alignBuffer(void *sourceBuffer, int size) {
    auto destinationBuffer = make_unique<char[]>(size);
    memcpy(destinationBuffer.get(), sourceBuffer, size);
    return destinationBuffer;
}

void NetworkSocket::send(multipart_t &message) {
    message.send(socket);
}

socket_ref NetworkSocket::getSocketRef() {
    return socket;
}
