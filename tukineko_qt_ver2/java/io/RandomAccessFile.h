#ifndef JAVA_IO_RANDOMACCESSFILE_H
#define JAVA_IO_RANDOMACCESSFILE_H

#include <QFile>
#include <QString>

namespace java {
namespace io {

class RandomAccessFile {
private:
    QFile* m_file;

public:
    RandomAccessFile(const QString& name, const QString& mode);
    ~RandomAccessFile();

    int read();
    void seek(int offset);
    int read(char* bytes, int offset, int len);
    qint64 skipBytes(int i);
    void close();
};

} // namespace io
} // namespace java

#endif // JAVA_IO_RANDOMACCESSFILE_H
