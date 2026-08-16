#ifndef MENUCLICKPAGECOMMAND_H
#define MENUCLICKPAGECOMMAND_H

#include <QString>
#include "vecommand.h"

class MenuclickpageCommand : public VECommand
{
public:
    MenuclickpageCommand();
    virtual ~MenuclickpageCommand();

    bool check(const QString& str);
    void execute();
};

#endif // MENUCLICKPAGECOMMAND_H
