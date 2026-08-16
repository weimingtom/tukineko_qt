#ifndef JAVA_IO_BYTEARRAYOUTPUTSTREAM_H
#define JAVA_IO_BYTEARRAYOUTPUTSTREAM_H

#include "OutputStream.h"
#include <QBuffer>

namespace java {
namespace io {

class ByteArrayOutputStream : public OutputStream {
private:
    QBuffer* m_buffer;

public:
    ByteArrayOutputStream();
    explicit ByteArrayOutputStream(int bufferSize);
    ~ByteArrayOutputStream();

    qint64 size() const;
    QByteArray toByteArray() const;
    void close() override;
};

} // namespace io
} // namespace java

#endif // JAVA_IO_BYTEARRAYOUTPUTSTREAM_H
