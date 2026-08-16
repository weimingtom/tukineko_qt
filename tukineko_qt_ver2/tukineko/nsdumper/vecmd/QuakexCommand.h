#ifndef QUAKEXCOMMAND_H
#define QUAKEXCOMMAND_H

#include "VECommand.h"
#include "nscripter.h"

class QuakexCommand : public VECommand
{
public:
    QuakexCommand();
    virtual ~QuakexCommand();

    virtual bool check(const QString &str) override;
    virtual void execute() override;

private:
    tukineko::NScripter *ns;
};

#endif // QUAKEXCOMMAND_H
