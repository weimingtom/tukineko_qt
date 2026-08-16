#include "fileoutputstream.h"
#include <QDebug>

FileOutputStream::FileOutputStream(const QString& filename)
    : m_file(filename)
{
    if (!m_file.open(QIODevice::WriteOnly | QIODevice::Truncate)) {
        qDebug() << "Failed to open file for writing:" << filename;
    }
}

FileOutputStream::~FileOutputStream()
{
    close();
}

void FileOutputStream::write(int b)
{
    if (m_file.isOpen()) {
        char c = static_cast<char>(b);
        m_file.write(&c, 1);
    }
}

void FileOutputStream::flush()
{
    if (m_file.isOpen()) {
        m_file.flush();
    }
}

void FileOutputStream::close()
{
    if (m_file.isOpen()) {
        m_file.write(m_buffer);
        m_buffer.clear();
        m_file.flush();
        m_file.close();
    }
}
