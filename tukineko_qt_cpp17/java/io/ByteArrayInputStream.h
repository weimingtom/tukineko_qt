#ifndef JAVA_IO_BYTEARRAYINPUTSTREAM_H
#define JAVA_IO_BYTEARRAYINPUTSTREAM_H

#include "InputStream.h"
#include <QBuffer>

namespace java {
namespace io {

class ByteArrayInputStream : public InputStream {
private:
    QBuffer* m_buffer;

public:
    explicit ByteArrayInputStream(const QByteArray& data);
    ByteArrayInputStream(const QByteArray& data, int off, int len);
    ~ByteArrayInputStream();

    int available() override;
};

} // namespace io
} // namespace java

#endif // JAVA_IO_BYTEARRAYINPUTSTREAM_H
