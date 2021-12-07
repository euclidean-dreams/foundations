#ifndef IMPRESARIO_UTILS_NETWORKPROXY_H
#define IMPRESARIO_UTILS_NETWORKPROXY_H

#include <memory>
#include "../NonCopyable.h"
#include "NetworkSocket.h"

namespace impresarioUtils {

class NetworkProxy : NonCopyable {
private:
    std::unique_ptr<NetworkSocket> inputSocket;
    std::unique_ptr<NetworkSocket> outputSocket;

public:
    NetworkProxy(std::unique_ptr<NetworkSocket> inputSocket, std::unique_ptr<NetworkSocket> outputSocket);

    void start();
};

}

#endif //IMPRESARIO_UTILS_NETWORKPROXY_H
