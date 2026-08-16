#ifndef DEFAULTFONTCOMMAND_H
#define DEFAULTFONTCOMMAND_H

#include "sfcommand.h"

#include "nscripter.h"

class DefaultfontCommand : public SFCommand
{
public:
    DefaultfontCommand();

    bool check(const QString &str) override;
    void execute() override;

private:
    tukineko::NScripter *ns;
};

#endif // DEFAULTFONTCOMMAND_H
