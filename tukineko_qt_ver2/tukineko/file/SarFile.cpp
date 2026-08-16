#include "SarFile.h"
#include <QDebug>

namespace tukineko {

SarFile::SarFile(const QString &filename)
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

    for (int k = 0; k < this->num; k++) {
        QString str = readString();
        int i = readLong() + this->top;
        int j = readLong();
        this->entry.insert(str, SarEntry(str, i, j));
    }
}

SarFile::~SarFile()
{
    delete stream;
    if (file) {
        file->close();
        delete file;
    }
}

int SarFile::size() const
{
    return this->entry.size();
}

QList<SarEntry> SarFile::entries() const
{
    return this->entry.values();
}

SarEntry SarFile::getSarEntry(const QString &key) const
{
    return this->entry.value(key);
}

SarInputStream* SarFile::getInputStream(const SarEntry &se)
{
    return new SarInputStream(file, se);
}

int SarFile::readByte()
{
    quint8 byte;
    *stream >> byte;
    return byte;
}

int SarFile::readWord()
{
    int i = readByte() << 8;
    return i | readByte();
}

int SarFile::readLong()
{
    int i = readByte() << 24;
    i |= readByte() << 16;
    i |= readByte() << 8;
    return i | readByte();
}

QString SarFile::readString()
{
    QString result;
    char c;
    while (stream->readRawData(&c, 1) == 1 && c != 0) {
        result.append(QChar(c));
    }
    return result;
}

}
