#ifndef OFSCPYCOMMAND_H
#define OFSCPYCOMMAND_H

#include "VECommand.h"

namespace tukineko {

#include "nscripter.h"

class OfscpyCommand : public VECommand
{
public:
    OfscpyCommand();
    virtual ~OfscpyCommand();

    virtual bool check(const QString &str) override;
    virtual void execute() override;

private:
    tukineko::NScripter *ns;
};

}

#endif // OFSCPYCOMMAND_H
