#include "sarfile.h"
#include "sarentry.h"
#include "sarinputstream.h"
#include <QFile>
#include <QDebug>

SarFile::SarFile(const QString& filename)
    : m_filename(filename)
{
    readHeader();
}

SarFile::~SarFile()
{
    qDeleteAll(m_entries);
    m_entries.clear();
}

void SarFile::readHeader()
{
    QFile file(m_filename);
    if (!file.open(QIODevice::ReadOnly)) {
        qDebug() << "Failed to open SAR file:" << m_filename;
        return;
    }

    // SAR header parsing would go here
    file.close();
}

SarEntry* SarFile::getSarEntry(const QString& name)
{
    return m_entries.value(name, nullptr);
}

InputStream* SarFile::getInputStream(SarEntry* entry)
{
    if (!entry) return nullptr;
    return new SarInputStream(m_filename, entry->offset(), entry->length_());
}
