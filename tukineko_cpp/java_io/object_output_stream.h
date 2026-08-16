#ifndef OBJECT_OUTPUT_STREAM_H
#define OBJECT_OUTPUT_STREAM_H

#include "output_stream.h"
#include <QDataStream>

class ObjectOutputStream : public OutputStream
{
public:
    ObjectOutputStream(OutputStream* out);
    virtual ~ObjectOutputStream();
    
    void write(int b) override;
    void write(const QByteArray& b, int off, int len) override;
    
    // Type writing methods
    void writeInt(int val);
    void writeBool(bool val);
    void writeQString(const QString& str);
    void writeBytes(const QByteArray& bytes);
    
private:
    OutputStream* m_output;
};

#endif // OBJECT_OUTPUT_STREAM_H
