#ifndef HUMANZCOMMAND_H
#define HUMANZCOMMAND_H

#include <QString>
#include "sfcommand.h"

class HumanzCommand : public SFCommand
{
public:
    HumanzCommand();
    virtual ~HumanzCommand();

    bool check(const QString& str);
    void execute();
};

#endif // HUMANZCOMMAND_H

