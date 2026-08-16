#ifndef SAR_FILE_H
#define SAR_FILE_H

#include <QString>
#include <QMap>
#include "../java_io/input_stream.h"

struct SarEntry
{
    QString name;
    int offset;
    int length;
};

class SarFile
{
public:
    SarFile();
    SarFile(const QString& filename);
    ~SarFile();
    
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
    QMap<QString, SarEntry> m_entries;
    
    void readIndex();
    SarEntry* findEntry(const QString& name);
};

#endif // SAR_FILE_H
