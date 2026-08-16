#include "SarEntry.h"

namespace tukineko {

SarEntry::SarEntry()
{

}

SarEntry::SarEntry(const QString &name, int offset, int length)
    : name(name), offset(offset), length(length)
{
}

int SarEntry::length_() const
{
    return this->length;
}

QString SarEntry::toString() const
{
    return QString("SarEntry name:%1,offset:%2,length:%3")
        .arg(this->name)
        .arg(this->offset)
        .arg(this->length);
}

}
