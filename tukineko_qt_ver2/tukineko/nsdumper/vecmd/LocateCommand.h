#ifndef LOCATECOMMAND_H
#define LOCATECOMMAND_H

#include "VECommand.h"
#include "nscripter.h"

class LocateCommand : public VECommand
{
public:
    LocateCommand();
    virtual ~LocateCommand();

    virtual bool check(const QString &str) override;
    virtual void execute() override;

private:
    tukineko::NScripter *ns;
};

#endif // LOCATECOMMAND_H
