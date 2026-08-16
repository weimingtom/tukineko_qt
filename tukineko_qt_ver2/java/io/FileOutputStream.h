#ifndef JAVA_IO_FILEOUTPUTSTREAM_H
#define JAVA_IO_FILEOUTPUTSTREAM_H

#include "OutputStream.h"
#include <QFile>
#include <QFileInfo>

namespace java {
namespace io {

class FileOutputStream : public OutputStream {
private:
    QFile* m_file;

public:
    explicit FileOutputStream(const QString& filename);
    explicit FileOutputStream(const QFileInfo& file);
    ~FileOutputStream();

    void write(int x) override;
    void write(const QByteArray& bytes) override;
    void write(const char* bytes, int offset, int length) override;
    void close() override;
};

} // namespace io
} // namespace java

#endif // JAVA_IO_FILEOUTPUTSTREAM_H
