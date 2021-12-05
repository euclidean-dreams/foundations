#include "ParcelCollection.h"

namespace impresarioUtils {

ParcelCollection::ParcelCollection()
        : parcels{} {

}

void ParcelCollection::pushParcel(std::unique_ptr<const Parcel> parcel) {
    parcels.push_front(move(parcel));
}

bool ParcelCollection::moreParcelsLeft() const {
    return !parcels.empty();
}

std::unique_ptr<const Parcel> ParcelCollection::popParcel() {
    auto result = move(parcels.back());
    parcels.pop_back();
    return result;
}

}
