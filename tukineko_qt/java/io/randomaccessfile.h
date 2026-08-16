#ifndef RANDOMACCESSFILE_H
#define RANDOMACCESSFILE_H

#include <QFile>
#include <QString>

class RandomAccessFile
{
public:
    RandomAccessFile(const QString& filename, const QString& mode);
    virtual ~RandomAccessFile();

    int read();
    int read(char* buffer, int offset, int len);
    long length() const;
    long getFilePointer() const;
    void seek(long pos);
    void close();

private:
    QFile m_file;
    QString m_mode;
};

#endif // RANDOMACCESSFILE_H
