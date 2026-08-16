#include "nsainputstream.h"
#include <QFile>

NsaInputStream::NsaInputStream(const QString& filename, int offset, int length)
    : m_filename(filename), m_offset(offset), m_length(length), m_pos(0)
{
}

NsaInputStream::~NsaInputStream()
{
}

int NsaInputStream::read()
{
    if (m_pos >= m_length) return -1;

    QFile file(m_filename);
    if (!file.open(QIODevice::ReadOnly)) return -1;

    file.seek(m_offset + m_pos);
    unsigned char c;
    if (file.read(reinterpret_cast<char*>(&c), 1) == 1) {
        m_pos++;
        file.close();
        return c;
    }

    file.close();
    return -1;
}
