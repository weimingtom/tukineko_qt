#ifndef INPUTSTREAM_H
#define INPUTSTREAM_H

#include <QObject>
#include <QByteArray>

class InputStream
{
public:
    InputStream();
    virtual ~InputStream();

    virtual int read() = 0;
    virtual int read(QByteArray& buffer, int offset, int len);
    //FIXME:added
    virtual int read(QByteArray& buffer) {Q_UNUSED(buffer) return 0;}
    virtual long available();
    virtual void close();

protected:
    QByteArray m_buffer;
    int m_pos;
};

#endif // INPUTSTREAM_H
