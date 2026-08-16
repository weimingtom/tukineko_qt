#ifndef DECCOMMAND_H
#define DECCOMMAND_H

#include "FECommand.h"

#include "nscripter.h"

class DecCommand : public FECommand
{
public:
    DecCommand();
    bool check(const QString &str) override;
    void execute() override;

private:
    tukineko::NScripter *ns;
};

#endif // DECCOMMAND_H
