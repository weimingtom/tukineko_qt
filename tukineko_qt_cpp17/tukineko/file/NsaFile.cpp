#include "NsaFile.h"
#include <QDebug>

namespace tukineko {

NsaFile::NsaFile(const QString &filename)
    : file(new QFile(filename)), num(0), top(0)
{
    if (!file->open(QIODevice::ReadOnly)) {
        delete file;
        file = nullptr;
        stream = nullptr;
        return;
    }

    stream = new QDataStream(file);
    stream->setByteOrder(QDataStream::BigEndian);

    this->num = readWord();
    this->top = readLong();

    for (int n = 0; n < this->num; n++) {
        QString str = readString();
        int k = readByte();
        int i = readLong() + this->top;
        int j = readLong();
        int m = readLong();
        this->entry.insert(str, NsaEntry(str, i, j, k, m));
    }
}

NsaFile::~NsaFile()
{
    delete stream;
    if (file) {
        file->close();
        delete file;
    }
}

int NsaFile::size() const
{
    return this->entry.size();
}

QList<NsaEntry> NsaFile::entries() const
{
    return this->entry.values();
}

NsaEntry NsaFile::getNsaEntry(const QString &key) const
{
    return this->entry.value(key);
}

NsaInputStream* NsaFile::getInputStream(const NsaEntry &ne)
{
    return new NsaInputStream(file, ne);
}

int NsaFile::readByte()
{
    quint8 byte;
    *stream >> byte;
    return byte;
}

int NsaFile::readWord()
{
    int i = readByte() << 8;
    return i | readByte();
}

int NsaFile::readLong()
{
    int i = readByte() << 24;
    i |= readByte() << 16;
    i |= readByte() << 8;
    return i | readByte();
}

QString NsaFile::readString()
{
    QString result;
    char c;
    while (stream->readRawData(&c, 1) == 1 && c != 0) {
        result.append(QChar(c));
    }
    return result;
}

}
