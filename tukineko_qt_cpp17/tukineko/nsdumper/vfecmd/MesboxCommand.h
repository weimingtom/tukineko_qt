#ifndef MESBOXCOMMAND_H
#define MESBOXCOMMAND_H

#include "VFECommand.h"

namespace tukineko {

#include "nscripter.h"

class MesboxCommand : public VFECommand
{
public:
    MesboxCommand();
    virtual ~MesboxCommand();

    virtual bool check(const QString &str) override;
    virtual void execute() override;

private:
    tukineko::NScripter *ns;
};

}

#endif // MESBOXCOMMAND_H
