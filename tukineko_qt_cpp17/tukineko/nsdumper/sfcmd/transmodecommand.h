#ifndef TRANSMODECOMMAND_H
#define TRANSMODECOMMAND_H

#include "sfcommand.h"

#include "nscripter.h"

class TransmodeCommand : public SFCommand
{
public:
    TransmodeCommand();

    bool check(const QString &str) override;
    void execute() override;

private:
    tukineko::NScripter *ns;
};

#endif // TRANSMODECOMMAND_H
