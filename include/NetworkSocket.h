#ifndef IMPRESARIO_UTILS_NETWORKSOCKET_H
#define IMPRESARIO_UTILS_NETWORKSOCKET_H

#include <cstring>
#include <zmq.hpp>
#include <zmq_addon.hpp>
#include "NonCopyable.h"

using namespace std;
using namespace zmq;

class NetworkSocket : NonCopyable {
private:
    socket_t socket;

    static inline unique_ptr<char[]> alignBuffer(void *sourceBuffer, int size);

public:
    NetworkSocket(context_t &context, const string &endpoint, socket_type socketType, bool bind);

    void setSubscriptionFilter(const string &filter);

    unique_ptr<multipart_t> receive(recv_flags flags = recv_flags::none);

    unique_ptr<char[]> receiveBuffer(recv_flags flags = recv_flags::none);

    void send(multipart_t &message);
};

#endif //IMPRESARIO_UTILS_NETWORKSOCKET_H
