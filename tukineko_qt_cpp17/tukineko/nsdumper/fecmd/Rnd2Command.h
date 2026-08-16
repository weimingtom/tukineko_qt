#ifndef RND2COMMAND_H
#define RND2COMMAND_H

#include "FECommand.h"

#include "nscripter.h"

class Rnd2Command : public FECommand
{
public:
    Rnd2Command();
    bool check(const QString &str) override;
    void execute() override;

private:
    tukineko::NScripter *ns;
};

#endif // RND2COMMAND_H
