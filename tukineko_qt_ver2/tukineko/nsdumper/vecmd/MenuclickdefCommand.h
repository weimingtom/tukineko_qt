#ifndef MENUCLICKDEFCOMMAND_H
#define MENUCLICKDEFCOMMAND_H

#include "VECommand.h"
#include "nscripter.h"

class MenuclickdefCommand : public VECommand
{
public:
    MenuclickdefCommand();
    virtual ~MenuclickdefCommand();

    virtual bool check(const QString &str) override;
    virtual void execute() override;

private:
    tukineko::NScripter *ns;
};

#endif // MENUCLICKDEFCOMMAND_H
