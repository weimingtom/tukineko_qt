#ifndef BGCOMMAND_H
#define BGCOMMAND_H

#include <QString>
#include "vecommand.h"

class BgCommand : public VECommand
{
public:
    BgCommand();
    virtual ~BgCommand();

    bool check(const QString& str);
    void execute();
};

#endif // BGCOMMAND_H

