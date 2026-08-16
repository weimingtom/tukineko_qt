#include "ByteArrayInputStream.h"

namespace java {
namespace io {

ByteArrayInputStream::ByteArrayInputStream(const QByteArray& data)
    : m_buffer(new QBuffer())
{
    m_buffer->setData(data);
    m_buffer->open(QIODevice::ReadOnly);
    setDevice(m_buffer, true);
}

ByteArrayInputStream::ByteArrayInputStream(const QByteArray& data, int off, int len)
    : m_buffer(new QBuffer())
{
    m_buffer->setData(data.mid(off, len));
    m_buffer->open(QIODevice::ReadOnly);
    setDevice(m_buffer, true);
}

ByteArrayInputStream::~ByteArrayInputStream()
{
    if (m_ownsDevice && m_buffer) {
        m_buffer->close();
        delete m_buffer;
    }
}

int ByteArrayInputStream::available()
{
    if (m_buffer) {
        return static_cast<int>(m_buffer->bytesAvailable());
    }
    return 0;
}

} // namespace io
} // namespace java
