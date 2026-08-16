#ifndef RANDOM_ACCESS_FILE_H
#define RANDOM_ACCESS_FILE_H

#include <QFile>
#include <QByteArray>
#include "input_stream.h"
#include "output_stream.h"

class RandomAccessFile
{
public:
    RandomAccessFile(const QString& name, const QString& mode);
    ~RandomAccessFile();
    
    int read();
    int read(QByteArray& b, int off, int len);
    void write(int b);
    void write(const QByteArray& b, int off, int len);
    
    void seek(long pos);
    long getFilePointer();
    long length();
    void close();
    
    bool isNull() const { return !m_file.isOpen(); }

private:
    QFile m_file;
};

#endif // RANDOM_ACCESS_FILE_H
