#ifndef TRAPCOMMAND_H
#define TRAPCOMMAND_H

#include "ecommand.h"

class TrapCommand : public ECommand
{
public:
    TrapCommand();
    virtual ~TrapCommand();
    bool check(const QString& str);
    void execute();
};

#endif // TRAPCOMMAND_H
