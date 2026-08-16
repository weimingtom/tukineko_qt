#ifndef JUMPFCOMMAND_H
#define JUMPFCOMMAND_H

#include <QString>
#include "fecommand.h"

class JumpfCommand : public FECommand
{
public:
    JumpfCommand();
    virtual ~JumpfCommand();

    bool check(const QString& str);
    void execute();
};

#endif // JMPFCOMMAND_H
