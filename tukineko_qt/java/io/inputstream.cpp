#include "inputstream.h"
#include <QDebug>

InputStream::InputStream()
    : m_pos(0)
{
}

InputStream::~InputStream()
{
}

int InputStream::read(QByteArray& buffer, int offset, int len)
{
    Q_UNUSED(offset);
    Q_UNUSED(len);
    return -1;
}

long InputStream::available()
{
    return m_buffer.size() - m_pos;
}

void InputStream::close()
{
}
