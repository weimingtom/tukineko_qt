#ifndef NSAENTRY_H
#define NSAENTRY_H

#include <QString>

namespace tukineko {

class NsaEntry
{
public:
    int offset;
    int type;
    int length;

    NsaEntry();
    NsaEntry(const QString &name, int offset, int compressLength, int type, int length);

    int length_() const;

    QString toString() const;

private:
    QString name;
    int compressLength;
};

}

#endif // NSAENTRY_H
