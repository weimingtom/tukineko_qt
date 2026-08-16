#ifndef SARFILE_H
#define SARFILE_H

#include <QFile>
#include <QDataStream>
#include <QMap>
#include <QString>
#include <QList>
#include "SarEntry.h"
#include "SarInputStream.h"

namespace tukineko {

class SarFile
{
public:
    SarFile(const QString &filename);
    ~SarFile();

    int size() const;
    QList<SarEntry> entries() const;
    SarEntry getSarEntry(const QString &key) const;
    SarInputStream* getInputStream(const SarEntry &se);

private:
    QFile *file;
    QDataStream *stream;
    int num;
    int top;
    QMap<QString, SarEntry> entry;

    int readByte();
    int readWord();
    int readLong();
    QString readString();
};

}

#endif // SARFILE_H
