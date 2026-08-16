#ifndef SAVEONCOMMAND_H
#define SAVEONCOMMAND_H

#include "FECommand.h"

class SaveonCommand : public FECommand
{
public:
    SaveonCommand();
    bool check(const QString &str) override;
    void execute() override;
};

#endif // SAVEONCOMMAND_H
