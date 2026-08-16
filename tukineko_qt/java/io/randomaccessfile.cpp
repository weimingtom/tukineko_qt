#include "randomaccessfile.h"
#include <QDebug>
#include <QIODevice>

RandomAccessFile::RandomAccessFile(const QString& filename, const QString& mode)
    : m_file(filename)
    , m_mode(mode)
{
    QIODevice::OpenModeFlag flags = QIODevice::NotOpen;
    if (mode.contains('r') && mode.contains('w')) {
        flags = QIODevice::OpenModeFlag::ReadWrite;
    } else if (mode.contains('r')) {
        flags = QIODevice::OpenModeFlag::ReadOnly;
    } else if (mode.contains('w')) {
        flags = (QIODevice::OpenModeFlag) ((int)QIODevice::OpenModeFlag::WriteOnly | (int)QIODevice::OpenModeFlag::Truncate);
    }

    if (!m_file.open(flags)) {
        qDebug() << "Failed to open RandomAccessFile:" << filename;
    }
}

RandomAccessFile::~RandomAccessFile()
{
    close();
}

int RandomAccessFile::read()
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

int RandomAccessFile::read(char* buffer, int offset, int len)
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

long RandomAccessFile::length() const
{
    return m_file.size();
}

long RandomAccessFile::getFilePointer() const
{
    return m_file.pos();
}

void RandomAccessFile::seek(long pos)
{
    if (m_file.isOpen()) {
        m_file.seek(pos);
    }
}

void RandomAccessFile::close()
{
    if (m_file.isOpen()) {
        m_file.close();
    }
}
