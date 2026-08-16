#ifndef SARINPUTSTREAM_H
#define SARINPUTSTREAM_H

#include "java/io/inputstream.h"

class SarInputStream : public InputStream
{
public:
    SarInputStream(const QString& filename, int offset, int length);
    virtual ~SarInputStream();

    int read() override;

private:
    QString m_filename;
    int m_offset;
    int m_length;
    int m_pos;
};

#endif // SARINPUTSTREAM_H
