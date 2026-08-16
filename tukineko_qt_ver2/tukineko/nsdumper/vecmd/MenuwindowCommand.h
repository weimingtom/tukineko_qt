#ifndef MENUWINDOWCOMMAND_H
#define MENUWINDOWCOMMAND_H

#include "VECommand.h"
#include "nscripter.h"

class MenuwindowCommand : public VECommand
{
public:
    MenuwindowCommand();
    virtual ~MenuwindowCommand();

    virtual bool check(const QString &str) override;
    virtual void execute() override;

private:
    tukineko::NScripter *ns;
};

#endif // MENUWINDOWCOMMAND_H
