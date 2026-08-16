#ifndef JAVA_LANG_INTERRUPTEDEXCEPTION_H
#define JAVA_LANG_INTERRUPTEDEXCEPTION_H

#include <stdexcept>

namespace java {
namespace lang {

class InterruptedException : public std::runtime_error {
public:
    InterruptedException()
        : std::runtime_error("InterruptedException")
    {
    }
};

} // namespace lang
} // namespace java

#endif // JAVA_LANG_INTERRUPTEDEXCEPTION_H
