#include "nsafile.h"
#include "nsaentry.h"
#include "nsainputstream.h"
#include <QFile>
#include <QDebug>

NsaFile::NsaFile(const QString& filename)
    : m_filename(filename)
{
    readHeader();
}

NsaFile::~NsaFile()
{
    qDeleteAll(m_entries);
    m_entries.clear();
}

void NsaFile::readHeader()
{
    QFile file(m_filename);
    if (!file.open(QIODevice::ReadOnly)) {
        qDebug() << "Failed to open NSA file:" << m_filename;
        return;
    }

    // NSA header parsing would go here
    file.close();
}

NsaEntry* NsaFile::getNsaEntry(const QString& name)
{
    return m_entries.value(name, nullptr);
}

InputStream* NsaFile::getInputStream(NsaEntry* entry)
{
    if (!entry) return nullptr;
    return new NsaInputStream(m_filename, entry->offset(), entry->length_());
}
