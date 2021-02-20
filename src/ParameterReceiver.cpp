#include "ParameterReceiver.h"

std::unique_ptr<ParameterReceiver> ParameterReceiver::create(context_t &context, const string &endpoint,
                                                             const string &subscriptionFilter) {
    auto input = make_unique<NetworkSocket>(context, endpoint, socket_type::sub, false);
    input->setSubscriptionFilter(subscriptionFilter);
    return make_unique<ParameterReceiver>(move(input));
}

ParameterReceiver::ParameterReceiver(std::unique_ptr<NetworkSocket> inputSocket) : inputSocket{move(inputSocket)} {}

std::unique_ptr<char[]> ParameterReceiver::receive() {
    auto envelope = inputSocket->receive(recv_flags::dontwait);
    if (!envelope->empty()) {
        auto message = envelope->pop();
        return alignBuffer(message.data(), message.size());
    } else {
        return nullptr;
    }
}
