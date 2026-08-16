#ifndef ERASETEXTWINDOWCOMMAND_H
#define ERASETEXTWINDOWCOMMAND_H

#include "VECommand.h"
#include "nscripter.h"

class ErasetextwindowCommand : public VECommand
{
public:
    ErasetextwindowCommand();
    virtual ~ErasetextwindowCommand();

    virtual bool check(const QString &str) override;
    virtual void execute() override;

private:
    tukineko::NScripter *ns;
};

#endif // ERASETEXTWINDOWCOMMAND_H
