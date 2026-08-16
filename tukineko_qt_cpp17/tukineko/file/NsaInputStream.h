#ifndef NSAINPUTSTREAM_H
#define NSAINPUTSTREAM_H

#include <QIODevice>
#include <QDataStream>
#include "NsaEntry.h"

namespace tukineko {

class NsaInputStream : public QIODevice
{
    Q_OBJECT

public:
    NsaInputStream(QIODevice *device, const NsaEntry &ne);

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
    NsaEntry ne;
    QIODevice *device;
    QDataStream *stream;
    int position;
    int length;
};

}

#endif // NSAINPUTSTREAM_H
