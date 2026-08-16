#ifndef FILEOUTPUTSTREAM_H
#define FILEOUTPUTSTREAM_H

#include "outputstream.h"
#include <QFile>

class FileOutputStream : public OutputStream
{
public:
    FileOutputStream(const QString& filename);
    virtual ~FileOutputStream();

    void write(int b) override;
    void flush() override;
    void close() override;

private:
    QFile m_file;
};

#endif // FILEOUTPUTSTREAM_H
