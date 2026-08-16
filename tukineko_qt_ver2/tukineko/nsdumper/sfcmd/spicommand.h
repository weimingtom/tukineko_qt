#ifndef SPICOMMAND_H
#define SPICOMMAND_H

#include "sfcommand.h"

#include "nscripter.h"

class SpiCommand : public SFCommand
{
public:
    SpiCommand();

    bool check(const QString &str) override;
    void execute() override;

private:
    tukineko::NScripter *ns;
};

#endif // SPICOMMAND_H
