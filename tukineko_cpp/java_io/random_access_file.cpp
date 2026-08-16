#include "random_access_file.h"

RandomAccessFile::RandomAccessFile(const QString& name, const QString& mode)
{
    QIODevice::OpenMode flags;
    if (mode.contains('r') && mode.contains('w')) {
        flags = QIODevice::ReadWrite;
    } else if (mode.contains('w')) {
        flags = QIODevice::WriteOnly | QIODevice::Truncate;
    } else {
        flags = QIODevice::ReadOnly;
    }
    m_file.setFileName(name);
    m_file.open(flags);
}

RandomAccessFile::~RandomAccessFile()
{
    if (m_file.isOpen()) {
        m_file.close();
    }
}

int RandomAccessFile::read()
{
    if (!m_file.isOpen()) return -1;
    char c;
    return m_file.read(&c, 1) == 1 ? static_cast<unsigned char>(c) : -1;
}

int RandomAccessFile::read(QByteArray& b, int off, int len)
{
    if (!m_file.isOpen()) return -1;
    QByteArray data = m_file.read(len);
    for (int i = 0; i < data.size() && off + i < b.size(); ++i) {
        b[off + i] = data[i];
    }
    return data.size();
}

void RandomAccessFile::write(int b)
{
    if (m_file.isOpen()) {
        char c = static_cast<char>(b);
        m_file.write(&c, 1);
    }
}

void RandomAccessFile::write(const QByteArray& b, int off, int len)
{
    if (m_file.isOpen()) {
        m_file.write(b.mid(off, len));
    }
}

void RandomAccessFile::seek(long pos)
{
    if (m_file.isOpen()) {
        m_file.seek(pos);
    }
}

long RandomAccessFile::getFilePointer()
{
    return m_file.isOpen() ? m_file.pos() : 0;
}

long RandomAccessFile::length()
{
    return m_file.isOpen() ? m_file.size() : 0;
}

void RandomAccessFile::close()
{
    if (m_file.isOpen()) {
        m_file.close();
    }
}
