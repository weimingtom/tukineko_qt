#include "NsaInputStream.h"
#include <QIODevice>

namespace tukineko {

NsaInputStream::NsaInputStream(QIODevice *device, const NsaEntry &ne)
    : ne(ne), device(device), position(0), length(ne.length)
{
    if (device) {
        device->seek(ne.offset);
    }
}

bool NsaInputStream::isSequential() const
{
    return false;
}

bool NsaInputStream::open(OpenMode mode)
{
    if (mode & QIODevice::WriteOnly) {
        return false;
    }
    setOpenMode(mode);
    this->position = 0;
    if (device) {
        device->seek(ne.offset);
    }
    return true;
}

void NsaInputStream::close()
{
    this->position = this->length;
    setOpenMode(NotOpen);
}

qint64 NsaInputStream::pos() const
{
    return this->position;
}

qint64 NsaInputStream::size() const
{
    return this->length;
}

bool NsaInputStream::seek(qint64 pos)
{
    if (pos < 0 || pos > this->length) {
        return false;
    }
    this->position = static_cast<int>(pos);
    if (device) {
        device->seek(ne.offset + this->position);
    }
    return true;
}

bool NsaInputStream::atEnd() const
{
    return this->position >= this->length;
}

qint64 NsaInputStream::readData(char *data, qint64 maxlen)
{
    if (this->ne.type != 0) {
        return -1;
    }
    if (this->position < this->length && device) {
        qint64 i;
        if (this->position + maxlen <= this->length)
            i = maxlen;
        else {
            i = this->length - this->position;
        }
        this->position += static_cast<int>(i);
        return device->read(data, i);
    }
    return -1;
}

qint64 NsaInputStream::writeData(const char *data, qint64 len)
{
    Q_UNUSED(data)
    Q_UNUSED(len)
    return -1;
}

}
