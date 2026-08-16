#ifndef WAITCOMMAND_H
#define WAITCOMMAND_H

#include "ecommand.h"

class WaitCommand : public ECommand
{
public:
    WaitCommand();
    virtual ~WaitCommand();
    bool check(const QString& str);
    void execute();
};

#endif // WAITCOMMAND_H
