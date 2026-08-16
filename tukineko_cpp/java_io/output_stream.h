#ifndef OUTPUT_STREAM_H
#define OUTPUT_STREAM_H

#include <QIODevice>
#include <QByteArray>
#include <QFile>

class OutputStream
{
public:
    OutputStream();
    OutputStream(QIODevice* device);
    virtual ~OutputStream();
    
    virtual void write(int b);
    virtual void write(const QByteArray& b);
    virtual void write(const QByteArray& b, int off, int len);
    virtual void flush();
    virtual void close();

protected:
    QIODevice* m_device;
    bool m_owned;
};

class FileOutputStream : public OutputStream
{
public:
    FileOutputStream(const QString& fileName, bool append = false);
    FileOutputStream(QIODevice* device);
    virtual ~FileOutputStream();
};

class ByteArrayOutputStream : public OutputStream
{
public:
    ByteArrayOutputStream();
    ByteArrayOutputStream(int size);
    virtual ~ByteArrayOutputStream();
    
    virtual void write(int b) override;
    virtual void write(const QByteArray& b, int off, int len) override;
    
    QByteArray toByteArray() const;
    QByteArray& getBuffer();
    int size() const;
    void reset();

private:
    QByteArray m_buffer;
};

#endif // OUTPUT_STREAM_H
