#include "sarentry.h"

SarEntry::SarEntry(const QString& name, int offset, int length)
    : m_name(name), m_offset(offset), m_length(length)
{
}

SarEntry::~SarEntry()
{
}
