#include "FileInputStream.h"

namespace java {
namespace io {

FileInputStream::FileInputStream(const QString& filename)
    : m_file(new QFile(filename))
{
    m_file->open(QIODevice::ReadOnly);
    setDevice(m_file, true);
}

FileInputStream::FileInputStream(const QFileInfo& file)
    : m_file(new QFile(file.absoluteFilePath()))
{
    m_file->open(QIODevice::ReadOnly);
    setDevice(m_file, true);
}

FileInputStream::~FileInputStream()
{
    close();
}

int FileInputStream::read()
{
    if (m_device && m_device->isOpen()) {
        char ch;
        if (m_device->getChar(&ch)) {
            return static_cast<unsigned char>(ch);
        }
    }
    return -1;
}

int FileInputStream::read(char* bytes, int offset, int length)
{
    if (m_device && m_device->isOpen()) {
        qint64 num = m_device->read(bytes + offset, length);
        return (num <= 0) ? -1 : static_cast<int>(num);
    }
    return -1;
}

void FileInputStream::close()
{
    InputStream::close();
    m_file = nullptr;
}

} // namespace io
} // namespace java
