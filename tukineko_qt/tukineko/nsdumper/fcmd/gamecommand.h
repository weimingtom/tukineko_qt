#ifndef GAMECOMMAND_H
#define GAMECOMMAND_H

#include "fcommand.h"

class GameCommand : public FCommand
{
public:
    GameCommand();
    virtual ~GameCommand();

    bool check(const QString& str);
    void execute();
};

#endif // GAMECOMMAND_H
