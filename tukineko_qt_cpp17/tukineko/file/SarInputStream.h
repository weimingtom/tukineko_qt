#ifndef SARINPUTSTREAM_H
#define SARINPUTSTREAM_H

#include <QIODevice>
#include <QDataStream>
#include "SarEntry.h"

namespace tukineko {

class SarInputStream : public QIODevice
{
    Q_OBJECT

public:
    SarInputStream(QIODevice *device, const SarEntry &se);

    bool isSequential() const override;
    bool open(OpenMode mode) override;
    void close() override;
    qint64 pos() const override;
    qint64 size() const override;
    bool seek(qint64 pos) override;
    bool atEnd() const override;

protected:
    qint64 readData(char *data, qint64 maxlen) override;
    qint64 writeData(const char *data, qint64 len) override;

private:
    QIODevice *device;
    int position;
    int length;
};

}

#endif // SARINPUTSTREAM_H
