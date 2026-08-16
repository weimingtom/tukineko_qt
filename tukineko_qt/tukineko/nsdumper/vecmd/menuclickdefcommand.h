#ifndef MENUCLICKDEFCOMMAND_H
#define MENUCLICKDEFCOMMAND_H

#include <QString>
#include "vecommand.h"

class MenuclickdefCommand : public VECommand
{
public:
    MenuclickdefCommand();
    virtual ~MenuclickdefCommand();

    bool check(const QString& str);
    void execute();
};

#endif // MENUCLICKDEFCOMMAND_H
