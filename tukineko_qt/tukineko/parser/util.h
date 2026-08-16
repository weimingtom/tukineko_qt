#ifndef UTIL_H
#define UTIL_H

#include <QString>

class Util
{
public:
    static int indexOf(const QString& str, QChar c);
    static QString substring(const QString& str, int start, int len = -1);
    static QString& trim(QString& str);
};

#endif // UTIL_H
