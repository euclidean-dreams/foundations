#ifndef IMPRESARIO_UTILS_INVALIDDESERIALIZATIONEXCEPTION_H
#define IMPRESARIO_UTILS_INVALIDDESERIALIZATIONEXCEPTION_H

namespace impresarioUtils {

class InvalidDeserializationException : public std::logic_error {
public:
    InvalidDeserializationException() : logic_error(
            "attempted to deserialize data using a type different than the one indicated by its identifier"
    ) {}
};

}

#endif //IMPRESARIO_UTILS_INVALIDDESERIALIZATIONEXCEPTION_H
