#ifndef SAVENAMECOMMAND_H
#define SAVENAMECOMMAND_H

#include "sfcommand.h"

#include "nscripter.h"

class SavenameCommand : public SFCommand
{
public:
    SavenameCommand();

    bool check(const QString &str) override;
    void execute() override;

private:
    tukineko::NScripter *ns;
};

#endif // SAVENAMECOMMAND_H
