#ifndef DWAVECOMMAND_H
#define DWAVECOMMAND_H

#include <QString>
#include "vecommand.h"

class DwaveCommand : public VECommand
{
public:
    DwaveCommand();
    virtual ~DwaveCommand();

    bool check(const QString& str);
    void execute();
};

#endif // DWAVECOMMAND_H

