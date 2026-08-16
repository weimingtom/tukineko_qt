#ifndef NSAFILE_H
#define NSAFILE_H

#include <QString>
#include <QMap>

class NsaEntry;
class InputStream;

class NsaFile
{
public:
    NsaFile(const QString& filename);
    virtual ~NsaFile();

    NsaEntry* getNsaEntry(const QString& name);
    InputStream* getInputStream(NsaEntry* entry);

private:
    void readHeader();

private:
    QString m_filename;
    QMap<QString, NsaEntry*> m_entries;
};

#endif // NSAFILE_H
