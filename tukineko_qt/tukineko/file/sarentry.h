#ifndef SARENTRY_H
#define SARENTRY_H

#include <QString>

class SarEntry
{
public:
    SarEntry(const QString& name, int offset, int length);
    virtual ~SarEntry();

    QString name() const { return m_name; }
    int offset() const { return m_offset; }
    int length_() const { return m_length; }

private:
    QString m_name;
    int m_offset;
    int m_length;
};

#endif // SARENTRY_H
