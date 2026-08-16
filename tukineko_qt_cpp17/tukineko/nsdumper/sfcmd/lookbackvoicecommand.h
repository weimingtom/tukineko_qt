#ifndef LOOKBACKVOICECOMMAND_H
#define LOOKBACKVOICECOMMAND_H

#include "sfcommand.h"

#include "nscripter.h"

class LookbackvoiceCommand : public SFCommand
{
public:
    LookbackvoiceCommand();

    bool check(const QString &str) override;
    void execute() override;

private:
    tukineko::NScripter *ns;
};

#endif // LOOKBACKVOICECOMMAND_H
