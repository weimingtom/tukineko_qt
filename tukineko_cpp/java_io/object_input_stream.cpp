#include "object_input_stream.h"

ObjectInputStream::ObjectInputStream(InputStream* in)
    : m_input(in)
{
    // We'll use a buffer for QDataStream
}

ObjectInputStream::~ObjectInputStream()
{
}

int ObjectInputStream::read()
{
    return m_input ? m_input->read() : -1;
}

int ObjectInputStream::read(QByteArray& b, int off, int len)
{
    return m_input ? m_input->read(b, off, len) : -1;
}

int ObjectInputStream::readInt()
{
    if (!m_input) return 0;
    QByteArray buf(4, 0);
    m_input->read(buf, 0, 4);
    
    // Read as big-endian integer
    int result = 0;
    for (int i = 0; i < 4; ++i) {
        result = (result << 8) | (static_cast<unsigned char>(buf[i]));
    }
    return result;
}

bool ObjectInputStream::readBool()
{
    return read() != 0;
}

QString ObjectInputStream::readQString()
{
    int len = readInt();
    if (len <= 0) return QString();
    
    QByteArray data;
    read(data, 0, len);
    
    // Assuming UTF-8 encoding
    return QString::fromUtf8(data);
}

QByteArray ObjectInputStream::readBytes(int len)
{
    QByteArray data;
    read(data, 0, len);
    return data;
}
