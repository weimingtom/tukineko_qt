#include "nsvaluestorage.h"
#include <QDebug>

void NsValueStorage::load(InputStream* is, int* values, QString* strings, int start, int end)
{
    Q_UNUSED(is);
    Q_UNUSED(values);
    Q_UNUSED(strings);
    Q_UNUSED(start);
    Q_UNUSED(end);
    // Implementation would read from stream
}

void NsValueStorage::save(OutputStream* os, int* values, QString* strings, int start, int end)
{
    Q_UNUSED(os);
    Q_UNUSED(values);
    Q_UNUSED(strings);
    Q_UNUSED(start);
    Q_UNUSED(end);
    // Implementation would write to stream
}
