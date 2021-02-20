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
    message->recv(socket, static_cast<int>(flags));
    return message;
}

void NetworkSocket::send(multipart_t &message) {
    message.send(socket);
}
