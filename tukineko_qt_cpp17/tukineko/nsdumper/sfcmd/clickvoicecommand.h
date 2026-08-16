#ifndef CLICKVOICECOMMAND_H
#define CLICKVOICECOMMAND_H

#include "sfcommand.h"

#include "nscripter.h"

class ClickvoiceCommand : public SFCommand
{
public:
    ClickvoiceCommand();

    bool check(const QString &str) override;
    void execute() override;

private:
    tukineko::NScripter *ns;
};

#endif // CLICKVOICECOMMAND_H
