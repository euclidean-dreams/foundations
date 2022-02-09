#include "VolitiaPercipient.h"

namespace impresarioUtils {

std::unique_ptr<std::thread> VolitiaPercipient::create(zmq::context_t &context, std::string endpoint,
                                                       std::shared_ptr<impresarioUtils::Arbiter<const impresarioUtils::Parcel>> axiomology,
                                                       std::shared_ptr<impresarioUtils::BufferArbiter<const impresarioUtils::Parcel>> phenomenology) {
    auto instance = std::make_unique<VolitiaPercipient>(context, endpoint, move(axiomology), move(phenomenology));
    return impresarioUtils::Circlet::begin(move(instance));
}

VolitiaPercipient::VolitiaPercipient(zmq::context_t &context, std::string endpoint,
                                     std::shared_ptr<impresarioUtils::Arbiter<const impresarioUtils::Parcel>> axiomology,
                                     std::shared_ptr<impresarioUtils::BufferArbiter<const impresarioUtils::Parcel>> phenomenology)
        : socket{context, endpoint, zmq::socket_type::sub, false},
          axiomology{move(axiomology)},
          phenomenology{move(phenomenology)} {
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

}
