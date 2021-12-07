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

public:
    Arbiter()
            : mutex{},
              arbitable{nullptr} {

    }

    void give(std::unique_ptr<const T> newArbitable) {
        std::unique_lock<std::mutex> lock{mutex};
        arbitable = move(newArbitable);
    }

    std::shared_ptr<const T> take() {
        std::unique_lock<std::mutex> lock{mutex};
        return arbitable;
    }
};

}

#endif //IMPRESARIO_UTILS_ARBITER_H
