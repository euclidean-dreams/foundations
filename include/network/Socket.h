#ifndef IMPRESARIO_UTILS_SOCKET_H
#define IMPRESARIO_UTILS_SOCKET_H

#include <cstring>
#include <zmq.hpp>
#include <zmq_addon.hpp>
#include "mixin/NonCopyable.h"

namespace network {

class Socket : mixin::NonCopyable {
private:
    zmq::socket_t socket;

    static inline std::unique_ptr<char[]> alignBuffer(void *sourceBuffer, int size);

public:
    Socket(zmq::context_t &context, const std::string &endpoint, zmq::socket_type socketType, bool bind);

    void setSubscriptionFilter(const std::string &filter);

    std::unique_ptr<zmq::multipart_t> receive(zmq::recv_flags flags = zmq::recv_flags::none);

    std::unique_ptr<char[]> receiveBuffer(zmq::recv_flags flags = zmq::recv_flags::none);

    void send(zmq::multipart_t &message);

    zmq::socket_ref getSocketRef();
};

}

#endif //IMPRESARIO_UTILS_SOCKET_H
