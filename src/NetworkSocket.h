#ifndef IMPRESARIO_UTILS_NETWORKSOCKET_H
#define IMPRESARIO_UTILS_NETWORKSOCKET_H

#include <zmq.hpp>
#include <zmq_addon.hpp>
#include "NonCopyable.h"

using namespace std;
using namespace zmq;

class NetworkSocket : NonCopyable {
private:
    socket_t socket;

public:
    NetworkSocket(context_t &context, const string &endpoint, socket_type socketType, bool bind);

    void setSubscriptionFilter(const string &filter);

    unique_ptr<multipart_t> receive(recv_flags flags = recv_flags::none);

    void send(multipart_t &message);
};

#endif //IMPRESARIO_UTILS_NETWORKSOCKET_H
