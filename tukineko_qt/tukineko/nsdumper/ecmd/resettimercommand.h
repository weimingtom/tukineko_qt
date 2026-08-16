#ifndef RESETTIMERCOMMAND_H
#define RESETTIMERCOMMAND_H

#include "ecommand.h"

class ResettimerCommand : public ECommand
{
public:
    ResettimerCommand();
    virtual ~ResettimerCommand();
    bool check(const QString& str);
    void execute();
};

#endif // RESETTIMERCOMMAND_H
