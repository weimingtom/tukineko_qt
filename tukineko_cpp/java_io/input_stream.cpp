#include "input_stream.h"
#include <QFile>

InputStream::InputStream()
    : m_device(nullptr)
    , m_owned(false)
{
}

InputStream::InputStream(QIODevice* device)
    : m_device(device)
    , m_owned(false)
{
}

InputStream::~InputStream()
{
    if (m_owned && m_device) {
        delete m_device;
    }
}

int InputStream::read()
{
    if (!m_device) return -1;
    if (m_device->isSequential()) {
        char c;
        return m_device->read(&c, 1) == 1 ? static_cast<unsigned char>(c) : -1;
    }
    return m_device->getChar(&m_device) ? 0 : -1;
}

int InputStream::read(QByteArray& buffer, int len)
{
    if (!m_device) return -1;
    QByteArray data = m_device->read(len);
    buffer = data;
    return data.size();
}

int InputStream::read(QByteArray& buffer, int off, int len)
{
    if (!m_device) return -1;
    QByteArray data = m_device->read(len);
    if (data.size() + off > buffer.size()) {
        buffer.resize(data.size() + off);
    }
    for (int i = 0; i < data.size(); ++i) {
        buffer[off + i] = data[i];
    }
    return data.size();
}

long InputStream::skip(long n)
{
    if (!m_device) return 0;
    return m_device->skip(n);
}

int InputStream::available()
{
    if (!m_device) return 0;
    return m_device->bytesAvailable();
}

void InputStream::close()
{
    if (m_device) {
        m_device->close();
    }
}

void InputStream::mark(int readlimit)
{
    // Not supported for sequential devices by default
}

void InputStream::reset()
{
    if (m_device) {
        m_device->reset();
    }
}

bool InputStream::markSupported()
{
    return false;
}

FileInputStream::FileInputStream(const QString& fileName)
{
    QFile* file = new QFile(fileName);
    if (file->open(QIODevice::ReadOnly)) {
        m_device = file;
        m_owned = true;
    } else {
        delete file;
        m_device = nullptr;
    }
}

FileInputStream::FileInputStream(QIODevice* device)
    : InputStream(device)
{
}

FileInputStream::~FileInputStream()
{
}

ByteArrayInputStream::ByteArrayInputStream(const QByteArray& buffer)
    : m_buffer(buffer)
    , m_pos(0)
    , m_markPos(0)
    , m_count(buffer.size())
{
}

ByteArrayInputStream::ByteArrayInputStream(const QByteArray& buffer, int offset, int length)
    : m_buffer(buffer)
    , m_pos(offset)
    , m_markPos(offset)
    , m_count(qMin(offset + length, buffer.size()))
{
}

ByteArrayInputStream::~ByteArrayInputStream()
{
}

int ByteArrayInputStream::read()
{
    if (m_pos >= m_count) return -1;
    return static_cast<unsigned char>(m_buffer[m_pos++]);
}

int ByteArrayInputStream::read(QByteArray& buffer, int off, int len)
{
    if (m_pos >= m_count) return -1;
    int available = m_count - m_pos;
    int actualLen = qMin(len, available);
    for (int i = 0; i < actualLen; ++i) {
        buffer[off + i] = m_buffer[m_pos++];
    }
    return actualLen;
}

long ByteArrayInputStream::skip(long n)
{
    if (m_pos >= m_count) return 0;
    int available = m_count - m_pos;
    int actualSkip = qMin(static_cast<int>(n), available);
    m_pos += actualSkip;
    return actualSkip;
}

void ByteArrayInputStream::reset()
{
    m_pos = m_markPos;
}
