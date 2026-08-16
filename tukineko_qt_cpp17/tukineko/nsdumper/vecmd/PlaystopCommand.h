#ifndef PLAYSTOPCOMMAND_H
#define PLAYSTOPCOMMAND_H

#include "VECommand.h"

namespace tukineko {

#include "nscripter.h"

class PlaystopCommand : public VECommand
{
public:
    PlaystopCommand();
    virtual ~PlaystopCommand();

    virtual bool check(const QString &str) override;
    virtual void execute() override;

private:
    tukineko::NScripter *ns;
};

}

#endif // PLAYSTOPCOMMAND_H
