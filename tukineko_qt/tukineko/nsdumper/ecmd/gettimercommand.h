#ifndef GETTIMERCOMMAND_H
#define GETTIMERCOMMAND_H

#include "ecommand.h"

class GettimerCommand : public ECommand
{
public:
    GettimerCommand();
    virtual ~GettimerCommand();
    bool check(const QString& str);
    void execute();
};

#endif // GETTIMERCOMMAND_H
