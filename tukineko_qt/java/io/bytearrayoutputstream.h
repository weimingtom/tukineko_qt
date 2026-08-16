#ifndef BYTEARRAYOUTPUTSTREAM_H
#define BYTEARRAYOUTPUTSTREAM_H

#include "outputstream.h"

class ByteArrayOutputStream : public OutputStream
{
public:
    ByteArrayOutputStream();
    virtual ~ByteArrayOutputStream();

    void write(int b) override;
    QByteArray toByteArray() const;

private:
    QByteArray m_buffer;
};

#endif // BYTEARRAYOUTPUTSTREAM_H
