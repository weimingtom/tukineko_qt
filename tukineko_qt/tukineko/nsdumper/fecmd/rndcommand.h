#ifndef RNDCOMMAND_H
#define RNDCOMMAND_H

#include <QString>
#include "fecommand.h"

class RndCommand : public FECommand
{
public:
    RndCommand();
    virtual ~RndCommand();

    bool check(const QString& str);
    void execute();
};

#endif // RNDCOMMAND_H
