#ifndef JAVA_LANG_NUMBERFORMATEXCEPTION_H
#define JAVA_LANG_NUMBERFORMATEXCEPTION_H

#include <stdexcept>

namespace java {
namespace lang {

class NumberFormatException : public std::runtime_error {
public:
    NumberFormatException()
        : std::runtime_error("NumberFormatException")
    {
    }
};

} // namespace lang
} // namespace java

#endif // JAVA_LANG_NUMBERFORMATEXCEPTION_H
