#ifndef IMPRESARIO_UTILS_PROXY_H
#define IMPRESARIO_UTILS_PROXY_H

#include <memory>
#include "mixin/NonCopyable.h"
#include "network/Socket.h"

namespace network {

class Proxy : mixin::NonCopyable {
private:
    std::unique_ptr<Socket> inputSocket;
    std::unique_ptr<Socket> outputSocket;

public:
    Proxy(std::unique_ptr<Socket> inputSocket, std::unique_ptr<Socket> outputSocket);

    void start();
};

}

#endif //IMPRESARIO_UTILS_PROXY_H
