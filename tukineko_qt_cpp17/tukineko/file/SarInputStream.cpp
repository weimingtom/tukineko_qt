#include "SarInputStream.h"
#include <QIODevice>

namespace tukineko {

SarInputStream::SarInputStream(QIODevice *device, const SarEntry &se)
    : device(device), position(0), length(se.length)
{
    if (device) {
        device->seek(se.offset);
    }
}

bool SarInputStream::isSequential() const
{
    return false;
}

bool SarInputStream::open(OpenMode mode)
{
    if (mode & QIODevice::WriteOnly) {
        return false;
    }
    setOpenMode(mode);
    this->position = 0;
    if (device) {
        device->seek(device->pos() - this->position);
    }
    return true;
}

void SarInputStream::close()
{
    this->position = this->length;
    setOpenMode(NotOpen);
}

qint64 SarInputStream::pos() const
{
    return this->position;
}

qint64 SarInputStream::size() const
{
    return this->length;
}

bool SarInputStream::seek(qint64 pos)
{
    if (pos < 0 || pos > this->length) {
        return false;
    }
    this->position = static_cast<int>(pos);
    if (device) {
        device->seek(device->pos() - this->position + pos);
    }
    return true;
}

bool SarInputStream::atEnd() const
{
    return this->position >= this->length;
}

qint64 SarInputStream::readData(char *data, qint64 maxlen)
{
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

qint64 SarInputStream::writeData(const char *data, qint64 len)
{
    Q_UNUSED(data)
    Q_UNUSED(len)
    return -1;
}

}
