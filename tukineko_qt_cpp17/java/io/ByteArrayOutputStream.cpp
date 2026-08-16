#include "ByteArrayOutputStream.h"

namespace java {
namespace io {

ByteArrayOutputStream::ByteArrayOutputStream()
    : m_buffer(new QBuffer())
{
    m_buffer->open(QIODevice::WriteOnly);
    setDevice(m_buffer, true);
}

ByteArrayOutputStream::ByteArrayOutputStream(int bufferSize)
    : m_buffer(new QBuffer())
{
    m_buffer->setBuffer(new QByteArray(bufferSize, 0));
    m_buffer->open(QIODevice::WriteOnly);
    setDevice(m_buffer, true);
}

ByteArrayOutputStream::~ByteArrayOutputStream()
{
    if (m_ownsDevice && m_buffer) {
        m_buffer->close();
        delete m_buffer;
    }
}

qint64 ByteArrayOutputStream::size() const
{
    if (m_buffer) {
        return m_buffer->size();
    }
    return 0;
}

QByteArray ByteArrayOutputStream::toByteArray() const
{
    if (m_buffer) {
        return m_buffer->data();
    }
    return QByteArray();
}

void ByteArrayOutputStream::close()
{
    // ByteArrayOutputStream close does nothing in Java
}

} // namespace io
} // namespace java
