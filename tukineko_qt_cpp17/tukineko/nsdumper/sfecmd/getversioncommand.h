#ifndef GETVERSIONCOMMAND_H
#define GETVERSIONCOMMAND_H

#include "sfecommand.h"

#include "nscripter.h"

class GetversionCommand : public SFECommand
{
public:
    GetversionCommand();

    bool check(const QString &str) override;
    void execute() override;

private:
    tukineko::NScripter *ns;
};

#endif // GETVERSIONCOMMAND_H
