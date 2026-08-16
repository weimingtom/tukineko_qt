#include "util.h"

int Util::indexOf(const QString& str, QChar c)
{
    return str.indexOf(c);
}

QString Util::substring(const QString& str, int start, int len)
{
    if (len < 0) {
        return str.mid(start);
    }
    return str.mid(start, len);
}

QString& Util::trim(QString& str)
{
    str = str.trimmed();
    return str;
}
