#ifndef NSSSELECT_H
#define NSSSELECT_H

#include <QString>

struct NsGosub
{
    int retpos;
    QString rest;
};

class NsSelect
{
public:
    NsSelect(const QString& message, const QString& label, int y, int height, bool subrutine, bool selected);
    virtual ~NsSelect();

    QString message;
    QString label;
    int y;
    int height;
    bool subrutine;
    bool selected;
};

#endif // NSSSELECT_H
