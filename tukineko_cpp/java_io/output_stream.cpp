#include "output_stream.h"

OutputStream::OutputStream()
    : m_device(nullptr)
    , m_owned(false)
{
}

OutputStream::OutputStream(QIODevice* device)
    : m_device(device)
    , m_owned(false)
{
}

OutputStream::~OutputStream()
{
    if (m_owned && m_device) {
        delete m_device;
    }
}

void OutputStream::write(int b)
{
    if (m_device) {
        char c = static_cast<char>(b);
        m_device->write(&c, 1);
    }
}

void OutputStream::write(const QByteArray& b)
{
    if (m_device) {
        m_device->write(b);
    }
}

void OutputStream::write(const QByteArray& b, int off, int len)
{
    if (m_device) {
        m_device->write(b.mid(off, len));
    }
}

void OutputStream::flush()
{
    if (m_device) {
        m_device->flush();
    }
}

void OutputStream::close()
{
    if (m_device) {
        m_device->close();
    }
}

FileOutputStream::FileOutputStream(const QString& fileName, bool append)
{
    QFile* file = new QFile(fileName);
    QIODevice::OpenMode mode = QIODevice::WriteOnly;
    if (append) mode |= QIODevice::Append;
    
    if (file->open(mode)) {
        m_device = file;
        m_owned = true;
    } else {
        delete file;
        m_device = nullptr;
    }
}

FileOutputStream::FileOutputStream(QIODevice* device)
    : OutputStream(device)
{
}

FileOutputStream::~FileOutputStream()
{
}

ByteArrayOutputStream::ByteArrayOutputStream()
{
}

ByteArrayOutputStream::ByteArrayOutputStream(int size)
{
    m_buffer.reserve(size);
}

ByteArrayOutputStream::~ByteArrayOutputStream()
{
}

void ByteArrayOutputStream::write(int b)
{
    m_buffer.append(static_cast<char>(b));
}

void ByteArrayOutputStream::write(const QByteArray& b, int off, int len)
{
    m_buffer.append(b.mid(off, len));
}

QByteArray ByteArrayOutputStream::toByteArray() const
{
    return m_buffer;
}

QByteArray& ByteArrayOutputStream::getBuffer()
{
    return m_buffer;
}

int ByteArrayOutputStream::size() const
{
    return m_buffer.size();
}

void ByteArrayOutputStream::reset()
{
    m_buffer.clear();
}
