#ifndef QUAKEYCOMMAND_H
#define QUAKEYCOMMAND_H

#include "VECommand.h"
#include "nscripter.h"

class QuakeyCommand : public VECommand
{
public:
    QuakeyCommand();
    virtual ~QuakeyCommand();

    virtual bool check(const QString &str) override;
    virtual void execute() override;

private:
    tukineko::NScripter *ns;
};

#endif // QUAKEYCOMMAND_H
