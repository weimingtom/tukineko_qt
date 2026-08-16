#ifndef NSSELECT_H
#define NSSELECT_H

#include <QString>

class NsSelect
{
public:
    QString message;
    QString label;
    int y;
    int height;
    bool subrutine;
    bool selected;

    NsSelect(const QString &message, const QString &label, int y, int height, bool subrutine);
    NsSelect(const QString &message, const QString &label, int y, int height, bool subrutine, bool selected);
};

#endif // NSSELECT_H
