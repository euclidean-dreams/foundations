#ifndef IMPRESARIO_UTILS_NETWORKPROXY_H
#define IMPRESARIO_UTILS_NETWORKPROXY_H

#include <memory>
#include "NetworkSocket.h"

class NetworkProxy {
private:
    std::unique_ptr<NetworkSocket> inputSocket;
    std::unique_ptr<NetworkSocket> outputSocket;

public:
    NetworkProxy(std::unique_ptr<NetworkSocket> inputSocket, std::unique_ptr<NetworkSocket> outputSocket);

    void start();
};

#endif //IMPRESARIO_UTILS_NETWORKPROXY_H
