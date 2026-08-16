#ifndef SAVEOFFCOMMAND_H
#define SAVEOFFCOMMAND_H

#include "FECommand.h"

class SaveoffCommand : public FECommand
{
public:
    SaveoffCommand();
    bool check(const QString &str) override;
    void execute() override;
};

#endif // SAVEOFFCOMMAND_H
