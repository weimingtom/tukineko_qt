#ifndef OUTPUTSTREAM_H
#define OUTPUTSTREAM_H

#include <QObject>
#include <QByteArray>

class OutputStream
{
public:
    OutputStream();
    virtual ~OutputStream();

    virtual void write(int b) = 0;
    virtual void write(const QByteArray& buffer, int offset = 0, int len = -1);
    virtual void flush();
    virtual void close();

protected:
    QByteArray m_buffer;
};

#endif // OUTPUTSTREAM_H
