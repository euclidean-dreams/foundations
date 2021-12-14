#ifndef IMPRESARIO_UTILS_ARBITER_H
#define IMPRESARIO_UTILS_ARBITER_H

#include <mutex>
#include <memory>
#include "../NonCopyable.h"

namespace impresarioUtils {

template<class T>
class Arbiter : public NonCopyable {
private:
    std::mutex mutex;
    std::shared_ptr<const T> arbitable;
    bool newData;

public:
    Arbiter()
            : mutex{},
              arbitable{nullptr},
              newData{false} {

    }

    void give(std::unique_ptr<const T> newArbitable) {
        std::unique_lock<std::mutex> lock{mutex};
        arbitable = move(newArbitable);
        newData = true;
    }

    std::shared_ptr<const T> take() {
        std::unique_lock<std::mutex> lock{mutex};
        newData = false;
        return arbitable;
    }

    bool newDataAvailable() const {
        return newData;
    }
};

}

#endif //IMPRESARIO_UTILS_ARBITER_H
