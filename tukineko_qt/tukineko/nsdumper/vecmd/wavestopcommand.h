#ifndef WAVESTOPCOMMAND_H
#define WAVESTOPCOMMAND_H

#include <QString>
#include "vecommand.h"

class WavestopCommand : public VECommand
{
public:
    WavestopCommand();
    virtual ~WavestopCommand();

    bool check(const QString& str);
    void execute();
};

#endif // WAVESTOPCOMMAND_H
