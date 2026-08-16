#include "fileinputstream.h"
#include <QDebug>

FileInputStream::FileInputStream(const QString& filename)
    : m_file(filename)
{
    if (!m_file.open(QIODevice::ReadOnly)) {
        qDebug() << "Failed to open file for reading:" << filename;
    }
}

FileInputStream::~FileInputStream()
{
    m_file.close();
}

int FileInputStream::read()
{
    if (!m_file.isOpen()) {
        return -1;
    }
    char c;
    if (m_file.read(&c, 1) == 1) {
        return static_cast<unsigned char>(c);
    }
    return -1;
}

int FileInputStream::read(QByteArray& buffer, int offset, int len)
{
    if (!m_file.isOpen()) {
        return -1;
    }
    QByteArray data = m_file.read(len);
    int bytesRead = data.size();
    for (int i = 0; i < bytesRead; ++i) {
        buffer[offset + i] = data[i];
    }
    return bytesRead;
}

long FileInputStream::available()
{
    if (!m_file.isOpen()) {
        return 0;
    }
    return m_file.bytesAvailable();
}

void FileInputStream::close()
{
    if (m_file.isOpen()) {
        m_file.close();
    }
}
