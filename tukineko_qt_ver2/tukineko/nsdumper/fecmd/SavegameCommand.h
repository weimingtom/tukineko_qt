#ifndef SAVEGAMECOMMAND_H
#define SAVEGAMECOMMAND_H

#include "FECommand.h"

#include "nscripter.h"

class SavegameCommand : public FECommand
{
public:
    SavegameCommand();
    bool check(const QString &str) override;
    void execute() override;

private:
    tukineko::NScripter *ns;
};

#endif // SAVEGAMECOMMAND_H
