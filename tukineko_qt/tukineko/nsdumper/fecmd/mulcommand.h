#ifndef MULCOMMAND_H
#define MULCOMMAND_H

#include <QString>
#include "fecommand.h"

class MulCommand : public FECommand
{
public:
    MulCommand();
    virtual ~MulCommand();

    bool check(const QString& str);
    void execute();
};

#endif // MULCOMMAND_H
