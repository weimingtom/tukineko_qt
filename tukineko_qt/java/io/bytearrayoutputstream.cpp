#include "bytearrayoutputstream.h"

ByteArrayOutputStream::ByteArrayOutputStream()
{
}

ByteArrayOutputStream::~ByteArrayOutputStream()
{
}

void ByteArrayOutputStream::write(int b)
{
    m_buffer.append(static_cast<char>(b));
}

QByteArray ByteArrayOutputStream::toByteArray() const
{
    return m_buffer;
}
