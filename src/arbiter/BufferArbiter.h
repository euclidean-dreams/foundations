#ifndef IMPRESARIO_UTILS_BUFFERARBITER_H
#define IMPRESARIO_UTILS_BUFFERARBITER_H

#include <mutex>
#include <memory>
#include <vector>
#include "../NonCopyable.h"

namespace impresarioUtils {

template<class T>
class BufferArbiter : public NonCopyable {
private:
    std::mutex mutex;
    std::unique_ptr<std::vector<std::unique_ptr<const T>>> buffer;

public:
    BufferArbiter()
            : mutex{},
              buffer{std::make_unique<std::vector<std::unique_ptr<const T>>>()} {

    }

    void give(std::unique_ptr<const T> newArbitable) {
        std::unique_lock<std::mutex> lock{mutex};
        buffer->push_back(move(newArbitable));
    }

    std::unique_ptr<std::vector<std::unique_ptr<const T>>> take() {
        std::unique_lock<std::mutex> lock{mutex};
        auto result = move(buffer);
        buffer = std::make_unique<std::vector<std::unique_ptr<const T>>>();
        return result;
    }
};

}
#endif //IMPRESARIO_UTILS_BUFFERARBITER_H
