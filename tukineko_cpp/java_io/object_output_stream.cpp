#include "object_output_stream.h"

ObjectOutputStream::ObjectOutputStream(OutputStream* out)
    : m_output(out)
{
}

ObjectOutputStream::~ObjectOutputStream()
{
}

void ObjectOutputStream::write(int b)
{
    if (m_output) {
        m_output->write(b);
    }
}

void ObjectOutputStream::write(const QByteArray& b, int off, int len)
{
    if (m_output) {
        m_output->write(b, off, len);
    }
}

void ObjectOutputStream::writeInt(int val)
{
    if (!m_output) return;
    // Write as big-endian integer
    QByteArray buf(4, 0);
    buf[0] = (val >> 24) & 0xFF;
    buf[1] = (val >> 16) & 0xFF;
    buf[2] = (val >> 8) & 0xFF;
    buf[3] = val & 0xFF;
    m_output->write(buf);
}

void ObjectOutputStream::writeBool(bool val)
{
    write(val ? 1 : 0);
}

void ObjectOutputStream::writeQString(const QString& str)
{
    if (!m_output) return;
    
    QByteArray data = str.toUtf8();
    writeInt(data.size());
    if (!data.isEmpty()) {
        m_output->write(data);
    }
}

void ObjectOutputStream::writeBytes(const QByteArray& bytes)
{
    if (!m_output) return;
    m_output->write(bytes);
}
