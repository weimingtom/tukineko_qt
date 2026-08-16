#ifndef STOPCOMMAND_H
#define STOPCOMMAND_H

#include "VECommand.h"

namespace tukineko {

#include "nscripter.h"

class StopCommand : public VECommand
{
public:
    StopCommand();
    virtual ~StopCommand();

    virtual bool check(const QString &str) override;
    virtual void execute() override;

private:
    tukineko::NScripter *ns;
};

}

#endif // STOPCOMMAND_H
