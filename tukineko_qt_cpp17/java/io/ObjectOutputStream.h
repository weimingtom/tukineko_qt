#ifndef JAVA_IO_OBJECTOUTPUTSTREAM_H
#define JAVA_IO_OBJECTOUTPUTSTREAM_H

#include "ByteArrayOutputStream.h"
#include <QJsonDocument>
#include <QJsonObject>

// Forward declaration - user should include actual NScripter header
class NScripter;

namespace java {
namespace io {

class ObjectOutputStream {
private:
    ByteArrayOutputStream* m_stream;

public:
    explicit ObjectOutputStream(ByteArrayOutputStream* o);
    ~ObjectOutputStream();

    void writeObject(NScripter* o);
    void flush();
    void close();
};

} // namespace io
} // namespace java

#endif // JAVA_IO_OBJECTOUTPUTSTREAM_H
