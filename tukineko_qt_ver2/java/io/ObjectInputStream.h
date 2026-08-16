#ifndef JAVA_IO_OBJECTINPUTSTREAM_H
#define JAVA_IO_OBJECTINPUTSTREAM_H

#include "ByteArrayInputStream.h"
#include <QJsonDocument>
#include <QJsonObject>

// Forward declaration - user should include actual NScripter header
class NScripter;

namespace java {
namespace io {

class ObjectInputStream {
private:
    ByteArrayInputStream* m_stream;

public:
    explicit ObjectInputStream(ByteArrayInputStream* i);
    ~ObjectInputStream();

    NScripter* readObject();
    void close();
};

} // namespace io
} // namespace java

#endif // JAVA_IO_OBJECTINPUTSTREAM_H
