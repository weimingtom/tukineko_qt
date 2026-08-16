#include "nsa_file.h"
#include "../java_io/file_input_stream.h"
#include <QDebug>

NsaFile::NsaFile()
    : m_isOpen(false)
    , m_stream(nullptr)
{
}

NsaFile::NsaFile(const QString& filename)
    : m_isOpen(false)
    , m_stream(nullptr)
{
    open(filename);
}

NsaFile::~NsaFile()
{
    close();
}

bool NsaFile::open(const QString& filename)
{
    if (m_isOpen) {
        close();
    }
    
    if (!File_::exists(filename)) {
        qDebug() << "NSA file not found:" << filename;
        return false;
    }
    
    m_filename = filename;
    m_stream = new FileInputStream(filename);
    
    // Try to read index
    try {
        readIndex();
        m_isOpen = true;
        qDebug() << "Opened NSA archive:" << filename << "with" << m_entries.size() << "entries";
        return true;
    } catch (...) {
        qDebug() << "Failed to read NSA index";
        delete m_stream;
        m_stream = nullptr;
        return false;
    }
}

void NsaFile::close()
{
    if (m_stream) {
        m_stream->close();
        delete m_stream;
        m_stream = nullptr;
    }
    m_entries.clear();
    m_isOpen = false;
}

void NsaFile::readIndex()
{
    if (!m_stream) return;
    
    // NSA format: 4-byte header, then index entries
    // Each entry: 16-byte filename, 4-byte offset, 4-byte length
    // (format may vary, this is a generic implementation)
    
    // Skip header (if any)
    m_stream->skip(4);
    
    // Read entries until we hit the data section
    while (m_stream->available() > 0) {
        QByteArray nameBuf(16, 0);
        int read = m_stream->read(nameBuf, 0, 16);
        if (read < 16) break;
        
        QString name = QString::fromLatin1(nameBuf).trimmed();
        if (name.isEmpty()) break;
        
        NsaEntry entry;
        entry.name = name;
        
        // Read offset (4 bytes, big-endian)
        QByteArray offsetBuf(4, 0);
        m_stream->read(offsetBuf, 0, 4);
        entry.offset = ((unsigned char)offsetBuf[0] << 24) |
                      ((unsigned char)offsetBuf[1] << 16) |
                      ((unsigned char)offsetBuf[2] << 8) |
                      ((unsigned char)offsetBuf[3]);
        
        // Read length (4 bytes, big-endian)
        QByteArray lenBuf(4, 0);
        m_stream->read(lenBuf, 0, 4);
        entry.length = ((unsigned char)lenBuf[0] << 24) |
                       ((unsigned char)lenBuf[1] << 16) |
                       ((unsigned char)lenBuf[2] << 8) |
                       ((unsigned char)lenBuf[3]);
        
        m_entries[name] = entry;
    }
}

InputStream* NsaFile::openEntry(const QString& name)
{
    if (!m_isOpen) return nullptr;
    
    NsaEntry* entry = findEntry(name);
    if (!entry) return nullptr;
    
    // Create a sub-stream for this entry
    // In a full implementation, we'd seek to the offset and limit the read
    return nullptr;
}

QByteArray NsaFile::readEntry(const QString& name)
{
    QByteArray result;
    if (!m_isOpen) return result;
    
    NsaEntry* entry = findEntry(name);
    if (!entry) return result;
    
    // Seek to offset and read
    // (simplified - full implementation would handle seeking)
    
    return result;
}

bool NsaFile::hasEntry(const QString& name) const
{
    return m_entries.contains(name);
}

NsaEntry* NsaFile::findEntry(const QString& name)
{
    auto it = m_entries.find(name);
    if (it != m_entries.end()) {
        return &it.value();
    }
    return nullptr;
}
