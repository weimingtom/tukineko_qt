#ifndef MENUSETWINDOWCOMMAND_H
#define MENUSETWINDOWCOMMAND_H

#include "sfcommand.h"

#include "nscripter.h"

class MenusetwindowCommand : public SFCommand
{
public:
    MenusetwindowCommand();

    bool check(const QString &str) override;
    void execute() override;

private:
    tukineko::NScripter *ns;
};

#endif // MENUSETWINDOWCOMMAND_H
