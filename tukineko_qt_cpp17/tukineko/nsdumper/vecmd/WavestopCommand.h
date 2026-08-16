#ifndef WAVESTOPCOMMAND_H
#define WAVESTOPCOMMAND_H

#include "VECommand.h"

namespace tukineko {

#include "nscripter.h"

class WavestopCommand : public VECommand
{
public:
    WavestopCommand();
    virtual ~WavestopCommand();

    virtual bool check(const QString &str) override;
    virtual void execute() override;

private:
    tukineko::NScripter *ns;
};

}

#endif // WAVESTOPCOMMAND_H
