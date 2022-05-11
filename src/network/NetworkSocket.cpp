#include "NetworkSocket.h"

namespace impresarioUtils {

NetworkSocket::NetworkSocket(
        zmq::context_t &context, const std::string &endpoint, zmq::socket_type socketType,
        bool bind
)
        : socket{context, socketType} {
    if (bind) {
        socket.bind(endpoint);
    } else {
        socket.connect(endpoint);
    }
}

void NetworkSocket::setSubscriptionFilter(ImpresarioSerialization::Identifier identifier) {
    flatbuffers::FlatBufferBuilder identifierWrapperBuilder{};
    auto serializedIdentifier = ImpresarioSerialization::CreateIdentifierWrapper(identifierWrapperBuilder, identifier);
    identifierWrapperBuilder.Finish(serializedIdentifier);
    zmq::const_buffer filter{identifierWrapperBuilder.GetBufferPointer(), identifierWrapperBuilder.GetSize()};
    socket.set(zmq::sockopt::subscribe, filter);
    socket.set(zmq::sockopt::reconnect_ivl, 100);
    socket.set(zmq::sockopt::reconnect_ivl_max, 1000);
}

std::unique_ptr<zmq::multipart_t> NetworkSocket::receive(zmq::recv_flags flags) {
    auto message = std::make_unique<zmq::multipart_t>();
    message->recv(socket, static_cast<int>(flags));
    return message;
}

std::unique_ptr<Parcel> NetworkSocket::receiveParcel(zmq::recv_flags flags) {
    auto envelope = receive(flags);
    if (!envelope->empty()) {
        auto identifierWrapper = envelope->pop();
        auto payload = envelope->pop();
        return std::make_unique<Parcel>(identifierWrapper, payload);
    } else {
        return nullptr;
    }
}

void NetworkSocket::send(zmq::multipart_t &message) {
    message.send(socket);
}

void NetworkSocket::sendParcel(
        ImpresarioSerialization::Identifier identifier,
        flatbuffers::FlatBufferBuilder &messageBuilder
) {
    flatbuffers::FlatBufferBuilder identifierWrapperBuilder{};
    auto serializedIdentifier = ImpresarioSerialization::CreateIdentifierWrapper(identifierWrapperBuilder, identifier);
    identifierWrapperBuilder.Finish(serializedIdentifier);
    auto message = std::make_unique<zmq::multipart_t>();
    message->addmem(identifierWrapperBuilder.GetBufferPointer(), identifierWrapperBuilder.GetSize());
    message->addmem(messageBuilder.GetBufferPointer(), messageBuilder.GetSize());
    message->send(socket);
}

void NetworkSocket::sendParcel(
        std::unique_ptr<Parcel> parcel
) {
    flatbuffers::FlatBufferBuilder identifierWrapperBuilder{};
    auto serializedIdentifier = ImpresarioSerialization::CreateIdentifierWrapper(identifierWrapperBuilder,
                                                                                 parcel->getIdentifier());
    identifierWrapperBuilder.Finish(serializedIdentifier);
    auto message = std::make_unique<zmq::multipart_t>();
    message->addmem(identifierWrapperBuilder.GetBufferPointer(), identifierWrapperBuilder.GetSize());
    message->addmem(parcel->getBuffer(), parcel->size);
    message->send(socket);
}

zmq::socket_ref NetworkSocket::getSocketRef() {
    return socket;
}

}
