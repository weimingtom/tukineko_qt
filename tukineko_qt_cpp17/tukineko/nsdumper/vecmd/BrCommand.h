#ifndef BRCOMMAND_H
#define BRCOMMAND_H

#include "VECommand.h"

namespace tukineko {

#include "nscripter.h"

class BrCommand : public VECommand
{
public:
    BrCommand();
    virtual ~BrCommand();

    virtual bool check(const QString &str) override;
    virtual void execute() override;

private:
    tukineko::NScripter *ns;
};

}

#endif // BRCOMMAND_H
