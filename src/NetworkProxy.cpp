#include "NetworkProxy.h"

NetworkProxy::NetworkProxy(std::unique_ptr<NetworkSocket> inputSocket, std::unique_ptr<NetworkSocket> outputSocket)
        : inputSocket{move(inputSocket)},
          outputSocket{move(outputSocket)} {

}

void NetworkProxy::start() {
    proxy(inputSocket->getSocketRef(), outputSocket->getSocketRef());
}
