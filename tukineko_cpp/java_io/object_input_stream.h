#ifndef OBJECT_INPUT_STREAM_H
#define OBJECT_INPUT_STREAM_H

#include "input_stream.h"
#include <QDataStream>

class ObjectInputStream : public InputStream
{
public:
    ObjectInputStream(InputStream* in);
    virtual ~ObjectInputStream();
    
    int read() override;
    int read(QByteArray& b, int off, int len) override;
    
    // Type reading methods
    int readInt();
    bool readBool();
    QString readQString();
    QByteArray readBytes(int len);
    
private:
    InputStream* m_input;
    QDataStream m_dataStream;
};

#endif // OBJECT_INPUT_STREAM_H
