#include "VolitiaPercipient.h"

namespace impresarioUtils {

std::unique_ptr<std::thread> VolitiaPercipient::create(zmq::context_t &context, std::string &endpoint) {
    auto instance = std::make_unique<VolitiaPercipient>(context, endpoint);
    return impresarioUtils::Circlet::begin(move(instance));
}

VolitiaPercipient::VolitiaPercipient(zmq::context_t &context, std::string &endpoint)
        : socket{context, endpoint, zmq::socket_type::sub, false},
          axiomology{std::make_shared<impresarioUtils::Arbiter<const impresarioUtils::Parcel>>()},
          phenomenology{std::make_shared<impresarioUtils::BufferArbiter<const impresarioUtils::Parcel>>()} {
    socket.setSubscriptionFilter(ImpresarioSerialization::Identifier::axiomology);
    socket.setSubscriptionFilter(ImpresarioSerialization::Identifier::phenomenon);

}

void VolitiaPercipient::activate() {
    auto parcel = socket.receiveParcel();
    if (parcel->getIdentifier() == ImpresarioSerialization::Identifier::axiomology) {
        axiomology->give(move(parcel));
    } else if (parcel->getIdentifier() == ImpresarioSerialization::Identifier::phenomenon) {
        phenomenology->give(move(parcel));
    }
}

std::shared_ptr<impresarioUtils::Arbiter<const impresarioUtils::Parcel>> VolitiaPercipient::getAxiomology() {
    return axiomology;
}

std::shared_ptr<impresarioUtils::BufferArbiter<const impresarioUtils::Parcel>> VolitiaPercipient::getPhenomenology() {
    return phenomenology;
}

}
