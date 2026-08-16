#ifndef JAVA_IO_FILEINPUTSTREAM_H
#define JAVA_IO_FILEINPUTSTREAM_H

#include "InputStream.h"
#include <QFile>

namespace java {
namespace io {

class FileInputStream : public InputStream {
private:
    QFile* m_file;

public:
    explicit FileInputStream(const QString& filename);
    explicit FileInputStream(const QFileInfo& file);
    ~FileInputStream();

    int read() override;
    int read(char* bytes, int offset, int length) override;
    void close() override;
};

} // namespace io
} // namespace java

#endif // JAVA_IO_FILEINPUTSTREAM_H
