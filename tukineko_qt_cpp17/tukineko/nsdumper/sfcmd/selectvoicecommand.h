#ifndef SELECTVOICECOMMAND_H
#define SELECTVOICECOMMAND_H

#include "sfcommand.h"

#include "nscripter.h"

class SelectvoiceCommand : public SFCommand
{
public:
    SelectvoiceCommand();

    bool check(const QString &str) override;
    void execute() override;

private:
    tukineko::NScripter *ns;
};

#endif // SELECTVOICECOMMAND_H
