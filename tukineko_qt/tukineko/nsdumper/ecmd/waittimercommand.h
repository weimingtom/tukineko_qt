#ifndef WAITTIMERCOMMAND_H
#define WAITTIMERCOMMAND_H

#include "ecommand.h"

class WaittimerCommand : public ECommand
{
public:
    WaittimerCommand();
    virtual ~WaittimerCommand();
    bool check(const QString& str);
    void execute();
};

#endif // WAITTIMERCOMMAND_H
