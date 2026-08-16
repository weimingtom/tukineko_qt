#ifndef JAVA_IO_OUTPUTSTREAM_H
#define JAVA_IO_OUTPUTSTREAM_H

#include <QIODevice>
#include <QByteArray>

namespace java {
namespace io {

class OutputStream {
protected:
    QIODevice* m_device;
    bool m_ownsDevice;

public:
    OutputStream();
    explicit OutputStream(QIODevice* device);
    virtual ~OutputStream();

    QIODevice* device() const { return m_device; }
    void setDevice(QIODevice* device, bool owns = false);

    virtual void close();
    virtual void flush();
    virtual void write(int b);
    virtual void write(const QByteArray& b);
    virtual void write(const char* b, int offset, int len);

    static OutputStream* wrap(QIODevice* device);
};

} // namespace io
} // namespace java

#endif // JAVA_IO_OUTPUTSTREAM_H
