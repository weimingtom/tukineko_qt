#ifndef GAMECOMMAND_H
#define GAMECOMMAND_H

#include "fcommand.h"

class GameCommand : public FCommand
{
public:
    bool check(const QString &str) override;
    void execute() override;
};

#endif // GAMECOMMAND_H
