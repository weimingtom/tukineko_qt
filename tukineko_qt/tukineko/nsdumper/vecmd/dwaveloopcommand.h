#ifndef DWAVELOOPCOMMAND_H
#define DWAVELOOPCOMMAND_H

#include <QString>
#include "vecommand.h"

class DwaveloopCommand : public VECommand
{
public:
    DwaveloopCommand();
    virtual ~DwaveloopCommand();

    bool check(const QString& str);
    void execute();
};

#endif // DWAVELOOPCOMMAND_H

