#ifndef RLOOKBACKCOMMAND_H
#define RLOOKBACKCOMMAND_H

#include <QString>
#include "sfcommand.h"

class RlookbackCommand : public SFCommand
{
public:
    RlookbackCommand();
    virtual ~RlookbackCommand();

    bool check(const QString& str);
    void execute();
};

#endif // RLOOKBACKCOMMAND_H
