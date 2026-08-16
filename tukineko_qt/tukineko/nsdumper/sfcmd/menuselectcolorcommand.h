#ifndef MENUSELECTCOLORCOMMAND_H
#define MENUSELECTCOLORCOMMAND_H

#include <QString>
#include "sfcommand.h"

class MenuselectcolorCommand : public SFCommand
{
public:
    MenuselectcolorCommand();
    virtual ~MenuselectcolorCommand();

    bool check(const QString& str);
    void execute();
};

#endif // MENUSELECTCOLORCOMMAND_H
