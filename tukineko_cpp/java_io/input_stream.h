#ifndef INPUT_STREAM_H
#define INPUT_STREAM_H

#include <QIODevice>
#include <QBuffer>
#include <QByteArray>
#include <QFile>

class InputStream
{
public:
    InputStream();
    InputStream(QIODevice* device);
    virtual ~InputStream();
    
    virtual int read();
    virtual int read(QByteArray& buffer, int len);
    virtual int read(QByteArray& buffer, int off, int len);
    virtual long skip(long n);
    virtual int available();
    virtual void close();
    virtual void mark(int readlimit);
    virtual void reset();
    virtual bool markSupported();

protected:
    QIODevice* m_device;
    bool m_owned;
};

class FileInputStream : public InputStream
{
public:
    FileInputStream(const QString& fileName);
    FileInputStream(QIODevice* device);
    virtual ~FileInputStream();
};

class ByteArrayInputStream : public InputStream
{
public:
    ByteArrayInputStream(const QByteArray& buffer);
    ByteArrayInputStream(const QByteArray& buffer, int offset, int length);
    virtual ~ByteArrayInputStream();
    
    virtual int read() override;
    virtual int read(QByteArray& buffer, int off, int len) override;
    virtual long skip(long n) override;
    virtual void reset() override;
    virtual bool markSupported() override { return true; }

private:
    QByteArray m_buffer;
    int m_pos;
    int m_markPos;
    int m_count;
};

#endif // INPUT_STREAM_H
