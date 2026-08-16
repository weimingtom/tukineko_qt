#ifndef VSPCOMMAND_H
#define VSPCOMMAND_H

#include <QString>
#include "vecommand.h"

class VspCommand : public VECommand
{
public:
    VspCommand();
    virtual ~VspCommand();

    bool check(const QString& str);
    void execute();
};

#endif // VSPCOMMAND_H
