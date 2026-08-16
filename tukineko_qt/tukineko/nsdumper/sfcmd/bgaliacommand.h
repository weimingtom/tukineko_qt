#ifndef BGALIACOMMAND_H
#define BGALIACOMMAND_H

#include <QString>
#include "sfcommand.h"

class BgaliaCommand : public SFCommand
{
public:
    BgaliaCommand();
    virtual ~BgaliaCommand();

    bool check(const QString& str);
    void execute();
};

#endif // BGALIACOMMAND_H
