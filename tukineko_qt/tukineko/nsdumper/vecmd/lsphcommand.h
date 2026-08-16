#ifndef LSPHCOMMAND_H
#define LSPHCOMMAND_H

#include <QString>
#include "vecommand.h"

class LsphCommand : public VECommand
{
public:
    LsphCommand();
    virtual ~LsphCommand();

    bool check(const QString& str);
    void execute();
};

#endif // LSPHCOMMAND_H

