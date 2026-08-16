#ifndef NSA_FILE_H
#define NSA_FILE_H

#include <QString>
#include <QMap>
#include "../java_io/input_stream.h"

struct NsaEntry
{
    QString name;
    int offset;
    int length;
};

class NsaFile
{
public:
    NsaFile();
    NsaFile(const QString& filename);
    ~NsaFile();
    
    bool open(const QString& filename);
    void close();
    bool isOpen() const { return m_isOpen; }
    
    InputStream* openEntry(const QString& name);
    QByteArray readEntry(const QString& name);
    bool hasEntry(const QString& name) const;
    int getNumEntries() const { return m_entries.size(); }

private:
    bool m_isOpen;
    QString m_filename;
    InputStream* m_stream;
    QMap<QString, NsaEntry> m_entries;
    
    void readIndex();
    NsaEntry* findEntry(const QString& name);
};

#endif // NSA_FILE_H
