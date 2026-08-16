#include "outputstream.h"

OutputStream::OutputStream()
{
}

OutputStream::~OutputStream()
{
}

void OutputStream::write(const QByteArray& buffer, int offset, int len)
{
    if (len < 0) {
        m_buffer.append(buffer.mid(offset));
    } else {
        m_buffer.append(buffer.mid(offset, len));
    }
}

void OutputStream::flush()
{
}

void OutputStream::close()
{
}
