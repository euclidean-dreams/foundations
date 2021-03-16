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
    setSubscriptionFilter(std::string_view{filter});
}

void NetworkSocket::setSubscriptionFilter(std::string_view filter) {
    socket.set(zmq::sockopt::subscribe, filter);
}

std::unique_ptr<zmq::multipart_t> NetworkSocket::receive(zmq::recv_flags flags) {
    auto message = std::make_unique<zmq::multipart_t>();
    message->recv(socket, static_cast<int>(flags));
    return message;
}

std::unique_ptr<SerializedData> NetworkSocket::receiveSerializedData(zmq::recv_flags flags) {
    auto envelope = receive(flags);
    if (!envelope->empty()) {
        auto identifierWrapper = envelope->pop();
        auto payload = envelope->pop();
        return std::make_unique<SerializedData>(identifierWrapper, payload);
    } else {
        return nullptr;
    }
}

void NetworkSocket::send(zmq::multipart_t &message) {
    message.send(socket);
}

void NetworkSocket::sendSerializedData(ImpresarioSerialization::Identifier identifier,
                                       flatbuffers::FlatBufferBuilder &messageBuilder) {
    flatbuffers::FlatBufferBuilder identifierWrapperBuilder{};
    auto serializedIdentifier = ImpresarioSerialization::CreateIdentifierWrapper(identifierWrapperBuilder, identifier);
    identifierWrapperBuilder.Finish(serializedIdentifier);
    auto message = std::make_unique<zmq::multipart_t>();
    message->addmem(identifierWrapperBuilder.GetBufferPointer(), identifierWrapperBuilder.GetSize());
    message->addmem(messageBuilder.GetBufferPointer(), messageBuilder.GetSize());
    message->send(socket);
}

zmq::socket_ref NetworkSocket::getSocketRef() {
    return socket;
}

}
