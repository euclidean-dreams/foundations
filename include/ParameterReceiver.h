#ifndef IMPRESARIO_UTILS_PARAMETERRECEIVER_H
#define IMPRESARIO_UTILS_PARAMETERRECEIVER_H

#include <memory>
#include "Utils.h"
#include "NetworkSocket.h"
#include "NonCopyable.h"

class ParameterReceiver : NonCopyable {
private:
    std::unique_ptr<NetworkSocket> inputSocket;

public:
    static std::unique_ptr<ParameterReceiver> create(context_t &context, const string &endpoint,
                                                     const string &subscriptionFilter);

    explicit ParameterReceiver(std::unique_ptr<NetworkSocket> inputSocket);

    std::unique_ptr<char[]> receive();

};

#endif //IMPRESARIO_UTILS_PARAMETERRECEIVER_H
