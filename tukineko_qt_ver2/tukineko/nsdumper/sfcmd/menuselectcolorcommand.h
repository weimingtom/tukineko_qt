#ifndef MENUSELECTCOLORCOMMAND_H
#define MENUSELECTCOLORCOMMAND_H

#include "sfcommand.h"

#include "nscripter.h"

class MenuselectcolorCommand : public SFCommand
{
public:
    MenuselectcolorCommand();

    bool check(const QString &str) override;
    void execute() override;

private:
    tukineko::NScripter *ns;
};

#endif // MENUSELECTCOLORCOMMAND_H
