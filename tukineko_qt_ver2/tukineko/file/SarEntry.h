#ifndef SARENTRY_H
#define SARENTRY_H

#include <QString>

namespace tukineko {

class SarEntry
{
public:
    QString name;
    int offset;
    int length;

    SarEntry();
    SarEntry(const QString &name, int offset, int length);

    int length_() const;

    QString toString() const;
};

}

#endif // SARENTRY_H
