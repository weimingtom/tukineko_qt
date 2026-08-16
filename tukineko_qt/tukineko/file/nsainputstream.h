#ifndef NSAINPUTSTREAM_H
#define NSAINPUTSTREAM_H

#include "java/io/inputstream.h"

class NsaInputStream : public InputStream
{
public:
    NsaInputStream(const QString& filename, int offset, int length);
    virtual ~NsaInputStream();

    int read() override;

private:
    QString m_filename;
    int m_offset;
    int m_length;
    int m_pos;
};

#endif // NSAINPUTSTREAM_H
