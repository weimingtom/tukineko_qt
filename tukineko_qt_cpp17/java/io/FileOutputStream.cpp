#include "FileOutputStream.h"

namespace java {
namespace io {

FileOutputStream::FileOutputStream(const QString& filename)
    : m_file(new QFile(filename))
{
    m_file->open(QIODevice::WriteOnly | QIODevice::Truncate);
    setDevice(m_file, true);
}

FileOutputStream::FileOutputStream(const QFileInfo& file)
    : m_file(new QFile(file.absoluteFilePath()))
{
    m_file->open(QIODevice::WriteOnly | QIODevice::Truncate);
    setDevice(m_file, true);
}

FileOutputStream::~FileOutputStream()
{
    close();
}

void FileOutputStream::write(int x)
{
    if (m_device && m_device->isOpen()) {
        char ch = static_cast<char>(x);
        m_device->write(&ch, 1);
    }
}

void FileOutputStream::write(const QByteArray& bytes)
{
    if (m_device && m_device->isOpen()) {
        m_device->write(bytes);
    }
}

void FileOutputStream::write(const char* bytes, int offset, int length)
{
    if (m_device && m_device->isOpen()) {
        m_device->write(bytes + offset, length);
    }
}

void FileOutputStream::close()
{
    OutputStream::close();
    m_file = nullptr;
}

} // namespace io
} // namespace java
