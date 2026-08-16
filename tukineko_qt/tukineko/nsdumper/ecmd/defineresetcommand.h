#ifndef DEFINERESETCOMMAND_H
#define DEFINERESETCOMMAND_H

#include "ecommand.h"

class DefineresetCommand : public ECommand
{
public:
    DefineresetCommand();
    virtual ~DefineresetCommand();
    bool check(const QString& str);
    void execute();
};

#endif // DEFINERESETCOMMAND_H
