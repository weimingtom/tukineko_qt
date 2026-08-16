#include "OutputStream.h"

namespace java {
namespace io {

OutputStream::OutputStream()
    : m_device(nullptr)
    , m_ownsDevice(false)
{
}

OutputStream::OutputStream(QIODevice* device)
    : m_device(device)
    , m_ownsDevice(false)
{
}

OutputStream::~OutputStream()
{
    if (m_ownsDevice && m_device) {
        m_device->close();
        delete m_device;
    }
}

void OutputStream::setDevice(QIODevice* device, bool owns)
{
    if (m_ownsDevice && m_device) {
        m_device->close();
        delete m_device;
    }
    m_device = device;
    m_ownsDevice = owns;
}

void OutputStream::close()
{
    if (m_device) {
        m_device->close();
    }
}

void OutputStream::flush()
{
    if (m_device) {
#if 0 //FIXME:
        m_device->flush();
#endif
    }
}

void OutputStream::write(int b)
{
    if (!m_device) {
        throw std::runtime_error("OutputStream::write() - no device");
    }
    char ch = static_cast<char>(b);
    m_device->write(&ch, 1);
}

void OutputStream::write(const QByteArray& b)
{
    write(b.constData(), 0, b.size());
}

void OutputStream::write(const char* b, int offset, int len)
{
    if (m_device) {
        m_device->write(b + offset, len);
    } else {
        for (int i = 0; i < len; i++) {
            write(b[i + offset]);
        }
    }
}

OutputStream* OutputStream::wrap(QIODevice* device)
{
    return new OutputStream(device);
}

} // namespace io
} // namespace java
