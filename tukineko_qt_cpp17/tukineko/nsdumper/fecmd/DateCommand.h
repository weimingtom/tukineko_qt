#ifndef DATECOMMAND_H
#define DATECOMMAND_H

#include "FECommand.h"

#include "nscripter.h"

class DateCommand : public FECommand
{
public:
    DateCommand();
    bool check(const QString &str) override;
    void execute() override;

private:
    tukineko::NScripter *ns;
};

#endif // DATECOMMAND_H
