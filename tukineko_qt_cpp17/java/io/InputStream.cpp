#include "InputStream.h"

namespace java {
namespace io {

InputStream::InputStream()
    : m_device(nullptr)
    , m_ownsDevice(false)
    , m_markPos(-1)
{
}

InputStream::InputStream(QIODevice* device)
    : m_device(device)
    , m_ownsDevice(false)
    , m_markPos(-1)
{
}

InputStream::~InputStream()
{
    if (m_ownsDevice && m_device) {
        m_device->close();
        delete m_device;
    }
}

void InputStream::setDevice(QIODevice* device, bool owns)
{
    if (m_ownsDevice && m_device) {
        m_device->close();
        delete m_device;
    }
    m_device = device;
    m_ownsDevice = owns;
}

int InputStream::available()
{
    if (m_device) {
        return static_cast<int>(m_device->bytesAvailable());
    }
    return 0;
}

void InputStream::close()
{
    if (m_device) {
        m_device->close();
    }
}

void InputStream::mark(int readlimit)
{
    Q_UNUSED(readlimit)
    if (m_device && m_device->isSequential()) {
        m_markPos = m_device->pos();
    }
}

bool InputStream::markSupported()
{
    return (m_device != nullptr) && !m_device->isSequential();
}

int InputStream::read()
{
    if (!m_device) {
        throw std::runtime_error("InputStream::read() - no device");
    }
    char ch;
    if (m_device->getChar(&ch)) {
        return static_cast<unsigned char>(ch);
    }
    return -1;
}

int InputStream::read(QByteArray& buf)
{
    return read(buf.data(), 0, buf.size());
}

int InputStream::read(char* b, int off, int len)
{
    if (!m_device) {
        throw std::runtime_error("InputStream::read() - no device");
    }
    qint64 num = m_device->read(b + off, len);
    return (num <= 0) ? -1 : static_cast<int>(num);
}

void InputStream::reset()
{
    if (!m_device) {
        throw IOException();
    }
    if (m_markPos >= 0) {
        m_device->seek(m_markPos);
    }
}

qint64 InputStream::skip(qint64 cnt)
{
    qint64 n = cnt;
    while (n > 0) {
        if (read() == -1)
            return cnt - n;
        n--;
    }
    return cnt - n;
}

InputStream* InputStream::wrap(QIODevice* device)
{
    return new InputStream(device);
}

} // namespace io
} // namespace java
