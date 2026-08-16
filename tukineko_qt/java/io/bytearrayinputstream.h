#ifndef BYTEARRAYINPUTSTREAM_H
#define BYTEARRAYINPUTSTREAM_H

#include "inputstream.h"

class ByteArrayInputStream : public InputStream
{
public:
    ByteArrayInputStream(const QByteArray& buffer);
    virtual ~ByteArrayInputStream();

    int read() override;
    int read(QByteArray& buffer, int offset, int len) override;
    long available() override;

private:
    QByteArray m_buffer;
    int m_count;
};

#endif // BYTEARRAYINPUTSTREAM_H
