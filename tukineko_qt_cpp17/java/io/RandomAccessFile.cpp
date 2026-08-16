#include "RandomAccessFile.h"
#include <stdexcept>

namespace java {
namespace io {

RandomAccessFile::RandomAccessFile(const QString& name, const QString& mode)
    : m_file(new QFile(name))
{
    if (mode == "r") {
        m_file->open(QIODevice::ReadOnly);
    } else {
        delete m_file;
        m_file = nullptr;
        throw std::runtime_error("RandomAccessFile: unsupported mode");
    }
}

RandomAccessFile::~RandomAccessFile()
{
    close();
    delete m_file;
}

int RandomAccessFile::read()
{
    if (m_file && m_file->isOpen()) {
        char ch;
        if (m_file->getChar(&ch)) {
            return static_cast<unsigned char>(ch);
        }
    }
    return -1;
}

void RandomAccessFile::seek(int offset)
{
    if (m_file && m_file->isOpen()) {
        m_file->seek(offset);
    }
}

int RandomAccessFile::read(char* bytes, int offset, int len)
{
    if (m_file && m_file->isOpen()) {
        qint64 num = m_file->read(bytes + offset, len);
        return (num <= 0) ? -1 : static_cast<int>(num);
    }
    return -1;
}

qint64 RandomAccessFile::skipBytes(int i)
{
    if (m_file && m_file->isOpen()) {
        qint64 oldPos = m_file->pos();
        m_file->seek(oldPos + i);
        return m_file->pos() - oldPos;
    }
    return 0;
}

void RandomAccessFile::close()
{
    if (m_file) {
        m_file->close();
    }
}

} // namespace io
} // namespace java
