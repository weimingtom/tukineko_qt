#ifndef SARFILE_H
#define SARFILE_H

#include <QString>
#include <QMap>

class SarEntry;
class InputStream;

class SarFile
{
public:
    SarFile(const QString& filename);
    virtual ~SarFile();

    SarEntry* getSarEntry(const QString& name);
    InputStream* getInputStream(SarEntry* entry);

private:
    void readHeader();

private:
    QString m_filename;
    QMap<QString, SarEntry*> m_entries;
};

#endif // SARFILE_H
