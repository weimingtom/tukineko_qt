#ifndef JAVA_IO_IOEXCEPTION_H
#define JAVA_IO_IOEXCEPTION_H

#include <stdexcept>
#include <QString>

namespace java {
namespace io {

class IOException : public std::runtime_error {
public:
    IOException() : std::runtime_error("IOException") {}
    IOException(const QString& str) : std::runtime_error(str.toStdString()) {}
    IOException(const std::string& str) : std::runtime_error(str) {}
};

} // namespace io
} // namespace java

#endif // JAVA_IO_IOEXCEPTION_H
