#ifndef IMPRESARIO_UTILS_NONCOPYABLE_H
#define IMPRESARIO_UTILS_NONCOPYABLE_H

namespace impresarioUtils {

class NonCopyable {
public:
    NonCopyable(const NonCopyable &) = delete;

    NonCopyable &operator=(const NonCopyable &) = delete;

protected:
    NonCopyable() = default;
};

}

#endif //IMPRESARIO_UTILS_NONCOPYABLE_H
