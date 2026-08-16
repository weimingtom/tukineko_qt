#ifndef PLAYONCECOMMAND_H
#define PLAYONCECOMMAND_H

#include "VECommand.h"

namespace tukineko {

#include "nscripter.h"

class PlayonceCommand : public VECommand
{
public:
    PlayonceCommand();
    virtual ~PlayonceCommand();

    virtual bool check(const QString &str) override;
    virtual void execute() override;

private:
    tukineko::NScripter *ns;
};

}

#endif // PLAYONCECOMMAND_H
