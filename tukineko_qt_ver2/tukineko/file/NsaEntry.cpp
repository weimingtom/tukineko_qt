#include "NsaEntry.h"

namespace tukineko {

NsaEntry::NsaEntry()
{

}

NsaEntry::NsaEntry(const QString &name, int offset, int compressLength, int type, int length)
    : name(name), offset(offset), compressLength(length), type(type), length(length)
{
}

int NsaEntry::length_() const
{
    return this->length;
}

QString NsaEntry::toString() const
{
    QString typeStr;
    if (this->type == 2)
        typeStr = "lzss";
    else if (this->type == 1)
        typeStr = "spb";
    else
        typeStr = "raw";

    return QString("NsaEntry name:%1,offset:%2,compress length:%3,type:%4,length:%5")
        .arg(this->name)
        .arg(this->offset)
        .arg(this->compressLength)
        .arg(typeStr)
        .arg(this->length);
}

}
