#ifndef MENUSELECTVOICECOMMAND_H
#define MENUSELECTVOICECOMMAND_H

#include "sfcommand.h"

#include "nscripter.h"

class MenuselectvoiceCommand : public SFCommand
{
public:
    MenuselectvoiceCommand();

    bool check(const QString &str) override;
    void execute() override;

private:
    tukineko::NScripter *ns;
};

#endif // MENUSELECTVOICECOMMAND_H
