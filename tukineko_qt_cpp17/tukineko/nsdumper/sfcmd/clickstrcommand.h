#ifndef CLICKSTRCOMMAND_H
#define CLICKSTRCOMMAND_H

#include "sfcommand.h"

#include "nscripter.h"

class ClickstrCommand : public SFCommand
{
public:
    ClickstrCommand();

    bool check(const QString &str) override;
    void execute() override;

private:
    tukineko::NScripter *ns;
};

#endif // CLICKSTRCOMMAND_H
