#ifndef PRINTCOMMAND_H
#define PRINTCOMMAND_H

#include "VECommand.h"

namespace tukineko {

#include "nscripter.h"

class PrintCommand : public VECommand
{
public:
    PrintCommand();
    virtual ~PrintCommand();

    virtual bool check(const QString &str) override;
    virtual void execute() override;

private:
    tukineko::NScripter *ns;
};

}

#endif // PRINTCOMMAND_H
