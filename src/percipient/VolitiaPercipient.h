#ifndef IMPRESARIO_UTILS_VOLITIAPERCIPIENT_H
#define IMPRESARIO_UTILS_VOLITIAPERCIPIENT_H

#include <thread>
#include "../circlet/Circulable.h"
#include "../circlet/Circlet.h"
#include "../network/NetworkSocket.h"
#include "../arbiter/Arbiter.h"
#include "../arbiter/BufferArbiter.h"

namespace impresarioUtils {

class VolitiaPercipient : public impresarioUtils::Circulable {
private:
    impresarioUtils::NetworkSocket socket;
    std::shared_ptr<impresarioUtils::Arbiter<const impresarioUtils::Parcel>> axiomology;
    std::shared_ptr<impresarioUtils::BufferArbiter<const impresarioUtils::Parcel>> phenomenology;

public:
    static std::unique_ptr<std::thread> create(zmq::context_t &context, std::string endpoint,
                                               std::shared_ptr<impresarioUtils::Arbiter<const impresarioUtils::Parcel>> axiomology,
                                               std::shared_ptr<impresarioUtils::BufferArbiter<const impresarioUtils::Parcel>> phenomenology);

    VolitiaPercipient(zmq::context_t &context, std::string endpoint,
                      std::shared_ptr<impresarioUtils::Arbiter<const impresarioUtils::Parcel>> axiomology,
                      std::shared_ptr<impresarioUtils::BufferArbiter<const impresarioUtils::Parcel>> phenomenology);

    void activate() override;

};

}

#endif //IMPRESARIO_UTILS_VOLITIAPERCIPIENT_H
