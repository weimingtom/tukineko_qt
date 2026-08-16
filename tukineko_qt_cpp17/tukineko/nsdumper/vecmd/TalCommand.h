#ifndef TALCOMMAND_H
#define TALCOMMAND_H

#include "VECommand.h"

namespace tukineko {

#include "nscripter.h"

class TalCommand : public VECommand
{
public:
    TalCommand();
    virtual ~TalCommand();

    virtual bool check(const QString &str) override;
    virtual void execute() override;

private:
    tukineko::NScripter *ns;
};

}

#endif // TALCOMMAND_H
