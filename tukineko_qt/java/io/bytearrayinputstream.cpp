#include "bytearrayinputstream.h"

ByteArrayInputStream::ByteArrayInputStream(const QByteArray& buffer)
    : m_buffer(buffer)
    , m_count(0)
{
    m_pos = 0;
}

ByteArrayInputStream::~ByteArrayInputStream()
{
}

int ByteArrayInputStream::read()
{
    if (m_pos >= m_buffer.size()) {
        return -1;
    }
    return static_cast<unsigned char>(m_buffer[m_pos++]);
}

int ByteArrayInputStream::read(QByteArray& buffer, int offset, int len)
{
    int bytesToRead = qMin(len, m_buffer.size() - m_pos);
    for (int i = 0; i < bytesToRead; ++i) {
        buffer[offset + i] = m_buffer[m_pos + i];
    }
    m_pos += bytesToRead;
    return bytesToRead;
}

long ByteArrayInputStream::available()
{
    return m_buffer.size() - m_pos;
}
