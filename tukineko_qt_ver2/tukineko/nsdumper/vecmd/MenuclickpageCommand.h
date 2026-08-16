#ifndef MENUCLICKPAGECOMMAND_H
#define MENUCLICKPAGECOMMAND_H

#include "VECommand.h"
#include "nscripter.h"

class MenuclickpageCommand : public VECommand
{
public:
    MenuclickpageCommand();
    virtual ~MenuclickpageCommand();

    virtual bool check(const QString &str) override;
    virtual void execute() override;

private:
    tukineko::NScripter *ns;
};

#endif // MENUCLICKPAGECOMMAND_H
