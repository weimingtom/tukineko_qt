#ifndef FILEINPUTSTREAM_H
#define FILEINPUTSTREAM_H

#include "inputstream.h"
#include <QFile>

class FileInputStream : public InputStream
{
public:
    FileInputStream(const QString& filename);
    virtual ~FileInputStream();

    int read() override;
    int read(QByteArray& buffer, int offset, int len) override;
    long available() override;
    void close() override;

private:
    QFile m_file;
};

#endif // FILEINPUTSTREAM_H
