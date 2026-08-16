#ifndef JUMPBCOMMAND_H
#define JUMPBCOMMAND_H

#include <QString>
#include "fecommand.h"

class JumpbCommand : public FECommand
{
public:
    JumpbCommand();
    virtual ~JumpbCommand();

    bool check(const QString& str);
    void execute();
};

#endif // JUMPBCOMMAND_H
