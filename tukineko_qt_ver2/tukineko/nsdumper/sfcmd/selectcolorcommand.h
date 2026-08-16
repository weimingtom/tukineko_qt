#ifndef SELECTCOLORCOMMAND_H
#define SELECTCOLORCOMMAND_H

#include "sfcommand.h"

#include "nscripter.h"

class SelectcolorCommand : public SFCommand
{
public:
    SelectcolorCommand();

    bool check(const QString &str) override;
    void execute() override;

private:
    tukineko::NScripter *ns;
};

#endif // SELECTCOLORCOMMAND_H
