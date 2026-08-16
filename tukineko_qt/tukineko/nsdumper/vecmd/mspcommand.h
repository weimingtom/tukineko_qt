#ifndef MSPCOMMAND_H
#define MSPCOMMAND_H

#include <QString>
#include "vecommand.h"

class MspCommand : public VECommand
{
public:
    MspCommand();
    virtual ~MspCommand();

    bool check(const QString& str);
    void execute();
};

#endif // MSPCOMMAND_H

