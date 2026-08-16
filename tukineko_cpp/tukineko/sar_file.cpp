#include "sar_file.h"
#include "../java_io/file_input_stream.h"
#include <QDebug>

SarFile::SarFile()
    : m_isOpen(false)
    , m_stream(nullptr)
{
}

SarFile::SarFile(const QString& filename)
    : m_isOpen(false)
    , m_stream(nullptr)
{
    open(filename);
}

SarFile::~SarFile()
{
    close();
}

bool SarFile::open(const QString& filename)
{
    if (m_isOpen) {
        close();
    }
    
    if (!File_::exists(filename)) {
        qDebug() << "SAR file not found:" << filename;
        return false;
    }
    
    m_filename = filename;
    m_stream = new FileInputStream(filename);
    
    try {
        readIndex();
        m_isOpen = true;
        qDebug() << "Opened SAR archive:" << filename << "with" << m_entries.size() << "entries";
        return true;
    } catch (...) {
        qDebug() << "Failed to read SAR index";
        delete m_stream;
        m_stream = nullptr;
        return false;
    }
}

void SarFile::close()
{
    if (m_stream) {
        m_stream->close();
        delete m_stream;
        m_stream = nullptr;
    }
    m_entries.clear();
    m_isOpen = false;
}

void SarFile::readIndex()
{
    if (!m_stream) return;
    
    // SAR format: simple archive with index
    // Index is stored at the end of the file
    
    // Read entries
    while (m_stream->available() > 0) {
        // Read name length (4 bytes)
        QByteArray lenBuf(4, 0);
        m_stream->read(lenBuf, 0, 4);
        int nameLen = ((unsigned char)lenBuf[0] << 24) |
                      ((unsigned char)lenBuf[1] << 16) |
                      ((unsigned char)lenBuf[2] << 8) |
                      ((unsigned char)lenBuf[3]);
        
        if (nameLen <= 0 || nameLen > 256) break;
        
        // Read name
        QByteArray nameBuf(nameLen, 0);
        m_stream->read(nameBuf, 0, nameLen);
        QString name = QString::fromLatin1(nameBuf);
        
        SarEntry entry;
        entry.name = name;
        
        // Read data offset (4 bytes)
        QByteArray offBuf(4, 0);
        m_stream->read(offBuf, 0, 4);
        entry.offset = ((unsigned char)offBuf[0] << 24) |
                       ((unsigned char)offBuf[1] << 16) |
                       ((unsigned char)offBuf[2] << 8) |
                       ((unsigned char)offBuf[3]);
        
        // Read length (4 bytes)
        QByteArray len2Buf(4, 0);
        m_stream->read(len2Buf, 0, 4);
        entry.length = ((unsigned char)len2Buf[0] << 24) |
                       ((unsigned char)len2Buf[1] << 16) |
                       ((unsigned char)len2Buf[2] << 8) |
                       ((unsigned char)len2Buf[3]);
        
        m_entries[name] = entry;
    }
}

InputStream* SarFile::openEntry(const QString& name)
{
    if (!m_isOpen) return nullptr;
    
    SarEntry* entry = findEntry(name);
    if (!entry) return nullptr;
    
    return nullptr;
}

QByteArray SarFile::readEntry(const QString& name)
{
    QByteArray result;
    if (!m_isOpen) return result;
    
    SarEntry* entry = findEntry(name);
    if (!entry) return result;
    
    return result;
}

bool SarFile::hasEntry(const QString& name) const
{
    return m_entries.contains(name);
}

SarEntry* SarFile::findEntry(const QString& name)
{
    auto it = m_entries.find(name);
    if (it != m_entries.end()) {
        return &it.value();
    }
    return nullptr;
}
