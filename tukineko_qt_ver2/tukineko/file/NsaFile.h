#ifndef NSAFILE_H
#define NSAFILE_H

#include <QFile>
#include <QDataStream>
#include <QMap>
#include <QString>
#include <QList>
#include "NsaEntry.h"
#include "NsaInputStream.h"

namespace tukineko {

class NsaFile
{
public:
    NsaFile(const QString &filename);
    ~NsaFile();

    int size() const;
    QList<NsaEntry> entries() const;
    NsaEntry getNsaEntry(const QString &key) const;
    NsaInputStream* getInputStream(const NsaEntry &ne);

private:
    QFile *file;
    QDataStream *stream;
    int num;
    int top;
    QMap<QString, NsaEntry> entry;

    int readByte();
    int readWord();
    int readLong();
    QString readString();
};

}

#endif // NSAFILE_H
