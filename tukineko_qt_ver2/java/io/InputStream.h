#ifndef JAVA_IO_INPUTSTREAM_H
#define JAVA_IO_INPUTSTREAM_H

#include <QIODevice>
#include <QByteArray>
#include <memory>
#include "IOException.h"

namespace java {
namespace io {

class InputStream {
protected:
    QIODevice* m_device;
    bool m_ownsDevice;
    qint64 m_markPos;

public:
    InputStream();
    explicit InputStream(QIODevice* device);
    virtual ~InputStream();

    QIODevice* device() const { return m_device; }
    void setDevice(QIODevice* device, bool owns = false);

    virtual int available();
    virtual void close();
    virtual void mark(int readlimit);
    virtual bool markSupported();
    virtual int read();
    virtual int read(QByteArray& buf);
    virtual int read(char* b, int off, int len);
    virtual void reset();
    virtual qint64 skip(qint64 cnt);

    static InputStream* wrap(QIODevice* device);
};

} // namespace io
} // namespace java

#endif // JAVA_IO_INPUTSTREAM_H
