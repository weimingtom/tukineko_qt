#ifndef ROFFCOMMAND_H
#define ROFFCOMMAND_H

#include <QString>
#include "sfcommand.h"

class RoffCommand : public SFCommand
{
public:
    RoffCommand();
    virtual ~RoffCommand();

    bool check(const QString& str);
    void execute();
};

#endif // ROFFCOMMAND_H
