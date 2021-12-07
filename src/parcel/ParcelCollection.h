#ifndef IMPRESARIO_UTILS_PARCELCOLLECTION_H
#define IMPRESARIO_UTILS_PARCELCOLLECTION_H

#include <list>
#include <memory>
#include "parcel/Parcel.h"

namespace impresarioUtils {

class ParcelCollection : NonCopyable {
private:
    std::list<std::unique_ptr<const Parcel>> parcels;

public:
    ParcelCollection();

    void pushParcel(std::unique_ptr<const Parcel> parcel);

    bool moreParcelsLeft() const;

    std::unique_ptr<const Parcel> popParcel();
};

}

#endif //IMPRESARIO_UTILS_PARCELCOLLECTION_H
