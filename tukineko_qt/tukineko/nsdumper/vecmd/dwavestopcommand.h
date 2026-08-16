#ifndef DWAVESTOPCOMMAND_H
#define DWAVESTOPCOMMAND_H

#include <QString>
#include "vecommand.h"

class DwavestopCommand : public VECommand
{
public:
    DwavestopCommand();
    virtual ~DwavestopCommand();

    bool check(const QString& str);
    void execute();
};

#endif // DWAVESTOPCOMMAND_H

