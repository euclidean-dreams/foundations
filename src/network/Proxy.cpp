#include "network/Proxy.h"

namespace network {

Proxy::Proxy(std::unique_ptr<Socket> inputSocket, std::unique_ptr<Socket> outputSocket)
        : inputSocket{move(inputSocket)},
          outputSocket{move(outputSocket)} {

}

void Proxy::start() {
    proxy(inputSocket->getSocketRef(), outputSocket->getSocketRef());
}

}
