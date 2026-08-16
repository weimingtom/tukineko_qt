#include "sarinputstream.h"
#include <QFile>

SarInputStream::SarInputStream(const QString& filename, int offset, int length)
    : m_filename(filename), m_offset(offset), m_length(length), m_pos(0)
{
}

SarInputStream::~SarInputStream()
{
}

int SarInputStream::read()
{
    if (m_pos >= m_length) return -1;

    QFile file(m_filename);
    if (!file.open(QIODevice::ReadOnly)) return -1;

    file.seek(m_offset + m_pos);
    unsigned char c;
    if (file.read(reinterpret_cast<char*>(&c), 1) == 1) {
        m_pos++;
        file.close();
        return c ^ 0x84;
    }

    file.close();
    return -1;
}
