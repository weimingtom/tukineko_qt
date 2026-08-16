#ifndef NSAENTRY_H
#define NSAENTRY_H

#include <QString>

class NsaEntry
{
public:
    NsaEntry(const QString& name, int offset, int length);
    virtual ~NsaEntry();

    QString name() const { return m_name; }
    int offset() const { return m_offset; }
    int length_() const { return m_length; }

private:
    QString m_name;
    int m_offset;
    int m_length;
};

#endif // NSAENTRY_H
